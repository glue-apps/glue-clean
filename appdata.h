#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QFileInfo>
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
        QFileInfo info1("/Users/guanxu/Documents/GlueFX/glue-apps/glue-clean");
        qDebug() << info1.size();

        QFileInfo info2("/Users/guanxu/Documents/GlueFX/glue-apps/glue-clean/docs");
        qDebug() << info2.size();

        QFileInfo info3("/Users/guanxu/Downloads/20200525-集成产品研发管理研究与思考.pptx");
        qDebug() << info3.size();

        return m_author;
    }

    Q_INVOKABLE void scan(const QString &path) {
        qDebug() << "c++ scan" << path;
        return;
    }

signals:
    void authorChanged();
private:
    QString m_author;
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
