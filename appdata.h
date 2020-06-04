#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QDebug>

class AppData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
public:
    explicit AppData(QObject *parent = nullptr);
    void setAuthor(const QString &a) {
        if (a != m_author) {
            m_author = a;
            emit authorChanged();
        }
    }
    QString author() const {
        return m_author;
    }

    Q_INVOKABLE void scan(const QString &path);

signals:
    void authorChanged();
    void dirAdded(const QString &dirInfo);
    void dirScanned();

private:
    QString m_author;
    void scanDir(const QString &path);
    qint64 getDirSize(const QString &path);
};

/*

{
    index: 0,
    data: [
        {
            name: '/Users/name/Documents',
            size: 1000,
            children: [
                {
                    name: '/Users/name/Documents/demo1.txt',
                    size: 400,
                },
                {
                    name: '/Users/name/Documents/demo2.txt',
                    size: 600,
                }
            ]
        }
    ]
}
*/

#endif // APPDATA_H
