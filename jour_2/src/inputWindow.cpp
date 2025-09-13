#include "inputWindow.h"
#include <QVBoxLayout>

InputWindow::InputWindow(QWidget *parent) : QWidget(parent)
{
    _label = new QLabel("Blank", this);
    _input = new QLineEdit(this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(_label);
    layout->addWidget(_input);
    setLayout(layout);
    connect(_input, &QLineEdit::textChanged, this, &InputWindow::updateLabel);
}

void InputWindow::updateLabel()
{
    _label->setText(_input->text().toUpper());
}