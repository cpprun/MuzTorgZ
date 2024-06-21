/********************************************************************************
** Form generated from reading UI file 'dbwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWINDOW_H
#define UI_DBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DbWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DbWindow)
    {
        if (DbWindow->objectName().isEmpty())
            DbWindow->setObjectName(QString::fromUtf8("DbWindow"));
        DbWindow->resize(400, 300);
        centralwidget = new QWidget(DbWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        DbWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DbWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 24));
        DbWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DbWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DbWindow->setStatusBar(statusbar);

        retranslateUi(DbWindow);

        QMetaObject::connectSlotsByName(DbWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DbWindow)
    {
        DbWindow->setWindowTitle(QCoreApplication::translate("DbWindow", "DbWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DbWindow: public Ui_DbWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWINDOW_H
