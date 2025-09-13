#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class AssetRenamer : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *_folderInput;
    QLineEdit *_prefixInput;
    QPushButton *_chooseFolderButton;
    QPushButton *_renameButton;
    QTextEdit *_log;

public:
    AssetRenamer(QWidget *parent = nullptr);
    bool isReady() const;
public slots:
    void chooseFolder();
    void renameFiles();
    void logMessage(const QString &message);
    void activateRenameButton();
};