//
// Created by vladislav on 6/21/24.
//

#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class RegDialog; }
QT_END_NAMESPACE

class RegDialog : public QDialog {
Q_OBJECT

public:
    explicit RegDialog(QWidget *parent = nullptr);
    ~RegDialog() override;
private slots:
    void onRegBtnClicked();
private:
    Ui::RegDialog *ui;
};


#endif //REGDIALOG_H
