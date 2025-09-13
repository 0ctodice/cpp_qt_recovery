#include <iostream>
#include <QDir>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage :\n"
                  << argv[0]
                  << " <directory>"
                  << std::endl;
        return 1;
    }

    QDir dir(argv[1]);
    if (!dir.exists())
    {
        std::cerr << "Cannot find the directory" << std::endl;
        return 1;
    }

    auto qFiles = dir.entryInfoList(QDir::Files, QDir::Size);

    for (const auto &file : qFiles)
    {
        std::cout << file.fileName().toStdString() << " | " << file.size() << " | " << file.lastModified().toString("dd/MM/yyy hh:mm").toStdString() << std::endl;
    }

    return 0;
}
