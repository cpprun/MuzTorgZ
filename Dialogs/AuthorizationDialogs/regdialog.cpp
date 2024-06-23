//
// Created by vladislav on 6/21/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RegDialog.h" resolved

#include "regdialog.h"

#include <qaction.h>
#include <QDebug>

#include "authorizationwin.h"
#include "dbmanager.h"
#include "Hashing.h"
#include "MuzMsgBox.h"
#include "ui_regdialog.h"


RegDialog::RegDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::RegDialog) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->regBtn, &QPushButton::clicked, this, &RegDialog::onRegBtnClicked);
}

void RegDialog::onRegBtnClicked() {
    QString login = ui->loginField->text();
    QString password = ui->passwordField->text();
    QString email = ui->emailField->text();
    if (login.isEmpty() || password.isEmpty() || email.isEmpty()) {
        MuzMsgBox::createMessageBox("Поля не должны быть пустыми!");
        return;
    }
    QString salt = QString::fromStdString(Hashing::generateSalt(16));
    QString hashedPassword = QString::fromStdString(Hashing::hashPassword(password.toStdString(), salt.toStdString()));
    dbmanager::regUser(login, hashedPassword, email, Roles::Guest, salt);

    AuthorizationWin* authorization_win = new AuthorizationWin(this);
    authorization_win->show();
    hide();
}

RegDialog::~RegDialog() {
    delete ui;
}
