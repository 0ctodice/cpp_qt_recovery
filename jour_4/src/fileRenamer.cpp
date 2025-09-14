#include "fileRenamer.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
FileRenamer::FileRenamer(const QString &folder, const QString &prefix) : _folder{folder}, _prefix{prefix} {}
QStringList FileRenamer::listFiles() const { return QDir(_folder).entryList(QDir::Files, QDir::Name); }
bool FileRenamer::renameAll(QStringList &renamedFiles)
{
    if (!QDir(_folder).exists())
    {
        emit fileRenameError("Critical Error : " + _folder + " doesn't exist");
        return false;
    }

    auto files = listFiles();
    emit numberOfFilesCatched(files.size());

    int index = 0;

    for (auto fileName : files)
    {
        QString newName = _folder + "/" + _prefix + "_" + fileName;

        QFileInfo fileInfo(_folder + "/" + fileName);
        QFileInfo futureFileInfo(_folder + "/" + newName);

        if (!fileInfo.isWritable())
        {
            emit fileRenameError("Error renaming " + fileName + " : it is protected.");
        }
        else if (futureFileInfo.exists())
        {
            emit fileRenameError("Error renaming " + fileName + " : there is already file named " + newName);
        }
        else
        {

            QFile file(_folder + "/" + fileName);

            if (!file.rename(newName))
            {
                emit fileRenameError("Error renaming " + fileName + ": " + file.errorString());
            }
            else
            {
                renamedFiles.append(file.fileName());
            }
        }

        emit filesCounter(++index);
    }

    return true;
}