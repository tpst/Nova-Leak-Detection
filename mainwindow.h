#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "capturehandler.h"
#include "configdialog.h"
#include "cvconfig.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateDisplay(QImage frame);

    void updateDisplay2(QImage frame);

    //void recordDisplay(cv::Mat frame);

    void on_exitButton_clicked();

    void on_AddStream_clicked();

    void on_stopButton_clicked();

    void on_recordStream_clicked();

    void on_toolButton_clicked();

    void on_processStream_clicked();

    void refreshDisplays();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *ui;
    captureHandler* handler;
    configDialog cfg;
    cvConfig cvCfg;
};

#endif // MAINWINDOW_H
