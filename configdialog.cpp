#include "configdialog.h"
#include "ui_configdialog.h"


configDialog::configDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    if(ui->radioButton_3->isChecked())
    {
        ui->lineEdit_2->setReadOnly(true);
        ui->lineEdit_2->setStyleSheet("Background: #F2F1F0");
    }
}

configDialog::~configDialog()
{
    delete ui;
}

bool configDialog::isButton1Checked()
{
    return ui->radioButton->isChecked();
}

bool  configDialog::isButton2Checked()
{
    return ui->radioButton_2->isChecked();
}

bool configDialog::isButton3Checked()
{
    return ui->radioButton_3->isChecked();
}

// Validate config. This should also check IP address
bool configDialog::validStream()
{
    if(!this->isButton1Checked() && !this->isButton2Checked())
    {
        return false;
    } else {
        return true;
    }
}

void configDialog::getIPs(QString& one, QString& two)
{
     //http://169.254.101.222/mjpg/video.mjpg
    one.clear();
    two.clear();

    QString str = "http://";
    one += str;
    two += str;
    one += ui->lineEdit->text();
    two += ui->lineEdit_2->text();

    str = "/mjpg/video.mjpg";
    one += str;
    two += str;

}

void configDialog::on_buttonBox_accepted()
{
}



void configDialog::on_radioButton_3_toggled(bool checked)
{
    if(!checked)
    {
        ui->lineEdit_2->setReadOnly(false);
        ui->lineEdit_2->setStyleSheet("Background: #FFFFFF");
    } else {
        ui->lineEdit_2->setReadOnly(true);
        ui->lineEdit_2->setStyleSheet("Background: #F2F1F0");
    }

}
