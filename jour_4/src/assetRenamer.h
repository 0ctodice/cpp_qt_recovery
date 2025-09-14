#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMenuBar>
#include <QProgressBar>

class AssetRenamer : public QWidget
{
    Q_OBJECT
private:
    QMenuBar *_menu;
    QLineEdit *_folderInput;
    QLineEdit *_prefixInput;
    QPushButton *_chooseFolderButton;
    QPushButton *_renameButton;
    QTextEdit *_log;
    QProgressBar *_progressBar;

    void setupMenuBar();

private slots:
    void showAbout() const;

public:
    AssetRenamer(QWidget *parent = nullptr);
    bool isReady() const;
public slots:
    void chooseFolder();
    void renameFiles();
    void logMessage(const QString &message);
    void activateRenameButton();
};