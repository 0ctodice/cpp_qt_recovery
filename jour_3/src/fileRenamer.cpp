#include "fileRenamer.h"
#include <QDir>
#include <QFile>

FileRenamer::FileRenamer(const QString &folder, const QString &prefix) : _folder{folder}, _prefix{prefix}
{
}

QStringList FileRenamer::listFiles() const { return QDir(_folder).entryList(); }

bool FileRenamer::renameAll(QStringList &renamedFiles, QStringList &errors)
{
    for (auto fileName : listFiles())
    {
        QFile file(_folder + "/" + fileName);
        QString newName = _prefix + "_" + fileName;
        bool status = file.rename(newName);
        renamedFiles.append(file.fileName());
        errors.append(status ? fileName + " | successfully renamed" : fileName + " | error : couldn't rename it");
    }
}