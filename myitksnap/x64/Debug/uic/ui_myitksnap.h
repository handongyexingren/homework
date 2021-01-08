/********************************************************************************
** Form generated from reading UI file 'myitksnap.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYITKSNAP_H
#define UI_MYITKSNAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_myitksnapClass
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *action3D;
    QAction *actionThreshold;
    QAction *actionRegionGrowing;
    QAction *actionWindow;
    QWidget *centralWidget;
    QVTKWidget *qvw1;
    QVTKWidget *qvw2;
    QVTKWidget *qvw3;
    QVTKWidget *qvw4;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label11;
    QLabel *label22;
    QLabel *label33;
    QLabel *label44;
    QMenuBar *menuBar;
    QMenu *menuFiles;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myitksnapClass)
    {
        if (myitksnapClass->objectName().isEmpty())
            myitksnapClass->setObjectName(QString::fromUtf8("myitksnapClass"));
        myitksnapClass->resize(812, 870);
        actionOpen = new QAction(myitksnapClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(myitksnapClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        action3D = new QAction(myitksnapClass);
        action3D->setObjectName(QString::fromUtf8("action3D"));
        actionThreshold = new QAction(myitksnapClass);
        actionThreshold->setObjectName(QString::fromUtf8("actionThreshold"));
        actionRegionGrowing = new QAction(myitksnapClass);
        actionRegionGrowing->setObjectName(QString::fromUtf8("actionRegionGrowing"));
        actionWindow = new QAction(myitksnapClass);
        actionWindow->setObjectName(QString::fromUtf8("actionWindow"));
        centralWidget = new QWidget(myitksnapClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qvw1 = new QVTKWidget(centralWidget);
        qvw1->setObjectName(QString::fromUtf8("qvw1"));
        qvw1->setGeometry(QRect(0, 0, 391, 381));
        qvw1->setMouseTracking(true);
        qvw1->setTabletTracking(true);
        qvw1->setAutoFillBackground(false);
        qvw2 = new QVTKWidget(centralWidget);
        qvw2->setObjectName(QString::fromUtf8("qvw2"));
        qvw2->setGeometry(QRect(420, 0, 391, 381));
        qvw2->setMouseTracking(true);
        qvw2->setTabletTracking(true);
        qvw2->setAutoFillBackground(false);
        qvw3 = new QVTKWidget(centralWidget);
        qvw3->setObjectName(QString::fromUtf8("qvw3"));
        qvw3->setGeometry(QRect(0, 420, 391, 381));
        qvw3->setMouseTracking(true);
        qvw3->setTabletTracking(true);
        qvw3->setAutoFillBackground(false);
        qvw4 = new QVTKWidget(centralWidget);
        qvw4->setObjectName(QString::fromUtf8("qvw4"));
        qvw4->setGeometry(QRect(420, 420, 391, 381));
        qvw4->setMouseTracking(true);
        qvw4->setTabletTracking(true);
        qvw4->setAutoFillBackground(false);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(300, 380, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        label1->setFont(font);
        label1->setLayoutDirection(Qt::RightToLeft);
        label1->setFrameShape(QFrame::NoFrame);
        label1->setFrameShadow(QFrame::Plain);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(720, 380, 81, 31));
        label2->setFont(font);
        label2->setLayoutDirection(Qt::RightToLeft);
        label2->setFrameShape(QFrame::NoFrame);
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(300, 800, 81, 31));
        label3->setFont(font);
        label3->setLayoutDirection(Qt::RightToLeft);
        label3->setFrameShape(QFrame::NoFrame);
        label4 = new QLabel(centralWidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(710, 800, 91, 31));
        label4->setFont(font);
        label4->setLayoutDirection(Qt::RightToLeft);
        label4->setFrameShape(QFrame::NoFrame);
        label11 = new QLabel(centralWidget);
        label11->setObjectName(QString::fromUtf8("label11"));
        label11->setGeometry(QRect(60, 380, 211, 31));
        label11->setFont(font);
        label11->setLayoutDirection(Qt::RightToLeft);
        label11->setFrameShape(QFrame::NoFrame);
        label11->setFrameShadow(QFrame::Plain);
        label22 = new QLabel(centralWidget);
        label22->setObjectName(QString::fromUtf8("label22"));
        label22->setGeometry(QRect(480, 380, 211, 31));
        label22->setFont(font);
        label22->setLayoutDirection(Qt::RightToLeft);
        label22->setFrameShape(QFrame::NoFrame);
        label22->setFrameShadow(QFrame::Plain);
        label33 = new QLabel(centralWidget);
        label33->setObjectName(QString::fromUtf8("label33"));
        label33->setGeometry(QRect(60, 800, 211, 31));
        label33->setFont(font);
        label33->setLayoutDirection(Qt::RightToLeft);
        label33->setFrameShape(QFrame::NoFrame);
        label33->setFrameShadow(QFrame::Plain);
        label44 = new QLabel(centralWidget);
        label44->setObjectName(QString::fromUtf8("label44"));
        label44->setGeometry(QRect(480, 800, 211, 31));
        label44->setFont(font);
        label44->setLayoutDirection(Qt::RightToLeft);
        label44->setFrameShape(QFrame::NoFrame);
        label44->setFrameShadow(QFrame::Plain);
        myitksnapClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(myitksnapClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 812, 23));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        myitksnapClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(myitksnapClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        myitksnapClass->setStatusBar(statusBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFiles->addAction(actionOpen);
        menuFiles->addAction(action3D);
        menuFiles->addSeparator();
        menuFiles->addAction(actionClose);
        menuEdit->addAction(actionWindow);
        menuEdit->addAction(actionThreshold);
        menuEdit->addAction(actionRegionGrowing);

        retranslateUi(myitksnapClass);

        QMetaObject::connectSlotsByName(myitksnapClass);
    } // setupUi

    void retranslateUi(QMainWindow *myitksnapClass)
    {
        myitksnapClass->setWindowTitle(QApplication::translate("myitksnapClass", "myitksnap", nullptr));
        actionOpen->setText(QApplication::translate("myitksnapClass", "\346\211\223\345\274\200", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("myitksnapClass", "\346\211\223\345\274\200", nullptr));
#endif // QT_NO_TOOLTIP
        actionClose->setText(QApplication::translate("myitksnapClass", "\345\205\263\351\227\255", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("myitksnapClass", "\345\205\263\351\227\255", nullptr));
#endif // QT_NO_TOOLTIP
        action3D->setText(QApplication::translate("myitksnapClass", "3D\346\230\276\347\244\272", nullptr));
#ifndef QT_NO_TOOLTIP
        action3D->setToolTip(QApplication::translate("myitksnapClass", "3D\346\230\276\347\244\272", nullptr));
#endif // QT_NO_TOOLTIP
        actionThreshold->setText(QApplication::translate("myitksnapClass", "\351\230\210\345\200\274\345\210\206\345\211\262", nullptr));
#ifndef QT_NO_TOOLTIP
        actionThreshold->setToolTip(QApplication::translate("myitksnapClass", "\351\230\210\345\200\274\345\210\206\345\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        actionRegionGrowing->setText(QApplication::translate("myitksnapClass", "\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRegionGrowing->setToolTip(QApplication::translate("myitksnapClass", "\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
#endif // QT_NO_TOOLTIP
        actionWindow->setText(QApplication::translate("myitksnapClass", "\347\252\227\345\256\275\347\252\227\344\275\215", nullptr));
#ifndef QT_NO_TOOLTIP
        actionWindow->setToolTip(QApplication::translate("myitksnapClass", "\347\252\227\345\256\275\347\252\227\344\275\215", nullptr));
#endif // QT_NO_TOOLTIP
        label1->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
        label11->setText(QString());
        label22->setText(QString());
        label33->setText(QString());
        label44->setText(QString());
        menuFiles->setTitle(QApplication::translate("myitksnapClass", "Files", nullptr));
        menuEdit->setTitle(QApplication::translate("myitksnapClass", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myitksnapClass: public Ui_myitksnapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYITKSNAP_H
