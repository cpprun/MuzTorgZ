//
// Created by vladislav on 6/21/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DbWindow.h" resolved

#include "dbwindow.h"

#include "CurrentUser.h"
#include "dbmanager.h"
#include "ui_dbwindow.h"

DbWindow::DbWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DbWindow), createUserDialog(nullptr), currentTable(nullptr) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("База данных");

    connect(ui->addDataBtn, &QPushButton::clicked, this, &DbWindow::onAddDataBtnClicked);
    connect(ui->changeDataBtn, &QPushButton::clicked, this, &DbWindow::onChangeDataBtnClicked);
    connect(ui->deleteDataBtn, &QPushButton::clicked, this, &DbWindow::onDeleteDataBtnClicked);

    tabMenu = addTab("Таблицы");
    if (CurrentUser::role == Roles::StAdmin){
        addMenuAction(stAdminTables);

    } else if (CurrentUser::role == Roles::Admin){
        addMenuAction(adminTables);
    } else if (CurrentUser::role == Roles::Guest) {
        addMenuAction(guestTables);
    }
}

void DbWindow::onActionTriggered() {
    currentTable = qobject_cast<QAction*>(sender());
    if (currentTable){
        if (currentTable->text() == "Users"){
            ui->tableView->setModel(dbmanager::getUsersTable());
            ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Suppliers"){
            ui->tableView->setModel(dbmanager::getSuppliersTable());
        } else if (currentTable->text() == "Roles"){
            ui->tableView->setModel(dbmanager::getRolesTable());
        } else if (currentTable->text() == "Reviews"){
            ui->tableView->setModel(dbmanager::getReviewsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Products"){
            ui->tableView->setModel(dbmanager::getProductsTable());
            ui->tableView->setItemDelegateForColumn(5, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "ProductSuppliers"){
            ui->tableView->setModel(dbmanager::getProductSuppliersTable());
            ui->tableView->setItemDelegateForColumn(0, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Payments"){
            ui->tableView->setModel(dbmanager::getPaymentsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Orders"){
            ui->tableView->setModel(dbmanager::getOrdersTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "OrderItems"){
            ui->tableView->setModel(dbmanager::getOrderItemsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Categories"){
            ui->tableView->setModel(dbmanager::getCategoriesTable());
        } else if (currentTable->text() == "Carts"){
            ui->tableView->setModel(dbmanager::getCartsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "CartItems"){
            ui->tableView->setModel(dbmanager::getCartItemsTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Addresses"){
            ui->tableView->setModel(dbmanager::getAddressesTable());
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        }
    }
}

void DbWindow::onAddDataBtnClicked() {
    if (currentTable) {
        if (currentTable->text() == "Users") {
            createUserDialog = new CreateUserDialog(this);
            createUserDialog->show();
        }
    }
}

void DbWindow::onDeleteDataBtnClicked() {
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
    delete currentTable;
    delete tabMenu;
    delete createUserDialog;
}
