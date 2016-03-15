#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->statusBar->showMessage("LeL");

    handler = new captureHandler();

    // Allow Mats to be passed through signal
    qRegisterMetaType< cv::Mat >("cv::Mat");
    connect(ui->exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(handler, SIGNAL(frameReady(QImage)), this, SLOT(updateDisplay(QImage)));
    connect(handler, SIGNAL(frameReady2(QImage)), this, SLOT(updateDisplay2(QImage)));
    connect(handler, SIGNAL(refreshDisplays()), this, SLOT(refreshDisplays()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddStream_clicked()
{
    if(cfg.validStream()) // check that both streams are toggled on, IP's are valid
    {
        cfg.getIPs(handler->IP1, handler->IP2);

        handler->toggleStream1(cfg.isButton2Checked()); // stream 1 is blackfly, thus swap toggle
        handler->toggleStream2(cfg.isButton1Checked()); // stream 2 is first IP

        this->refreshDisplays();

        handler->playStream();
    }
}

void MainWindow::updateDisplay(QImage frame)
{
    if(!frame.isNull())
    {
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(frame).scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::updateDisplay2(QImage frame)
{
    if(!frame.isNull())
    {
        ui->label_2->setAlignment(Qt::AlignCenter);
        ui->label_2->setPixmap(QPixmap::fromImage(frame).scaled(ui->label_2->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::on_stopButton_clicked()
{
    // stop streams
    handler->Stop();

    handler->quit();

    cvCfg.disconnect();

    this->refreshDisplays();
}

void MainWindow::on_exitButton_clicked()
{
    handler->Stop();
    close();
}

void MainWindow::on_recordStream_clicked()
{
    if(!handler->isStopped()) {
        if(handler->isRecording())
        {
            ui->recordStream->setText("Record");
            handler->toggleRecord(false);
        } else {
            ui->recordStream->setText("Stop Recording");
            handler->toggleRecord(true);
        }
        //handler->recordStream();

    }
}

void MainWindow::on_toolButton_clicked()
{
    cfg.setModal(true);
    cfg.exec();
}

void MainWindow::on_processStream_clicked()
{
    if(!handler->isProcessActive())
    {
        handler->toggleProcess(true);
        ui->processStream->setText("Stop Process");
    } else {
        handler->toggleProcess(false);
        ui->processStream->setText("Process");
    }
}

void MainWindow::refreshDisplays()
{
    if(!handler->isStream1Active() && !handler->isStream2Active())
    {
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
    } else {
        ui->label->setVisible(handler->isStream1Active());
        ui->label_2->setVisible(handler->isStream2Active());
    }
    ui->label->clear();
    ui->label_2->clear();
    //ui->label->repaint();
    //ui->label_2->repaint();
}

void MainWindow::on_toolButton_2_clicked()
{
    try {

        cvCfg.setModal(false);
        cvCfg.show();
        if(!handler->isStopped() && handler->isStream2Active())
        {
            cvCfg.init(*handler->get2);
        } else {
            cvCfg.disconnect();
        }
    } catch(std::exception &e) {
        qDebug() << "Error: " << e.what();
    }
}
