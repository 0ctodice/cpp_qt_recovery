#pragma once
#include <QObject>
#include <QString>
#include <QStringList>

class FileRenamer : public QObject
{
    Q_OBJECT
private:
    QString _folder;
    QString _prefix;

public:
    FileRenamer(const QString &folder, const QString &prefix);
    QStringList listFiles() const;
    bool renameAll(QStringList &renamedFiles);
signals:
    void fileRenameError(const QString &error);
    void numberOfFilesCatched(int total);
    void filesCounter(int currentNumber);
};