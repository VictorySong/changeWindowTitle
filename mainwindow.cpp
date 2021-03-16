#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <Windows.h>

#pragma comment(lib, "user32.lib")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    qDebug()<<"mouseRelease";
    POINT point;
    BOOL ret;
    ret = GetCursorPos(&point);
    qDebug()<<ret;
    if(ret) {
        qDebug()<<"x:"<<point.x<<"y:"<<point.y;
        hwnd = WindowFromPoint(point);
        if (hwnd == NULL || hwnd == INVALID_HANDLE_VALUE){

        }else {
            ui->label->setText(QString("%1").arg((int)hwnd,8,16,QLatin1Char('0')));
            TCHAR windowText[MAX_PATH];
            GetWindowText(hwnd,windowText,MAX_PATH);
            ui->lineEdit->setText(QString::fromWCharArray(windowText));
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    TCHAR windowText[MAX_PATH];
    int count = ui->lineEdit->text().toWCharArray(windowText);
    windowText[count] = 0;
    SetWindowText(hwnd,windowText);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Return) {
        TCHAR windowText[MAX_PATH];
        int count = ui->lineEdit->text().toWCharArray(windowText);
        windowText[count] = 0;
        SetWindowText(hwnd,windowText);
    }
}
