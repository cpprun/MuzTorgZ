//
// Created by vladislav on 6/21/24.
//

#ifndef DBWINDOW_H
#define DBWINDOW_H

#include <QMainWindow>
#include <QAction>
#include "UsersTableDialogs/createuserdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DbWindow; }
QT_END_NAMESPACE

class DbWindow : public QMainWindow {
Q_OBJECT

public:
    explicit DbWindow(QWidget *parent = nullptr);
    ~DbWindow() override;
private slots:
        void onActionTriggered();
        void onAddDataBtnClicked();
        void onDeleteDataBtnClicked();
private:
    Ui::DbWindow *ui;
    CreateUserDialog* createUserDialog;
    QAction* currentTable;
    QMenu* tabMenu;
    QMenu* addTab(QString tabName);
    void addMenuAction(std::vector<QString> array);

    std::vector<QString> stAdminTables{"Addresses",
                                           "CartItems",
                                           "Carts",
                                           "Categories",
                                           "OrderItems",
                                           "Orders",
                                           "Payments",
                                           "ProductSuppliers",
                                           "Products",
                                           "Reviews",
                                           "Roles",
                                           "Suppliers",
                                           "Users"};

    std::vector<QString> adminTables{"Addresses",
                                         "CartItems",
                                         "Carts",
                                         "Categories",
                                         "OrderItems",
                                         "Orders",
                                         "Payments",
                                         "ProductSuppliers",
                                         "Products",
                                         "Reviews",
                                         "Roles",
                                         "Suppliers"

    };

    std::vector<QString> guestTables{"Addresses",
                                         "CartItems",
                                         "Carts",
                                         "Categories",
                                         "OrderItems",
                                         "Orders",
                                         "Payments",
                                         "Products",
                                         "Reviews",

    };
};


#endif //DBWINDOW_H
