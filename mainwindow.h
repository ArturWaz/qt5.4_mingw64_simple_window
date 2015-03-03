/*
 * mainwindow.h
 *
 *  Created on: 3/3/2015
 *      Author: Artur
 */


#ifndef mainwindow_H_
#define mainwindow_H_


#include <QtWidgets/QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};




#endif //__mainwindow_H_