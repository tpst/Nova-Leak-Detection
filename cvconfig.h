#ifndef CVCONFIG_H
#define CVCONFIG_H

#include <QDialog>
#include <QDebug>
#include <QThread>

#include "frameprocessor.h"
#include "framegetter.h"
#include "variables.h"

// sliders for search ROI
#include "test.h"

namespace Ui {
class cvConfig;
}

class cvConfig : public QDialog
{
    Q_OBJECT

public:
    explicit cvConfig(QWidget *parent = 0);
    ~cvConfig();

    void init(frameGetter &get);
    void variableSetup();
    void disconnect();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_lineEdit_textEdited(const QString &arg1);

    void updateDisplay(QImage frame);

    void on_cvConfig_finished(int result);

    void on_horizontalSlider_7_valueChanged(int value);

    void on_lineEdit_7_textEdited(const QString &arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_horizontalSlider_5_valueChanged(int value);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_horizontalSlider_8_valueChanged(int value);

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_horizontalSlider_9_valueChanged(int value);

    void on_lineEdit_9_textEdited(const QString &arg1);

signals:
    void valueChanged(variables v);
    void finished();
    void doStuff();
private:
    Ui::cvConfig *ui;

    int thresh;
    bool on;
    bool connected; //logic for framegetter

    cv::VideoCapture vc;

    frameProcessor* proc;
    frameGetter* getter;
    QThread* thread;

    variables values;
};

#endif // CVCONFIG_H
