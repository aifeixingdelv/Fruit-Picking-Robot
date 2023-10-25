/********************************************************************************
** Form generated from reading UI file 'ebox_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EBOX_MAINWINDOW_H
#define UI_EBOX_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Eboxmainwindow
{
public:
    QFrame *frame;
    QLabel *label;
    QLineEdit *car_connect_lineedit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *time;
    QLineEdit *car_task_num_lineedit;
    QLineEdit *mboxconnect;
    QLineEdit *rtkconnect;
    QLineEdit *action;
    QLineEdit *action2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *shibie;
    QLabel *fenge;
    QLabel *chengshudu;
    QLabel *label_8;
    QTextEdit *robot_arm_pose;
    QTextEdit *detect_objects;
    QLabel *label_9;
    QWidget *widget;
    QPushButton *forward_pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_14;
    QLineEdit *forward_status_lineedit;
    QLabel *label_15;
    QLineEdit *back_status_lineedit;
    QLabel *label_16;
    QLineEdit *left_status_lineedit;
    QLabel *label_17;
    QLineEdit *right_status_lineedit;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_18;
    QLineEdit *forward_speed_lineedit;
    QLabel *label_19;
    QLineEdit *back_speed_lineedit;
    QLabel *label_20;
    QLineEdit *left_speed_lineedit;
    QLabel *label_21;
    QLineEdit *right_speed_lineedit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *mboxconnect_10;
    QLineEdit *mboxconnect_11;
    QPushButton *right_pushButton;
    QPushButton *back_pushButton;
    QPushButton *left_pushButton;
    QLabel *label_10;
    QLabel *tracked_path;
    QLabel *label_11;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_24;
    QTextEdit *camera_detect_textedit;
    QTextEdit *lidar_detect_textedit;
    QTextEdit *other__detect_textedit;

    void setupUi(QWidget *Eboxmainwindow)
    {
        if (Eboxmainwindow->objectName().isEmpty())
            Eboxmainwindow->setObjectName(QString::fromUtf8("Eboxmainwindow"));
        Eboxmainwindow->resize(1906, 941);
        frame = new QFrame(Eboxmainwindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 1891, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 15, 181, 41));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        car_connect_lineedit = new QLineEdit(frame);
        car_connect_lineedit->setObjectName(QString::fromUtf8("car_connect_lineedit"));
        car_connect_lineedit->setGeometry(QRect(611, 10, 91, 50));
        car_connect_lineedit->setFont(font);
        car_connect_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        car_connect_lineedit->setAlignment(Qt::AlignCenter);
        car_connect_lineedit->setReadOnly(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(720, 15, 181, 41));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(976, 15, 181, 41));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1261, 10, 200, 50));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1578, 10, 200, 50));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        time = new QLineEdit(frame);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(10, 10, 200, 50));
        time->setFont(font);
        time->setAlignment(Qt::AlignCenter);
        time->setReadOnly(true);
        car_task_num_lineedit = new QLineEdit(frame);
        car_task_num_lineedit->setObjectName(QString::fromUtf8("car_task_num_lineedit"));
        car_task_num_lineedit->setGeometry(QRect(220, 10, 200, 50));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(car_task_num_lineedit->sizePolicy().hasHeightForWidth());
        car_task_num_lineedit->setSizePolicy(sizePolicy);
        car_task_num_lineedit->setFont(font);
        car_task_num_lineedit->setEchoMode(QLineEdit::Normal);
        car_task_num_lineedit->setAlignment(Qt::AlignCenter);
        car_task_num_lineedit->setReadOnly(true);
        mboxconnect = new QLineEdit(frame);
        mboxconnect->setObjectName(QString::fromUtf8("mboxconnect"));
        mboxconnect->setGeometry(QRect(889, 10, 91, 50));
        mboxconnect->setFont(font);
        mboxconnect->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        mboxconnect->setAlignment(Qt::AlignCenter);
        mboxconnect->setReadOnly(true);
        rtkconnect = new QLineEdit(frame);
        rtkconnect->setObjectName(QString::fromUtf8("rtkconnect"));
        rtkconnect->setGeometry(QRect(1130, 10, 91, 50));
        rtkconnect->setFont(font);
        rtkconnect->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        rtkconnect->setAlignment(Qt::AlignCenter);
        rtkconnect->setReadOnly(true);
        action = new QLineEdit(frame);
        action->setObjectName(QString::fromUtf8("action"));
        action->setGeometry(QRect(1469, 10, 91, 50));
        action->setFont(font);
        action->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        action->setAlignment(Qt::AlignCenter);
        action->setReadOnly(true);
        action2 = new QLineEdit(frame);
        action2->setObjectName(QString::fromUtf8("action2"));
        action2->setGeometry(QRect(1787, 10, 91, 50));
        action2->setFont(font);
        action2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        action2->setAlignment(Qt::AlignCenter);
        action2->setReadOnly(true);
        label_4 = new QLabel(Eboxmainwindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 481, 51));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 208, 80);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Eboxmainwindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 100, 481, 51));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 191, 191);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Eboxmainwindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1040, 99, 481, 51));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 217, 102);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Eboxmainwindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1560, 100, 331, 51));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 176, 240);"));
        label_7->setAlignment(Qt::AlignCenter);
        shibie = new QLabel(Eboxmainwindow);
        shibie->setObjectName(QString::fromUtf8("shibie"));
        shibie->setGeometry(QRect(20, 154, 481, 371));
        shibie->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 127);"));
        fenge = new QLabel(Eboxmainwindow);
        fenge->setObjectName(QString::fromUtf8("fenge"));
        fenge->setGeometry(QRect(530, 154, 481, 371));
        fenge->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 127);"));
        chengshudu = new QLabel(Eboxmainwindow);
        chengshudu->setObjectName(QString::fromUtf8("chengshudu"));
        chengshudu->setGeometry(QRect(1040, 154, 481, 371));
        chengshudu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 127);"));
        label_8 = new QLabel(Eboxmainwindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1560, 390, 331, 51));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 176, 240);"));
        label_8->setAlignment(Qt::AlignCenter);
        robot_arm_pose = new QTextEdit(Eboxmainwindow);
        robot_arm_pose->setObjectName(QString::fromUtf8("robot_arm_pose"));
        robot_arm_pose->setGeometry(QRect(1560, 440, 331, 81));
        detect_objects = new QTextEdit(Eboxmainwindow);
        detect_objects->setObjectName(QString::fromUtf8("detect_objects"));
        detect_objects->setGeometry(QRect(1560, 151, 331, 231));
        label_9 = new QLabel(Eboxmainwindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 540, 351, 51));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 176, 240);"));
        label_9->setAlignment(Qt::AlignCenter);
        widget = new QWidget(Eboxmainwindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 600, 351, 331));
        forward_pushButton = new QPushButton(widget);
        forward_pushButton->setObjectName(QString::fromUtf8("forward_pushButton"));
        forward_pushButton->setGeometry(QRect(120, 220, 101, 41));
        QFont font2;
        font2.setPointSize(12);
        forward_pushButton->setFont(font2);
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 171, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_14);

        forward_status_lineedit = new QLineEdit(formLayoutWidget);
        forward_status_lineedit->setObjectName(QString::fromUtf8("forward_status_lineedit"));
        forward_status_lineedit->setFont(font);
        forward_status_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        forward_status_lineedit->setAlignment(Qt::AlignCenter);
        forward_status_lineedit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, forward_status_lineedit);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_15);

        back_status_lineedit = new QLineEdit(formLayoutWidget);
        back_status_lineedit->setObjectName(QString::fromUtf8("back_status_lineedit"));
        back_status_lineedit->setFont(font);
        back_status_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        back_status_lineedit->setAlignment(Qt::AlignCenter);
        back_status_lineedit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, back_status_lineedit);

        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_16);

        left_status_lineedit = new QLineEdit(formLayoutWidget);
        left_status_lineedit->setObjectName(QString::fromUtf8("left_status_lineedit"));
        left_status_lineedit->setFont(font);
        left_status_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        left_status_lineedit->setAlignment(Qt::AlignCenter);
        left_status_lineedit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, left_status_lineedit);

        label_17 = new QLabel(formLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_17);

        right_status_lineedit = new QLineEdit(formLayoutWidget);
        right_status_lineedit->setObjectName(QString::fromUtf8("right_status_lineedit"));
        right_status_lineedit->setFont(font);
        right_status_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        right_status_lineedit->setAlignment(Qt::AlignCenter);
        right_status_lineedit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, right_status_lineedit);

        formLayoutWidget_2 = new QWidget(widget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(180, 0, 171, 141));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_18);

        forward_speed_lineedit = new QLineEdit(formLayoutWidget_2);
        forward_speed_lineedit->setObjectName(QString::fromUtf8("forward_speed_lineedit"));
        forward_speed_lineedit->setFont(font);
        forward_speed_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        forward_speed_lineedit->setAlignment(Qt::AlignCenter);
        forward_speed_lineedit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, forward_speed_lineedit);

        label_19 = new QLabel(formLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_19);

        back_speed_lineedit = new QLineEdit(formLayoutWidget_2);
        back_speed_lineedit->setObjectName(QString::fromUtf8("back_speed_lineedit"));
        back_speed_lineedit->setFont(font);
        back_speed_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        back_speed_lineedit->setAlignment(Qt::AlignCenter);
        back_speed_lineedit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, back_speed_lineedit);

        label_20 = new QLabel(formLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);
        label_20->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_20);

        left_speed_lineedit = new QLineEdit(formLayoutWidget_2);
        left_speed_lineedit->setObjectName(QString::fromUtf8("left_speed_lineedit"));
        left_speed_lineedit->setFont(font);
        left_speed_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        left_speed_lineedit->setAlignment(Qt::AlignCenter);
        left_speed_lineedit->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, left_speed_lineedit);

        label_21 = new QLabel(formLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_21);

        right_speed_lineedit = new QLineEdit(formLayoutWidget_2);
        right_speed_lineedit->setObjectName(QString::fromUtf8("right_speed_lineedit"));
        right_speed_lineedit->setFont(font);
        right_speed_lineedit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        right_speed_lineedit->setAlignment(Qt::AlignCenter);
        right_speed_lineedit->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, right_speed_lineedit);

        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 145, 351, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_22, 0, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font2);
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_23, 0, 1, 1, 1);

        mboxconnect_10 = new QLineEdit(gridLayoutWidget);
        mboxconnect_10->setObjectName(QString::fromUtf8("mboxconnect_10"));
        mboxconnect_10->setFont(font);
        mboxconnect_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        mboxconnect_10->setAlignment(Qt::AlignCenter);
        mboxconnect_10->setReadOnly(true);

        gridLayout->addWidget(mboxconnect_10, 1, 0, 1, 1);

        mboxconnect_11 = new QLineEdit(gridLayoutWidget);
        mboxconnect_11->setObjectName(QString::fromUtf8("mboxconnect_11"));
        mboxconnect_11->setFont(font);
        mboxconnect_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        mboxconnect_11->setAlignment(Qt::AlignCenter);
        mboxconnect_11->setReadOnly(true);

        gridLayout->addWidget(mboxconnect_11, 1, 1, 1, 1);

        right_pushButton = new QPushButton(widget);
        right_pushButton->setObjectName(QString::fromUtf8("right_pushButton"));
        right_pushButton->setGeometry(QRect(230, 240, 101, 41));
        right_pushButton->setFont(font2);
        back_pushButton = new QPushButton(widget);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));
        back_pushButton->setGeometry(QRect(120, 270, 101, 41));
        back_pushButton->setFont(font2);
        left_pushButton = new QPushButton(widget);
        left_pushButton->setObjectName(QString::fromUtf8("left_pushButton"));
        left_pushButton->setGeometry(QRect(10, 240, 101, 41));
        left_pushButton->setFont(font2);
        label_10 = new QLabel(Eboxmainwindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(390, 540, 811, 51));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 176, 240);"));
        label_10->setAlignment(Qt::AlignCenter);
        tracked_path = new QLabel(Eboxmainwindow);
        tracked_path->setObjectName(QString::fromUtf8("tracked_path"));
        tracked_path->setGeometry(QRect(390, 600, 811, 321));
        tracked_path->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 127);"));
        label_11 = new QLabel(Eboxmainwindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1220, 540, 671, 51));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 176, 240);"));
        label_11->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(Eboxmainwindow);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1220, 600, 671, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("aakar"));
        font3.setPointSize(14);
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 208, 80);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 208, 80);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 0, 1, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font3);
        label_24->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 208, 80);"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_24, 0, 2, 1, 1);

        camera_detect_textedit = new QTextEdit(gridLayoutWidget_2);
        camera_detect_textedit->setObjectName(QString::fromUtf8("camera_detect_textedit"));

        gridLayout_2->addWidget(camera_detect_textedit, 1, 0, 1, 1);

        lidar_detect_textedit = new QTextEdit(gridLayoutWidget_2);
        lidar_detect_textedit->setObjectName(QString::fromUtf8("lidar_detect_textedit"));

        gridLayout_2->addWidget(lidar_detect_textedit, 1, 1, 1, 1);

        other__detect_textedit = new QTextEdit(gridLayoutWidget_2);
        other__detect_textedit->setObjectName(QString::fromUtf8("other__detect_textedit"));

        gridLayout_2->addWidget(other__detect_textedit, 1, 2, 1, 1);


        retranslateUi(Eboxmainwindow);

        QMetaObject::connectSlotsByName(Eboxmainwindow);
    } // setupUi

    void retranslateUi(QWidget *Eboxmainwindow)
    {
        Eboxmainwindow->setWindowTitle(QApplication::translate("Eboxmainwindow", "\346\236\227\346\236\234\351\207\207\346\221\230\346\234\272\345\231\250\344\272\272\346\204\237\347\237\245\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("Eboxmainwindow", "\347\247\273\345\212\250\345\272\225\347\233\230\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        car_connect_lineedit->setText(QString());
        label_2->setText(QApplication::translate("Eboxmainwindow", "\350\275\257Mbox\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Eboxmainwindow", "RTK\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Eboxmainwindow", "\346\211\247\350\241\214\351\207\207\346\221\230", nullptr));
        pushButton_2->setText(QApplication::translate("Eboxmainwindow", "\351\242\204\347\225\231\346\214\211\351\222\256", nullptr));
        time->setText(QString());
        car_task_num_lineedit->setInputMask(QString());
        car_task_num_lineedit->setText(QString());
        mboxconnect->setText(QString());
        rtkconnect->setText(QString());
        action->setText(QString());
        action2->setText(QString());
        label_4->setText(QApplication::translate("Eboxmainwindow", "\347\233\270\346\234\272\347\262\227\345\256\232\344\275\215\357\274\210\350\257\206\345\210\253\357\274\211", nullptr));
        label_5->setText(QApplication::translate("Eboxmainwindow", "\347\233\270\346\234\272\347\262\276\345\256\232\344\275\215\357\274\210\345\210\206\345\211\262\357\274\211", nullptr));
        label_6->setText(QApplication::translate("Eboxmainwindow", "\347\233\270\346\234\272\347\262\276\345\256\232\344\275\215\357\274\210\346\210\220\347\206\237\345\272\246\346\243\200\346\265\213\357\274\211", nullptr));
        label_7->setText(QApplication::translate("Eboxmainwindow", "\346\237\221\346\251\230\350\257\206\345\210\253\347\273\223\346\236\234", nullptr));
        shibie->setText(QString());
        fenge->setText(QString());
        chengshudu->setText(QString());
        label_8->setText(QApplication::translate("Eboxmainwindow", "\345\275\223\345\211\215\346\234\272\346\242\260\350\207\202\344\275\215\345\247\277", nullptr));
        label_9->setText(QApplication::translate("Eboxmainwindow", "\346\234\272\346\242\260\350\277\220\345\212\250\345\217\202\346\225\260", nullptr));
        forward_pushButton->setText(QApplication::translate("Eboxmainwindow", "\345\211\215\350\277\233", nullptr));
        label_14->setText(QApplication::translate("Eboxmainwindow", "\345\211\215\350\277\233\347\212\266\346\200\201\357\274\232", nullptr));
        forward_status_lineedit->setText(QString());
        label_15->setText(QApplication::translate("Eboxmainwindow", "\345\220\216\351\200\200\347\212\266\346\200\201\357\274\232", nullptr));
        back_status_lineedit->setText(QString());
        label_16->setText(QApplication::translate("Eboxmainwindow", "\345\267\246\350\275\254\347\212\266\346\200\201\357\274\232", nullptr));
        left_status_lineedit->setText(QString());
        label_17->setText(QApplication::translate("Eboxmainwindow", "\345\217\263\350\275\254\347\212\266\346\200\201\357\274\232", nullptr));
        right_status_lineedit->setText(QString());
        label_18->setText(QApplication::translate("Eboxmainwindow", "\345\211\215\350\277\233\351\200\237\345\272\246\357\274\232", nullptr));
        forward_speed_lineedit->setText(QString());
        label_19->setText(QApplication::translate("Eboxmainwindow", "\345\220\216\351\200\200\351\200\237\345\272\246\357\274\232", nullptr));
        back_speed_lineedit->setText(QString());
        label_20->setText(QApplication::translate("Eboxmainwindow", "\345\267\246\350\275\254\351\200\237\345\272\246\357\274\232", nullptr));
        left_speed_lineedit->setText(QString());
        label_21->setText(QApplication::translate("Eboxmainwindow", "\345\217\263\350\275\254\351\200\237\345\272\246\357\274\232", nullptr));
        right_speed_lineedit->setText(QString());
        label_22->setText(QApplication::translate("Eboxmainwindow", "RTK\345\235\220\346\240\207XYZ\357\274\232", nullptr));
        label_23->setText(QApplication::translate("Eboxmainwindow", "\345\201\217\350\210\252\350\247\222\357\274\232", nullptr));
        mboxconnect_10->setText(QString());
        mboxconnect_11->setText(QString());
        right_pushButton->setText(QApplication::translate("Eboxmainwindow", "\345\217\263\350\275\254", nullptr));
        back_pushButton->setText(QApplication::translate("Eboxmainwindow", "\345\220\216\351\200\200", nullptr));
        left_pushButton->setText(QApplication::translate("Eboxmainwindow", "\345\267\246\350\275\254", nullptr));
        label_10->setText(QApplication::translate("Eboxmainwindow", "\350\267\237\350\270\252\350\267\257\345\276\204", nullptr));
        tracked_path->setText(QString());
        label_11->setText(QApplication::translate("Eboxmainwindow", "\351\232\234\347\242\215\347\211\251\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        label_12->setText(QApplication::translate("Eboxmainwindow", "\346\267\261\345\272\246\347\233\270\346\234\272", nullptr));
        label_13->setText(QApplication::translate("Eboxmainwindow", "\346\277\200\345\205\211\351\233\267\350\276\276", nullptr));
        label_24->setText(QApplication::translate("Eboxmainwindow", "\345\205\266\345\256\203\344\274\240\346\204\237\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Eboxmainwindow: public Ui_Eboxmainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EBOX_MAINWINDOW_H
