#include "fileRenamer.h"
#include <QDir>
#include <QFile>

FileRenamer::FileRenamer(const QString &folder, const QString &prefix) : _folder{folder}, _prefix{prefix} {}
QStringList FileRenamer::listFiles() const { return QDir(_folder).entryList(QDir::Files, QDir::Name); }
bool FileRenamer::renameAll(QStringList &renamedFiles)
{
    if (_folder.isEmpty() || _prefix.isEmpty())
    {
        return false;
    }

    auto files = listFiles();
    emit numberOfFilesCatched(files.size());

    int index = 0;

    for (auto fileName : files)
    {
        QFile file(_folder + "/" + fileName);
        QString newName = _folder + "/" + _prefix + "_" + fileName;
        if (!file.rename(newName))
        {
            emit fileRenameError("Error renaming " + fileName + ": " + file.errorString());
        }
        else
        {
            renamedFiles.append(file.fileName());
        }

        emit filesCounter(++index);
    }

    return true;
}