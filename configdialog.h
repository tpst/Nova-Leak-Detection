#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QString>

namespace Ui {
class configDialog;
}

class configDialog : public QDialog
{
    Q_OBJECT

public:
    explicit configDialog(QWidget *parent = 0);
    ~configDialog();

    bool isButton1Checked();

    bool isButton2Checked();

    bool validStream();

    void getIPs(QString& one, QString& two);

private slots:
    void on_buttonBox_accepted();

    void on_radioButton_3_toggled(bool checked);

private:
    Ui::configDialog *ui;
};

#endif // CONFIGDIALOG_H
