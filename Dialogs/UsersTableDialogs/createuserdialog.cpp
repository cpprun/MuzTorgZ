//
// Created by vladislav on 6/22/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateUserDialog.h" resolved
#include <QSqlRecord>
#include <QDebug>
#include "createuserdialog.h"
#include "dbmanager.h"
#include "Hashing.h"
#include "MuzMsgBox.h"
#include "ui_createuserdialog.h"

CreateUserDialog::CreateUserDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::CreateUserDialog), model(nullptr) {
    ui->setupUi(this);
    setWindowTitle("Добавление пользователя");
    setAttribute(Qt::WA_DeleteOnClose);
    model = dbmanager::getRolesTable();
    if (model) {
        ui->roleComboBox->setModel(model);
        ui->roleComboBox->setModelColumn(model->fieldIndex("role_name"));
    }

    connect(ui->addUserBtn, &QPushButton::clicked, this, &CreateUserDialog::onAddBtnClicked);
}

CreateUserDialog::~CreateUserDialog() {
    delete ui;
}

void CreateUserDialog::onAddBtnClicked() {
    QString login = ui->loginField->text();
    QString password = ui->passwordField->text();
    QString email = ui->emailField->text();
    if (login.isEmpty() || password.isEmpty() || email.isEmpty()) {
        MuzMsgBox::createMessageBox("Поля не должны быть пустыми!");
    } else {
        const QString salt = QString::fromStdString(Hashing::generateSalt(16));
        const QString hashedPassword = QString::fromStdString(Hashing::hashPassword(password.toStdString(), salt.toStdString()));
        const int currentIndex = ui->roleComboBox->currentIndex();
        const int roleId = model->record(currentIndex).value("role_id").toInt();
        dbmanager::regUser(login, hashedPassword, email, static_cast<Roles>(roleId), salt);
        close();
    }
}
