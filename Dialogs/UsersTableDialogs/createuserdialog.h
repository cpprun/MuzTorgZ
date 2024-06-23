//
// Created by vladislav on 6/22/24.
//

#ifndef CREATEUSERDIALOG_H
#define CREATEUSERDIALOG_H

#include <QDialog>
#include <QSqlRelationalTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class CreateUserDialog; }
QT_END_NAMESPACE

class CreateUserDialog : public QDialog {
Q_OBJECT

public:
    explicit CreateUserDialog(QWidget *parent = nullptr);
    ~CreateUserDialog() override;
private slots:
    void onAddBtnClicked();
private:
    Ui::CreateUserDialog *ui;
    QSqlRelationalTableModel* model;
};


#endif //CREATEUSERDIALOG_H
