#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton btn("Hello Qt from WSL!");
    btn.resize(280, 60);
    btn.show();
    return app.exec();
}
