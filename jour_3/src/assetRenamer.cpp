#include "assetRenamer.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFileDialog>

AssetRenamer::AssetRenamer(QWidget *parent) : QWidget(parent)
{
    _folderInput = new QLineEdit(this);
    _prefixInput = new QLineEdit(this);
    _chooseFolderButton = new QPushButton("choose folder", this);
    _renameButton = new QPushButton("rename", this);
    _log = new QTextEdit(this);
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
    connect(_renameButton, &QPushButton::clicked, this, &AssetRenamer::renameFiles);
}

void AssetRenamer::chooseFolder()
{
    auto path = QFileDialog::getExistingDirectory(this, "choose folder to rename all the files");
    if (path.isEmpty())
        return;
    _folderInput->setText(path);
}

void AssetRenamer::renameFiles()
{
    if (_folderInput->text() == "" || _prefixInput->text() == "")
    {
        return;
    }
}
