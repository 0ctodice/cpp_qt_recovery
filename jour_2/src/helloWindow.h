#pragma once
#include <QWidget>
#include <QPushButton>

class HelloWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *_btn;

public:
    HelloWindow(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();
};
