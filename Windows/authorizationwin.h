//
// Created by vladislav on 21.06.24.
//

#ifndef AUTHORIZATIONWIN_H
#define AUTHORIZATIONWIN_H

#include <iostream>
#include <QString>
#include "dbwindow.h"
#include "AuthorizationDialogs/regdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AuthorizationWin; }
QT_END_NAMESPACE

class AuthorizationWin : public QMainWindow {
Q_OBJECT

public:
    explicit AuthorizationWin(QWidget *parent = nullptr);
    ~AuthorizationWin() override;
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_enterBtn_clicked();

    void on_showPassword_stateChanged(int arg1) const;

    void on_regBtn_clicked();

private:
    Ui::AuthorizationWin *ui;
    RegDialog* regDialog;
    DbWindow* dbWindow;
};


#endif //AUTHORIZATIONWIN_H
