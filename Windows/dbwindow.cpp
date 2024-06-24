//
// Created by vladislav on 6/21/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DbWindow.h" resolved

#include "dbwindow.h"

#include <QSqlRecord>

#include "CurrentUser.h"
#include "dbmanager.h"
#include "MuzMsgBox.h"
#include "ui_dbwindow.h"

DbWindow::DbWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DbWindow), createUserDialog(nullptr), currentTable(nullptr), model(nullptr) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("База данных");

    connect(ui->addDataBtn, &QPushButton::clicked, this, &DbWindow::onAddDataBtnClicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &DbWindow::onSubmitBtnClicked);
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
            model = dbmanager::getUsersTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Suppliers"){
            model = dbmanager::getSuppliersTable();
            ui->tableView->setModel(model);
        } else if (currentTable->text() == "Roles"){
            model = dbmanager::getRolesTable();
            ui->tableView->setModel(model);
        } else if (currentTable->text() == "Reviews"){
            model = dbmanager::getReviewsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Products"){
            model = dbmanager::getProductsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(5, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "ProductSuppliers"){
            model = dbmanager::getProductSuppliersTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(0, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Payments"){
            model = dbmanager::getPaymentsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Orders"){
            model = dbmanager::getOrdersTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "OrderItems"){
            model = dbmanager::getOrderItemsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Categories"){
            model = dbmanager::getCategoriesTable();
            ui->tableView->setModel(model);
        } else if (currentTable->text() == "Carts"){
            model = dbmanager::getCartsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "CartItems"){
            model = dbmanager::getCartItemsTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
            ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate(ui->tableView));
        } else if (currentTable->text() == "Addresses"){
            model = dbmanager::getAddressesTable();
            ui->tableView->setModel(model);
            ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate(ui->tableView));
        }
    }
}

void DbWindow::onAddDataBtnClicked() {
    if (currentTable) {
        if (!addBtnMode) {
            int rowCount = model->rowCount();
            model->insertRow(rowCount);
            QModelIndex index = model->index(rowCount, 0);
            ui->tableView->setCurrentIndex(index);
            ui->tableView->edit(index);
            ui->addDataBtn->setText("Отменить");
            addBtnMode = true;
        } else if (addBtnMode) {
            ui->addDataBtn->setText("Добавить");
            model->removeRow(model->rowCount() - 1);
            addBtnMode = false;
        }
    }
}

void DbWindow::onDeleteDataBtnClicked() {
    if (currentTable) {
        if(ui->tableView->selectionModel()->hasSelection()) {
            ui->tableView->model()->removeRow(ui->tableView->currentIndex().row());
            if(!ui->tableView->model()->submit()) {
                MuzMsgBox::createMessageBox("Ошибка SQL", model->lastError().text());
            } else {
                updateTable();
            }
        }
    }
}

bool DbWindow::isRowEmpty(const int row) const {
    QSqlRecord record = model->record(row);
    for (int col = 0; col < record.count(); ++col) {
        QVariant value = record.value(col);
        if (value.isNull() && value.toString().trimmed().isEmpty()) {
            return true; // Нашли непустое значение
        }
    }
    return false;
}

void DbWindow::onSubmitBtnClicked() {
    if (currentTable) {
        if(isRowEmpty(model->rowCount() - 1)) {
            MuzMsgBox::createMessageBox("Ошибка", "Заполните все поля!");
        } else {
            if(!ui->tableView->model()->submit()) {
                MuzMsgBox::createMessageBox("Ошибка SQL", model->lastError().text());
            } else {
                updateTable();
            }
        }
    }
}


QMenu* DbWindow::addTab(QString tabName){
    return ui->menubar->addMenu(tabName);
}

void DbWindow::addMenuAction(std::vector<QString> array){
    tabMenu->clear();
    for (const auto & x : array){
        QAction* action = tabMenu->addAction(x);
        connect(action, &QAction::triggered, this, &DbWindow::onActionTriggered);
    }
}

void DbWindow::updateTable() {
    model->select();
    ui->tableView->setModel(model);
}

void DbWindow::keyPressEvent(QKeyEvent *event) {
    if( event->key() == Qt::Key_Delete )
    {
        if(ui->tableView->selectionModel()->hasSelection()) {
            ui->tableView->model()->removeRow(ui->tableView->currentIndex().row());
            ui->tableView->model()->submit();
            updateTable();
        }
    }
}

DbWindow::~DbWindow() {
    delete ui;
    delete currentTable;
    delete tabMenu;
    delete createUserDialog;
    delete model;
}
