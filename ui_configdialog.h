/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_configDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName(QStringLiteral("configDialog"));
        configDialog->resize(380, 143);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(configDialog->sizePolicy().hasHeightForWidth());
        configDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(configDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        label = new QLabel(configDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(configDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setFrame(true);
        lineEdit_2->setReadOnly(false);
        lineEdit_2->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lineEdit_2);

        radioButton_2 = new QRadioButton(configDialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(true);
        radioButton_2->setAutoExclusive(false);

        horizontalLayout_2->addWidget(radioButton_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(configDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit);

        radioButton = new QRadioButton(configDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);
        radioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(radioButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        radioButton_3 = new QRadioButton(configDialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(true);

        gridLayout->addWidget(radioButton_3, 3, 0, 1, 1);


        retranslateUi(configDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), configDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QApplication::translate("configDialog", "Stream IP Config", 0));
        label->setText(QApplication::translate("configDialog", "Stream IP Address", 0));
        lineEdit_2->setInputMask(QApplication::translate("configDialog", "000.000.000.000", 0));
        lineEdit_2->setText(QApplication::translate("configDialog", "...", 0));
        radioButton_2->setText(QApplication::translate("configDialog", "Connect", 0));
        lineEdit->setInputMask(QApplication::translate("configDialog", "000.000.000.000", 0));
        lineEdit->setText(QApplication::translate("configDialog", "192.168.20.102", 0));
        radioButton->setText(QApplication::translate("configDialog", "Connect", 0));
        radioButton_3->setText(QApplication::translate("configDialog", "BlackFly Cam Active", 0));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
