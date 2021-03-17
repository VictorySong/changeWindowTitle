#include "changedwindows.h"
#include <QMapIterator>
#include <QDebug>

ChangedWindows::ChangedWindows(QObject *parent) : QObject(parent)
{

}

void ChangedWindows::setHwndTitle(HWND hwnd, QString title) {
    mutex.lock();
    this->hwndTitles.insert(hwnd,title);
    mutex.unlock();
}

void ChangedWindows::updateHwndTitle() {
    QMapIterator<HWND,QString> i(this->hwndTitles);
    TCHAR windowText[MAX_PATH];
    mutex.lock();
    qDebug()<<"begin traversal";
    while (i.hasNext()) {
        i.next();
        qDebug()<<i.value();
        int count = i.value().toWCharArray(windowText);
        windowText[count] = 0;
        bool a = SetWindowText(i.key(),windowText);
        if(!a) {

            this->hwndTitles.remove(i.key());

        }
    }
    mutex.unlock();
}
