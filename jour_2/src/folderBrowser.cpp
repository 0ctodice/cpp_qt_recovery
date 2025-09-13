#include "folderBrowser.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>
#include <QDir>

namespace fs = std::filesystem;

FolderBrowser::FolderBrowser(QWidget *parent) : QWidget(parent)
{
    _btn = new QPushButton("choose folder", this);
    _list = new QListWidget(this);
    _label = new QLabel("path: ", this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(_label);
    layout->addWidget(_btn);
    layout->addWidget(_list);
    setLayout(layout);
    connect(_btn, &QPushButton::clicked, this, &FolderBrowser::chooseFolder);
}

void FolderBrowser::chooseFolder()
{
    const auto path = QFileDialog::getExistingDirectory(this, "choose folder");
    if (path.isEmpty())
        return;

    _list->clear();

    _label->setText("path: " + path);

    QDir dir(path);

    for (const auto &entry : dir.entryList(QDir::Files, QDir::Name))
    {
        _list->addItem(entry);
    }
}