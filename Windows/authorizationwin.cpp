//
// Created by vladislav on 21.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AuthorizationWin.h" resolved
#include <QString>
#include "authorizationwin.h"
#include "ui_authorizationwin.h"
#include "dbmanager.h"
#include "Hashing.h"
#include "MuzMsgBox.h"
#include "dbwindow.h"
#include "AuthorizationDialogs/regdialog.h"

AuthorizationWin::AuthorizationWin(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthorizationWin), dbWindow(nullptr), regDialog(nullptr) {
    ui->setupUi(this);
    ui->loginField->setFocusPolicy(Qt::ClickFocus);
    ui->passwordField->setFocusPolicy(Qt::ClickFocus);
}

void AuthorizationWin::on_enterBtn_clicked() {
    const QString login = ui->loginField->text();
    const QString password = ui->passwordField->text();
    dbmanager::authorizeUser(login);
    if (CurrentUser::role != Roles::None) {
        std::string hashedPassword = Hashing::hashPassword(password.toStdString(), CurrentUser::salt);
        if (hashedPassword == CurrentUser::password) {
            dbWindow = new DbWindow();
            dbWindow->show();
            hide();
        } else {
            MuzMsgBox::createMessageBox("Ошибка", "Пароль не совпадает!");
        }
    } else {
        MuzMsgBox::createMessageBox("Ошибка", "Пользователь не найден!");
    }
}


void AuthorizationWin::on_showPassword_stateChanged(const int arg1) const {
    if (arg1 == Qt::CheckState::Checked){
        ui->passwordField->setEchoMode(QLineEdit::EchoMode::Normal);
    } else {
        ui->passwordField->setEchoMode(QLineEdit::EchoMode::Password);
    }
}


void AuthorizationWin::on_regBtn_clicked() {
    regDialog = new RegDialog(this);
    regDialog->show();
}

AuthorizationWin::~AuthorizationWin() {
    dbmanager::closeDatabase();
    delete ui;
    delete regDialog;
    delete dbWindow;
}

void AuthorizationWin::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        on_enterBtn_clicked();
    }
}
