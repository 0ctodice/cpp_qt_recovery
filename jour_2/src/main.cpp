#include "folderBrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FolderBrowser window;
    window.show();
    return app.exec();
}
