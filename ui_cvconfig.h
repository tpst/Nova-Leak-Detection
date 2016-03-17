/********************************************************************************
** Form generated from reading UI file 'cvconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVCONFIG_H
#define UI_CVCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cvConfig
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_15;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_19;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_17;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_18;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_24;
    QSlider *cropwidth;
    QSlider *cropx;
    QLabel *label_23;
    QLabel *label_x;
    QSlider *cropheight;
    QLabel *label_22;
    QSlider *cropy;
    QSlider *horizontalSlider;
    QLabel *label_11;
    QFrame *line_4;
    QSlider *horizontalSlider_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_14;
    QSlider *horizontalSlider_2;
    QFrame *line;
    QSlider *horizontalSlider_9;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QFrame *line_2;
    QFrame *line_7;
    QSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_6;
    QSpacerItem *verticalSpacer;
    QLabel *label_7;
    QFrame *line_9;
    QFrame *line_6;
    QSlider *horizontalSlider_8;
    QLabel *label_6;
    QFrame *line_8;
    QSlider *horizontalSlider_7;
    QFrame *line_10;
    QLabel *label_20;
    QFrame *line_3;
    QFrame *line_11;
    QDialogButtonBox *buttonBox;
    QPushButton *applyButton;

    void setupUi(QDialog *cvConfig)
    {
        if (cvConfig->objectName().isEmpty())
            cvConfig->setObjectName(QStringLiteral("cvConfig"));
        cvConfig->resize(722, 683);
        gridLayout_3 = new QGridLayout(cvConfig);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frame = new QFrame(cvConfig);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(411, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_5->addWidget(label_15);


        gridLayout_2->addWidget(frame_4, 1, 0, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_4->addWidget(label_19);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_16 = new QLabel(frame_5);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_6->addWidget(label_16);


        gridLayout_2->addWidget(frame_5, 1, 1, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);


        gridLayout_2->addWidget(frame_3, 0, 1, 1, 1);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_17 = new QLabel(frame_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_7->addWidget(label_17);


        gridLayout_2->addWidget(frame_6, 2, 0, 1, 1);

        frame_7 = new QFrame(frame);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_7);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_18 = new QLabel(frame_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_8->addWidget(label_18);


        gridLayout_2->addWidget(frame_7, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        widget = new QWidget(cvConfig);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_4->addWidget(label_24, 1, 2, 1, 1);

        cropwidth = new QSlider(widget);
        cropwidth->setObjectName(QStringLiteral("cropwidth"));
        cropwidth->setMinimum(20);
        cropwidth->setMaximum(100);
        cropwidth->setValue(50);
        cropwidth->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(cropwidth, 0, 3, 1, 1);

        cropx = new QSlider(widget);
        cropx->setObjectName(QStringLiteral("cropx"));
        cropx->setMinimum(1);
        cropx->setMaximum(99);
        cropx->setValue(40);
        cropx->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(cropx, 0, 1, 1, 1);

        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_4->addWidget(label_23, 0, 2, 1, 1);

        label_x = new QLabel(widget);
        label_x->setObjectName(QStringLiteral("label_x"));

        gridLayout_4->addWidget(label_x, 0, 0, 1, 1);

        cropheight = new QSlider(widget);
        cropheight->setObjectName(QStringLiteral("cropheight"));
        cropheight->setMinimum(20);
        cropheight->setMaximum(100);
        cropheight->setValue(80);
        cropheight->setSliderPosition(80);
        cropheight->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(cropheight, 1, 3, 1, 1);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_4->addWidget(label_22, 1, 0, 1, 1);

        cropy = new QSlider(widget);
        cropy->setObjectName(QStringLiteral("cropy"));
        cropy->setMinimum(1);
        cropy->setMaximum(99);
        cropy->setValue(10);
        cropy->setOrientation(Qt::Horizontal);
        cropy->setInvertedAppearance(false);
        cropy->setInvertedControls(false);

        gridLayout_4->addWidget(cropy, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 3, 0, 1, 1);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);

        gridLayout->addWidget(horizontalSlider, 21, 0, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 24, 0, 1, 1);

        line_4 = new QFrame(widget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 29, 0, 1, 1);

        horizontalSlider_5 = new QSlider(widget);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(10000);
        horizontalSlider_5->setPageStep(100);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_5, 15, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMaximumSize(QSize(50, 16777215));
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(50, 16777215));
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(50, 16777215));
        lineEdit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 1);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 18, 0, 1, 1);

        horizontalSlider_2 = new QSlider(widget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(3000);
        horizontalSlider_2->setPageStep(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(horizontalSlider_2, 8, 0, 1, 1);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 23, 0, 1, 1);

        horizontalSlider_9 = new QSlider(widget);
        horizontalSlider_9->setObjectName(QStringLiteral("horizontalSlider_9"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalSlider_9->sizePolicy().hasHeightForWidth());
        horizontalSlider_9->setSizePolicy(sizePolicy3);
        horizontalSlider_9->setMinimum(1);
        horizontalSlider_9->setMaximum(20);
        horizontalSlider_9->setPageStep(1);
        horizontalSlider_9->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_9, 28, 0, 1, 1);

        line_5 = new QFrame(widget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy2.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy2);
        lineEdit_8->setMaximumSize(QSize(60, 16777215));
        lineEdit_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit_8);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        sizePolicy2.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy2);
        lineEdit_9->setMaximumSize(QSize(60, 16777215));
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit_9);


        gridLayout->addLayout(horizontalLayout_4, 26, 0, 1, 1);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 11, 0, 1, 1);

        line_7 = new QFrame(widget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 13, 0, 1, 1);

        horizontalSlider_3 = new QSlider(widget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(2000);
        horizontalSlider_3->setPageStep(100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 9, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(1666, 16777215));

        horizontalLayout_3->addWidget(label_8);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);
        lineEdit_5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEdit_5);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);
        label_9->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_9);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);
        lineEdit_6->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEdit_6);


        gridLayout->addLayout(horizontalLayout_3, 14, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMaximumSize(QSize(60, 16777215));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(false);

        horizontalLayout_2->addWidget(lineEdit);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(lineEdit_7);


        gridLayout->addLayout(horizontalLayout_2, 20, 0, 1, 1);

        horizontalSlider_4 = new QSlider(widget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(100000);
        horizontalSlider_4->setPageStep(1000);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 10, 0, 1, 1);

        horizontalSlider_6 = new QSlider(widget);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setMaximum(100000);
        horizontalSlider_6->setPageStep(1000);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_6, 16, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 30, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        line_9 = new QFrame(widget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_9, 25, 0, 1, 1);

        line_6 = new QFrame(widget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 6, 0, 1, 1);

        horizontalSlider_8 = new QSlider(widget);
        horizontalSlider_8->setObjectName(QStringLiteral("horizontalSlider_8"));
        sizePolicy3.setHeightForWidth(horizontalSlider_8->sizePolicy().hasHeightForWidth());
        horizontalSlider_8->setSizePolicy(sizePolicy3);
        horizontalSlider_8->setMinimum(1);
        horizontalSlider_8->setMaximum(20);
        horizontalSlider_8->setPageStep(1);
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_8, 27, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        line_8 = new QFrame(widget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 19, 0, 1, 1);

        horizontalSlider_7 = new QSlider(widget);
        horizontalSlider_7->setObjectName(QStringLiteral("horizontalSlider_7"));
        horizontalSlider_7->setMinimum(1);
        horizontalSlider_7->setMaximum(20);
        horizontalSlider_7->setPageStep(1);
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_7, 22, 0, 1, 1);

        line_10 = new QFrame(widget);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_10, 0, 0, 1, 1);

        label_20 = new QLabel(widget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 1, 0, 1, 1);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 17, 0, 1, 1);

        line_11 = new QFrame(widget);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_3->addWidget(widget, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(cvConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy6);
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 1, 1, 1);

        applyButton = new QPushButton(cvConfig);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        sizePolicy2.setHeightForWidth(applyButton->sizePolicy().hasHeightForWidth());
        applyButton->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(applyButton, 1, 0, 1, 1);


        retranslateUi(cvConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), cvConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cvConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(cvConfig);
    } // setupUi

    void retranslateUi(QDialog *cvConfig)
    {
        cvConfig->setWindowTitle(QApplication::translate("cvConfig", "Dialog", 0));
        label_15->setText(QApplication::translate("cvConfig", "contrast", 0));
        label_19->setText(QApplication::translate("cvConfig", "crop", 0));
        label_16->setText(QApplication::translate("cvConfig", "thresh", 0));
        label->setText(QApplication::translate("cvConfig", "sharp", 0));
        label_17->setText(QApplication::translate("cvConfig", "open", 0));
        label_18->setText(QApplication::translate("cvConfig", "result", 0));
        label_24->setText(QApplication::translate("cvConfig", "h", 0));
        label_23->setText(QApplication::translate("cvConfig", "w", 0));
        label_x->setText(QApplication::translate("cvConfig", "x", 0));
        label_22->setText(QApplication::translate("cvConfig", "y", 0));
        label_11->setText(QApplication::translate("cvConfig", "Morphological Opening", 0));
        label_3->setText(QApplication::translate("cvConfig", "Alpha", 0));
        lineEdit_2->setText(QApplication::translate("cvConfig", "2500", 0));
        label_4->setText(QApplication::translate("cvConfig", "Beta", 0));
        lineEdit_3->setText(QApplication::translate("cvConfig", "342", 0));
        label_5->setText(QApplication::translate("cvConfig", "Gamma", 0));
        lineEdit_4->setText(QApplication::translate("cvConfig", "6952", 0));
        label_14->setText(QApplication::translate("cvConfig", "Threshold & Closing", 0));
        label_12->setText(QApplication::translate("cvConfig", "Size X", 0));
        lineEdit_8->setText(QApplication::translate("cvConfig", "15", 0));
        label_13->setText(QApplication::translate("cvConfig", "Size Y", 0));
        lineEdit_9->setText(QApplication::translate("cvConfig", "2", 0));
        label_8->setText(QApplication::translate("cvConfig", "Alpha", 0));
        lineEdit_5->setText(QApplication::translate("cvConfig", "3685", 0));
        label_9->setText(QApplication::translate("cvConfig", "Beta", 0));
        lineEdit_6->setText(QApplication::translate("cvConfig", "66400", 0));
        label_2->setText(QApplication::translate("cvConfig", "Threshold Value:", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QApplication::translate("cvConfig", "128", 0));
        label_10->setText(QApplication::translate("cvConfig", "Size", 0));
        lineEdit_7->setText(QApplication::translate("cvConfig", "6", 0));
        label_7->setText(QApplication::translate("cvConfig", "Contrast", 0));
        label_6->setText(QApplication::translate("cvConfig", "Image Sharpening", 0));
        label_20->setText(QApplication::translate("cvConfig", "Crop Parameters", 0));
        applyButton->setText(QApplication::translate("cvConfig", "Apply Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class cvConfig: public Ui_cvConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVCONFIG_H
