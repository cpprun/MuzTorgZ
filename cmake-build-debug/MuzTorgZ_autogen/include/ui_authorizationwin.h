/********************************************************************************
** Form generated from reading UI file 'authorizationwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATIONWIN_H
#define UI_AUTHORIZATIONWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorizationWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *grid;
    QLabel *label;
    QLineEdit *loginField;
    QLabel *label_2;
    QLineEdit *passwordField;
    QCheckBox *showPassword;
    QPushButton *enterBtn;
    QPushButton *regBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AuthorizationWin)
    {
        if (AuthorizationWin->objectName().isEmpty())
            AuthorizationWin->setObjectName(QString::fromUtf8("AuthorizationWin"));
        AuthorizationWin->resize(400, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthorizationWin->sizePolicy().hasHeightForWidth());
        AuthorizationWin->setSizePolicy(sizePolicy);
        AuthorizationWin->setMinimumSize(QSize(400, 200));
        AuthorizationWin->setMaximumSize(QSize(400, 200));
        centralwidget = new QWidget(AuthorizationWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        grid->addWidget(label, 1, 0, 1, 1);

        loginField = new QLineEdit(centralwidget);
        loginField->setObjectName(QString::fromUtf8("loginField"));

        grid->addWidget(loginField, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        grid->addWidget(label_2, 2, 0, 1, 1);

        passwordField = new QLineEdit(centralwidget);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        passwordField->setEchoMode(QLineEdit::Password);

        grid->addWidget(passwordField, 2, 1, 1, 1);

        showPassword = new QCheckBox(centralwidget);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));

        grid->addWidget(showPassword, 2, 2, 1, 1);


        gridLayout->addLayout(grid, 0, 0, 1, 1);

        enterBtn = new QPushButton(centralwidget);
        enterBtn->setObjectName(QString::fromUtf8("enterBtn"));

        gridLayout->addWidget(enterBtn, 1, 0, 1, 1);

        regBtn = new QPushButton(centralwidget);
        regBtn->setObjectName(QString::fromUtf8("regBtn"));

        gridLayout->addWidget(regBtn, 2, 0, 1, 1);

        AuthorizationWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AuthorizationWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 24));
        AuthorizationWin->setMenuBar(menubar);
        statusbar = new QStatusBar(AuthorizationWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AuthorizationWin->setStatusBar(statusbar);

        retranslateUi(AuthorizationWin);

        QMetaObject::connectSlotsByName(AuthorizationWin);
    } // setupUi

    void retranslateUi(QMainWindow *AuthorizationWin)
    {
        AuthorizationWin->setWindowTitle(QCoreApplication::translate("AuthorizationWin", "AuthorizationWin", nullptr));
        label->setText(QCoreApplication::translate("AuthorizationWin", "\320\233\320\276\320\263\320\270\320\275: ", nullptr));
        label_2->setText(QCoreApplication::translate("AuthorizationWin", "\320\237\320\260\321\200\320\276\320\273\321\214: ", nullptr));
        showPassword->setText(QCoreApplication::translate("AuthorizationWin", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        enterBtn->setText(QCoreApplication::translate("AuthorizationWin", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        regBtn->setText(QCoreApplication::translate("AuthorizationWin", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorizationWin: public Ui_AuthorizationWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATIONWIN_H
