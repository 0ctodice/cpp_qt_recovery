#pragma once
#include <QString>
#include <QStringList>

class FileRenamer
{
private:
    QString _folder;
    QString _prefix;

public:
    FileRenamer(const QString &folder, const QString &prefix);
    QStringList listFiles() const;
    bool renameAll(QStringList &renamedFiles, QStringList &errors);
};