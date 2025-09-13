#pragma once
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

class FolderBrowser : public QWidget
{
    Q_OBJECT
private:
    QPushButton *_btn;
    QListWidget *_list;
    QLabel *_label;

public:
    FolderBrowser(QWidget *parent = nullptr);
public slots:
    void chooseFolder();
};