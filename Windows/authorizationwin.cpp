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
#include "regdialog.h"

AuthorizationWin::AuthorizationWin(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthorizationWin) {
    ui->setupUi(this);
}

void AuthorizationWin::on_enterBtn_clicked() {
    QString login = ui->loginField->text();
    QString password = ui->passwordField->text();
    dbmanager::authorizeUser(login);
    if (CurrentUser::role != Roles::None) {
        std::string hashedPassword = Hashing::hashPassword(password.toStdString(), CurrentUser::salt);
        std::cout << hashedPassword << std::endl;
        if (hashedPassword == CurrentUser::password) {
            DbWindow *dbWindow = new DbWindow(this);
            hide();
            dbWindow->show();
        } else {
            MuzMsgBox::createMessageBox("Пароль не совпадает!");
        }
    } else {
        MuzMsgBox::createMessageBox("Пользователь не найден!");
    }
}


void AuthorizationWin::on_showPassword_stateChanged(int arg1) {
}


void AuthorizationWin::on_regBtn_clicked() {
    RegDialog *reg_dialog = new RegDialog(this);
    reg_dialog->show();
    hide();
}

AuthorizationWin::~AuthorizationWin() {
    dbmanager::closeDatabase();
    delete ui;
}
