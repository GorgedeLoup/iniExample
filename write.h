#ifndef WRITE_H
#define WRITE_H

#include <QObject>

class Write : public QObject
{
    Q_OBJECT
public:
    explicit Write(QObject *parent = 0);
    ~Write();

signals:

public slots:
};

#endif // WRITE_H
