#ifndef CHANGEDWINDOWS_H
#define CHANGEDWINDOWS_H

#include <QObject>
#include <QMap>
#include <windows.h>
#include <QMutex>

class ChangedWindows : public QObject
{
    Q_OBJECT
public:
    explicit ChangedWindows(QObject *parent = nullptr);
    void setHwndTitle(HWND, QString);
public slots:
    void updateHwndTitle();

private:
    QMap<HWND,QString> hwndTitles;
    QMutex mutex;

signals:

};

#endif // CHANGEDWINDOWS_H
