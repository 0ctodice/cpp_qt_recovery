#include "helloWindow.h"
#include <QVBoxLayout>
#include <QDebug>

HelloWindow::HelloWindow(QWidget *parent) : QWidget(parent)
{
    _btn = new QPushButton("Click me!", this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(_btn);
    setLayout(layout);
    connect(_btn, &QPushButton::clicked, this, &HelloWindow::onButtonClicked);
}

void HelloWindow::onButtonClicked()
{
    qDebug() << "Button Clicked!";
}