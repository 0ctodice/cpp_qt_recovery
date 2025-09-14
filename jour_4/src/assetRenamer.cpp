#include "assetRenamer.h"
#include "fileRenamer.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
AssetRenamer::AssetRenamer(QWidget *parent) : QWidget(parent)
{
    setupMenuBar();
    _progressBar = new QProgressBar(this);
    _folderInput = new QLineEdit(this);
    _prefixInput = new QLineEdit(this);
    _chooseFolderButton = new QPushButton("choose folder", this);
    _renameButton = new QPushButton("rename", this);
    _renameButton->setDisabled(true);
    _log = new QTextEdit(this);
    _log->setReadOnly(true);
    _log->setText("Welcome to the asset renamer!");
    _label = new QLabel("Files found : 0", this);
    QVBoxLayout *generalLayout = new QVBoxLayout(this);
    QGridLayout *inputsLayout = new QGridLayout();
    inputsLayout->addWidget(_folderInput, 0, 0);
    inputsLayout->addWidget(_chooseFolderButton, 0, 1);
    inputsLayout->addWidget(_prefixInput, 1, 0);
    inputsLayout->addWidget(_renameButton, 1, 1);
    generalLayout->addWidget(_menu);
    generalLayout->addLayout(inputsLayout);
    generalLayout->addWidget(_label);
    generalLayout->addWidget(_log);
    generalLayout->addWidget(_progressBar);
    setLayout(generalLayout);
    connect(_chooseFolderButton, &QPushButton::clicked, this, &AssetRenamer::chooseFolder);
    connect(_folderInput, &QLineEdit::textChanged, this, &AssetRenamer::activateRenameButton);
    connect(_prefixInput, &QLineEdit::textChanged, this, &AssetRenamer::activateRenameButton);
    connect(_renameButton, &QPushButton::clicked, this, &AssetRenamer::renameFiles);
}
void AssetRenamer::setupMenuBar()
{
    _menu = new QMenuBar(this);
    auto *fileMenu = _menu->addMenu("File");
    auto *quitAction = fileMenu->addAction("Quit");
    auto *helpMenu = _menu->addMenu("Help");
    auto *aboutAction = helpMenu->addAction("About");
    connect(quitAction, &QAction::triggered, this, &QWidget::close);
    connect(aboutAction, &QAction::triggered, this, &AssetRenamer::showAbout);
}
void AssetRenamer::showAbout() const { QMessageBox::information(nullptr, "About", "this tool allows you to rename multiple files with the same prefix."); }
void AssetRenamer::logMessage(const QString &message) { _log->append(message); }
void AssetRenamer::logError(const QString &message)
{
    _log->setTextColor(Qt::red);
    _log->append(message);
    _log->setTextColor(Qt::black);
}
bool AssetRenamer::isReady() const { return !_folderInput->text().isEmpty() && !_prefixInput->text().isEmpty(); }
void AssetRenamer::activateRenameButton() { _renameButton->setEnabled(isReady()); }
void AssetRenamer::chooseFolder()
{
    auto path = QFileDialog::getExistingDirectory(this, "choose folder to rename all the files");
    if (path.isEmpty())
        return;
    _folderInput->setText(path);
}
void AssetRenamer::renameFiles()
{
    logMessage("renaming every files inside : " + _folderInput->text());
    logMessage("using the prefix : " + _prefixInput->text());
    FileRenamer fileRenamer(_folderInput->text(), _prefixInput->text());
    connect(&fileRenamer, &FileRenamer::fileRenameError, this, &AssetRenamer::logError);
    connect(&fileRenamer, &FileRenamer::numberOfFilesCatched, _progressBar, &QProgressBar::setMaximum);
    connect(&fileRenamer, &FileRenamer::numberOfFilesCatched, this, &AssetRenamer::updateLabel);
    connect(&fileRenamer, &FileRenamer::filesCounter, _progressBar, &QProgressBar::setValue);
    QStringList renamedFiles;
    if (fileRenamer.renameAll(renamedFiles))
    {
        logMessage("Done renaming! here's all the new name :");
        for (auto file : renamedFiles)
        {
            logMessage(file);
        }
    }
}
void AssetRenamer::updateLabel(int number)
{
    std::stringstream label;
    label << "Files found : " << number;
    _label->setText(QString::fromStdString(label.str()));
}