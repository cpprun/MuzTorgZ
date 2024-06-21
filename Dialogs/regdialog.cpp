//
// Created by vladislav on 6/21/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RegDialog.h" resolved

#include "regdialog.h"

#include <qaction.h>
#include <QDebug>

#include "ui_regdialog.h"


RegDialog::RegDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::RegDialog) {
    ui->setupUi(this);
    connect(ui->regBtn, &QPushButton::clicked, this, &RegDialog::onRegBtnClicked);
}

void RegDialog::onRegBtnClicked() {
    qDebug() << "ХУц";
}

RegDialog::~RegDialog() {
    delete ui;
}
