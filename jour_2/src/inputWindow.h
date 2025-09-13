#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class InputWindow : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *_input;
    QLabel *_label;

public:
    InputWindow(QWidget *parent = nullptr);
public slots:
    void updateLabel();
};