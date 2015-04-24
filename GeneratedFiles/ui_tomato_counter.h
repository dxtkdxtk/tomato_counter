/********************************************************************************
** Form generated from reading UI file 'tomato_counter.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOMATO_COUNTER_H
#define UI_TOMATO_COUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tomato_counterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *exitButton;
    QLCDNumber *timeCounter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *tomato_counterClass)
    {
        if (tomato_counterClass->objectName().isEmpty())
            tomato_counterClass->setObjectName(QStringLiteral("tomato_counterClass"));
        tomato_counterClass->resize(861, 599);
        centralWidget = new QWidget(tomato_counterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei Mono"));
        font.setPointSize(12);
        startButton->setFont(font);

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setFont(font);

        horizontalLayout->addWidget(stopButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);


        gridLayout->addLayout(horizontalLayout, 5, 2, 1, 1);

        timeCounter = new QLCDNumber(centralWidget);
        timeCounter->setObjectName(QStringLiteral("timeCounter"));
        timeCounter->setSmallDecimalPoint(false);
        timeCounter->setMode(QLCDNumber::Dec);
        timeCounter->setSegmentStyle(QLCDNumber::Flat);
        timeCounter->setProperty("value", QVariant(0));
        timeCounter->setProperty("intValue", QVariant(0));

        gridLayout->addWidget(timeCounter, 4, 2, 1, 1);

        tomato_counterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(tomato_counterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 26));
        tomato_counterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(tomato_counterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        tomato_counterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(tomato_counterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        tomato_counterClass->setStatusBar(statusBar);

        retranslateUi(tomato_counterClass);

        QMetaObject::connectSlotsByName(tomato_counterClass);
    } // setupUi

    void retranslateUi(QMainWindow *tomato_counterClass)
    {
        tomato_counterClass->setWindowTitle(QApplication::translate("tomato_counterClass", "tomato_counter", 0));
        startButton->setText(QApplication::translate("tomato_counterClass", "start work now", 0));
        stopButton->setText(QApplication::translate("tomato_counterClass", "stop", 0));
        exitButton->setText(QApplication::translate("tomato_counterClass", "exit", 0));
    } // retranslateUi

};

namespace Ui {
    class tomato_counterClass: public Ui_tomato_counterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOMATO_COUNTER_H
