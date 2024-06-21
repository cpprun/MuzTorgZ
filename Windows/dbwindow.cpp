//
// Created by vladislav on 6/21/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DbWindow.h" resolved

#include "dbwindow.h"

#include "CurrentUser.h"
#include "dbmanager.h"
#include "ui_dbwindow.h"


DbWindow::DbWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DbWindow) {
    ui->setupUi(this);
    tabMenu = addTab("Таблицы");
    if (CurrentUser::role == Roles::StAdmin){
        addMenuAction(stAdminTables);

    }
    else if (CurrentUser::role == Roles::Admin){
        addMenuAction(adminTables);
    }
}

void DbWindow::onActionTriggered(){
    QAction* action = qobject_cast<QAction*>(sender());
    if (action){
        if (action->text() == "Users"){
            ui->tableView->setModel(dbmanager::getUsersTable());
            ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Suppliers"){
            ui->tableView->setModel(dbmanager::getSuppliersTable());
        } else if (action->text() == "Roles"){
            ui->tableView->setModel(dbmanager::getRolesTable());
        } else if (action->text() == "Reviews"){
            ui->tableView->setModel(dbmanager::getReviewsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Products"){
            ui->tableView->setModel(dbmanager::getProductsTable());
            ui->tableView->setItemDelegateForColumn(5, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "ProductSuppliers"){
            ui->tableView->setModel(dbmanager::getProductSuppliersTable());
            ui->tableView->setItemDelegateForColumn(0, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Payments"){
            ui->tableView->setModel(dbmanager::getPaymentsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Orders"){
            ui->tableView->setModel(dbmanager::getOrdersTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "OrderItems"){
            ui->tableView->setModel(dbmanager::getOrderItemsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Categories"){
            ui->tableView->setModel(dbmanager::getCategoriesTable());
        } else if (action->text() == "Carts"){
            ui->tableView->setModel(dbmanager::getCartsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "CartItems"){
            ui->tableView->setModel(dbmanager::getCartItemsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (action->text() == "Addresses"){
            ui->tableView->setModel(dbmanager::getAddressesTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        }
    }
}


QMenu* DbWindow::addTab(QString tabName){
    return ui->menubar->addMenu(tabName);
}

void DbWindow::addMenuAction(std::vector<QString> array){
    tabMenu->clear();
    for (size_t x = 0; x < array.size(); x++){
        QAction* action = tabMenu->addAction(array.at(x));
        connect(action, &QAction::triggered, this, &DbWindow::onActionTriggered);
    }
}

DbWindow::~DbWindow() {
    delete ui;
}
