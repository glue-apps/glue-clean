#include "appdata.h"
#include <QFileInfo>
#include <QDir>

AppData::AppData(QObject *parent) : QObject(parent)
{

}

void AppData::scan(const QString &path) {
    QFileInfo info(path);
//    qDebug() << "isDir:" << info.isDir();
//    qDebug() << "isFile:" << info.isFile();
//    qDebug() << "path:" << info.path();
//    qDebug() << "fileName:" << info.fileName();
//    qDebug() << "filePath:" << info.filePath();

    QString dirPath = info.path();
    scanDir(dirPath);

    emit dirScanned();
    return;
}

void AppData::scanDir(const QString &path) {
    qint64 dirSize = 0;
    QString dirSizeString = "";

    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);

    foreach (QFileInfo info, dir.entryInfoList()) {
        if (info.isDir()) {
            QDir subDir(info.filePath());
            QString dirName = subDir.dirName();
            if (dirName == "node_modules") {
                dirSize = getDirSize(info.filePath());
                if (dirSize > 1024 * 1024 * 1024) {
                    dirSizeString = QString::number(dirSize / (1024.0 * 1024 * 1024), 'f', 2) + " GB";
                } else if (dirSize > 1024 * 1024) {
                    dirSizeString = QString::number(dirSize / (1024.0 * 1024), 'f', 2) + " MB";
                } else if (dirSize > 1024) {
                    dirSizeString = QString::number(dirSize / 1024.0, 'f', 2) + " KB";
                } else {
                    dirSizeString = QString::number(dirSize, 'f', 2) + " bytes";
                }
//                qDebug() << info.filePath() << dirSizeString;
                QString dirInfo = info.filePath() + "||" + dirSizeString;
                emit dirAdded(dirInfo);
                continue;
            }
            scanDir(info.filePath());
        }
    }
}

qint64 AppData::getDirSize(const QString &path) {
    qint64 dirSize = 0;

//    QFileInfo dirInfo(path);
//    dirSize += dirInfo.size();

    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);

    foreach (QFileInfo info, dir.entryInfoList()) {
//        dirSize += info.size();
        if (info.isDir()) {
            dirSize += getDirSize(info.filePath());
        } else {
            dirSize += info.size();
        }
    }
    return dirSize;
}
