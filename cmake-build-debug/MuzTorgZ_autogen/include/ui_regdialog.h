/********************************************************************************
** Form generated from reading UI file 'regdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGDIALOG_H
#define UI_REGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegDialog
{
public:
    QGridLayout *gridLayout_2;
    QLineEdit *loginField;
    QLineEdit *emailField;
    QLineEdit *passwordField;
    QPushButton *regBtn;

    void setupUi(QDialog *RegDialog)
    {
        if (RegDialog->objectName().isEmpty())
            RegDialog->setObjectName(QString::fromUtf8("RegDialog"));
        RegDialog->resize(400, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegDialog->sizePolicy().hasHeightForWidth());
        RegDialog->setSizePolicy(sizePolicy);
        RegDialog->setMinimumSize(QSize(400, 200));
        RegDialog->setMaximumSize(QSize(400, 200));
        gridLayout_2 = new QGridLayout(RegDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        loginField = new QLineEdit(RegDialog);
        loginField->setObjectName(QString::fromUtf8("loginField"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loginField->sizePolicy().hasHeightForWidth());
        loginField->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(loginField, 0, 0, 1, 1);

        emailField = new QLineEdit(RegDialog);
        emailField->setObjectName(QString::fromUtf8("emailField"));
        sizePolicy1.setHeightForWidth(emailField->sizePolicy().hasHeightForWidth());
        emailField->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(emailField, 2, 0, 1, 1);

        passwordField = new QLineEdit(RegDialog);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        sizePolicy1.setHeightForWidth(passwordField->sizePolicy().hasHeightForWidth());
        passwordField->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(passwordField, 1, 0, 1, 1);

        regBtn = new QPushButton(RegDialog);
        regBtn->setObjectName(QString::fromUtf8("regBtn"));

        gridLayout_2->addWidget(regBtn, 3, 0, 1, 1);


        retranslateUi(RegDialog);

        QMetaObject::connectSlotsByName(RegDialog);
    } // setupUi

    void retranslateUi(QDialog *RegDialog)
    {
        RegDialog->setWindowTitle(QCoreApplication::translate("RegDialog", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginField->setPlaceholderText(QCoreApplication::translate("RegDialog", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        emailField->setPlaceholderText(QCoreApplication::translate("RegDialog", "\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\260\321\217 \320\277\320\276\321\207\321\202\320\260", nullptr));
        passwordField->setPlaceholderText(QCoreApplication::translate("RegDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        regBtn->setText(QCoreApplication::translate("RegDialog", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegDialog: public Ui_RegDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGDIALOG_H
