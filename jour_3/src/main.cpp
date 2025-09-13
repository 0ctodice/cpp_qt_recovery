#include "assetRenamer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AssetRenamer window;
    window.show();
    return app.exec();
}
