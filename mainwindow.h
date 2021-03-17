#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "changedwindows.h"
#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_pushButton_clicked();
    void changeWindowTitle();

private:
    Ui::MainWindow *ui;
    HWND hwnd;
    ChangedWindows changedWindows;
    QTimer qTimer;
    QThread thread;
};
#endif // MAINWINDOW_H
