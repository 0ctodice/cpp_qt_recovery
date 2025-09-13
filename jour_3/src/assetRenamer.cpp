#include "assetRenamer.h"
#include "fileRenamer.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFileDialog>

AssetRenamer::AssetRenamer(QWidget *parent) : QWidget(parent)
{
    _folderInput = new QLineEdit(this);
    _prefixInput = new QLineEdit(this);
    _chooseFolderButton = new QPushButton("choose folder", this);
    _renameButton = new QPushButton("rename", this);
    _renameButton->setDisabled(true);
    _log = new QTextEdit(this);
    _log->setReadOnly(true);
    _log->setText("Welcome to the asset renamer!");
    QVBoxLayout *generalLayout = new QVBoxLayout(this);
    QGridLayout *inputsLayout = new QGridLayout();
    inputsLayout->addWidget(_folderInput, 0, 0);
    inputsLayout->addWidget(_chooseFolderButton, 0, 1);
    inputsLayout->addWidget(_prefixInput, 1, 0);
    inputsLayout->addWidget(_renameButton, 1, 1);
    generalLayout->addLayout(inputsLayout);
    generalLayout->addWidget(_log);
    setLayout(generalLayout);
    connect(_chooseFolderButton, &QPushButton::clicked, this, &AssetRenamer::chooseFolder);
    connect(_folderInput, &QLineEdit::textChanged, this, &AssetRenamer::activateRenameButton);
    connect(_prefixInput, &QLineEdit::textChanged, this, &AssetRenamer::activateRenameButton);
    connect(_renameButton, &QPushButton::clicked, this, &AssetRenamer::renameFiles);
}

bool AssetRenamer::isReady() const { return !_folderInput->text().isEmpty() && !_prefixInput->text().isEmpty(); }

void AssetRenamer::chooseFolder()
{
    auto path = QFileDialog::getExistingDirectory(this, "choose folder to rename all the files");
    if (path.isEmpty())
        return;
    _folderInput->setText(path);
}

void AssetRenamer::activateRenameButton()
{
    _renameButton->setDisabled(isReady());
}

void AssetRenamer::renameFiles()
{
    logMessage("renaming every files inside : " + _folderInput->text());
    logMessage("using the prefix : " + _prefixInput->text());
    FileRenamer fileRenamer(_folderInput->text(), _prefixInput->text());
    connect(&fileRenamer, &FileRenamer::fileRenameError, this, &AssetRenamer::logMessage);
    QStringList renamedFiles;
    fileRenamer.renameAll(renamedFiles);
    logMessage("Done renaming! here's all the new name :");
    for (auto file : renamedFiles)
    {
        logMessage(file);
    }
}

void AssetRenamer::logMessage(const QString &message) { _log->append(message); }
