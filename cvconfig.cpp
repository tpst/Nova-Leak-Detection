#include "cvconfig.h"
#include "ui_cvconfig.h"


cvConfig::cvConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cvConfig),
    on(false),
    connected(false),
    proc(new frameProcessor(on))
{
    ui->setupUi(this);

    variableSetup();
    proc->copyVariables(values);

    thread = new QThread;
    //connect(this, SIGNAL(threshValueChanged(int)), proc, SLOT(updateThresh(int)));
    qRegisterMetaType< variables >("variables");
    qRegisterMetaType< cv::Mat >("cv::Mat");
    connect(proc, SIGNAL(frameReady(QImage)), this, SLOT(updateDisplay(QImage)));
    connect(this, SIGNAL(finished()), thread, SLOT(quit()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(this, SIGNAL(valueChanged(variables)), proc, SLOT(copyVariables(variables)));

    // TESTING  TESTING
    test* t = new test();
    connect(t, SIGNAL(procFrame(cv::Mat)), proc, SLOT(testProcess(cv::Mat)));
    connect(thread, SIGNAL(started()), t, SLOT(process()));
    // ----------------------------------------------------------------
    proc->moveToThread(thread);
    thread->start();

}

cvConfig::~cvConfig()
{
    delete ui;
    emit finished();
}

void cvConfig::variableSetup()
{
    // -- Threshold
    values.var.thresh = ui->lineEdit->text().toInt();
    ui->lineEdit->setValidator(new QIntValidator(0, 255, this));
    ui->horizontalSlider->setValue(values.var.thresh);
    // size
    values.var.sSize = ui->lineEdit_7->text().toInt();
    ui->lineEdit_7->setValidator(new QIntValidator(1, 15, this));
    ui->horizontalSlider_7->setValue(values.var.sSize);

    // -- Sharpening
    // -- Alpha
    values.var.alpha = ui->lineEdit_2->text().toInt();
    ui->lineEdit_2->setValidator(new QIntValidator(0, 3000, this));
    ui->horizontalSlider_2->setValue(values.var.alpha);
    //-- Beta
    values.var.beta = ui->lineEdit_3->text().toInt();
    ui->lineEdit_3->setValidator(new QIntValidator(0, 10000, this));
    ui->horizontalSlider_3->setValue(values.var.beta);
    // -- Gamma
    values.var.gamma = ui->lineEdit_4->text().toInt();
    ui->lineEdit_4->setValidator(new QIntValidator(0, 100000, this));
    ui->horizontalSlider_4->setValue(values.var.gamma);

    // -- Contrast
    // -- Alpha
    values.var.scale = ui->lineEdit_5->text().toInt();
    ui->lineEdit_5->setValidator(new QIntValidator(0, 10000, this));
    ui->horizontalSlider_5->setValue(values.var.scale);
    // -- Beta
    values.var.betaC = ui->lineEdit_6->text().toInt();
    ui->lineEdit_6->setValidator(new QIntValidator(0, 100000, this));
    ui->horizontalSlider_6->setValue(values.var.betaC);

    // -- Morphological Opening
    // -- size X
    values.var.ssSizeX = ui->lineEdit_8->text().toInt();
    ui->lineEdit_8->setValidator(new QIntValidator(1, 15, this));
    ui->horizontalSlider_8->setValue(values.var.ssSizeX);
    // -- Size Y
    values.var.ssSizeY = ui->lineEdit_9->text().toInt();
    ui->lineEdit_9->setValidator(new QIntValidator(1, 15, this));
    ui->horizontalSlider_9->setValue(values.var.ssSizeY);

}

void cvConfig::init(frameGetter &get)
{
    if(!on) {
        if(!connected) {
            getter = &get;
            connect(getter, SIGNAL(procFrame(cv::Mat)), proc, SLOT(process(cv::Mat)));
            connected = true;
        }
        on = true;
    }
}

void cvConfig::disconnect()
{
    connected = false;
}

// Threshold
void cvConfig::on_horizontalSlider_valueChanged(int value)
{
    values.var.thresh = value;
    ui->lineEdit->setText(QString::number(value));
    emit valueChanged(values);
}
void cvConfig::on_lineEdit_textEdited(const QString &arg1)
{
    values.var.thresh = arg1.toInt();
    ui->horizontalSlider->setValue(values.var.thresh);
    emit valueChanged(values);
}

// Size

void cvConfig::updateDisplay(QImage frame)
{
    if(!frame.isNull())
    {
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(frame).scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    } else {
        qDebug() << "NULL";
    }
}

void cvConfig::on_cvConfig_finished(int result)
{
    if(on)
        on = false;
}

void cvConfig::on_horizontalSlider_7_valueChanged(int value)
{
    values.var.sSize = value;
    ui->lineEdit_7->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_7_textEdited(const QString &arg1)
{
    values.var.sSize = arg1.toInt();
    ui->horizontalSlider_7->setValue(values.var.sSize);
    emit valueChanged(values);
}
// Contrast
//Alpha
void cvConfig::on_horizontalSlider_2_valueChanged(int value)
{
    values.var.alpha = value;
    ui->lineEdit_2->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_2_textEdited(const QString &arg1)
{
    values.var.alpha = arg1.toInt();
    ui->horizontalSlider_2->setValue(values.var.alpha);
    emit valueChanged(values);
}
//Beta


void cvConfig::on_horizontalSlider_3_valueChanged(int value)
{
    values.var.beta = value;
    ui->lineEdit_3->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_3_textEdited(const QString &arg1)
{
    values.var.beta = arg1.toInt();
    ui->horizontalSlider_3->setValue(values.var.beta);
    emit valueChanged(values);
}
// gamma


void cvConfig::on_horizontalSlider_4_valueChanged(int value)
{
    values.var.gamma = value;
    ui->lineEdit_4->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_4_textEdited(const QString &arg1)
{
    values.var.gamma = arg1.toInt();
    ui->horizontalSlider_4->setValue(values.var.gamma);
    emit valueChanged(values);
}
// Contrast
// Alpha
void cvConfig::on_horizontalSlider_5_valueChanged(int value)
{
    values.var.scale = value;
    ui->lineEdit_5->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_5_textEdited(const QString &arg1)
{
    values.var.scale = arg1.toInt();
    ui->horizontalSlider_5->setValue(values.var.scale);
    emit valueChanged(values);
}
//Beta


void cvConfig::on_horizontalSlider_6_valueChanged(int value)
{
    values.var.betaC = value;
    ui->lineEdit_6->setText(QString::number(value));
    emit valueChanged(values);
}


void cvConfig::on_lineEdit_6_textEdited(const QString &arg1)
{
    values.var.betaC = arg1.toInt();
    ui->horizontalSlider_6->setValue(values.var.betaC);
    emit valueChanged(values);
}

//Morphological Open
// Size X
void cvConfig::on_horizontalSlider_8_valueChanged(int value)
{
    values.var.ssSizeX = value;
    ui->lineEdit_8->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_8_textEdited(const QString &arg1)
{
    values.var.ssSizeX = arg1.toInt();
    ui->horizontalSlider_8->setValue(values.var.ssSizeX);
    emit valueChanged(values);
}

void cvConfig::on_horizontalSlider_9_valueChanged(int value)
{
    values.var.ssSizeY = value;
    ui->lineEdit_9->setText(QString::number(value));
    emit valueChanged(values);
}

void cvConfig::on_lineEdit_9_textEdited(const QString &arg1)
{
    values.var.ssSizeY = arg1.toInt();
    ui->horizontalSlider_9->setValue(values.var.ssSizeY);
    emit valueChanged(values);
}
