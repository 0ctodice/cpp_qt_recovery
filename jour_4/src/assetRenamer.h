#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMenuBar>
#include <QProgressBar>
#include <QLabel>

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
    QLabel *_label;
    void setupMenuBar();

public:
    AssetRenamer(QWidget *parent = nullptr);
    bool isReady() const;
public slots:
    void chooseFolder();
    void renameFiles();
    void logMessage(const QString &message);
    void logError(const QString &message);
    void activateRenameButton();
    void showAbout() const;
    void updateLabel(int number);
};