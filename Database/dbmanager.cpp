#include "dbmanager.h"

#include <iostream>

#include "MuzMsgBox.h"

QSqlDatabase dbmanager::db = QSqlDatabase::addDatabase("QMYSQL");

void dbmanager::connectToDatabase() {
    db.setHostName("localhost");
    db.setDatabaseName("muztorgdb");
    db.setUserName("root");
    db.setPassword("Berkut281706");

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
        return;
    }

    qDebug() << "Успешное подключение к базе данных";

}

void dbmanager::closeDatabase() {
    db.close();
}

void dbmanager::authorizeUser(const QString& login){
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();
    query.prepare("SELECT * FROM Users WHERE username = :login");
    query.bindValue(":login", login);
    if (!query.exec()){
        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
        return;
    }
    model->setQuery(query);
    std::cout << model->index(0, 0).data().toString().toStdString();
    //CurrentUser user;
    CurrentUser::login = model->index(0, 1).data().toString().toStdString();
    CurrentUser::password = model->index(0, 2).data().toString().toStdString();
    CurrentUser::salt = model->index(0, 6).data().toString().toStdString();
    CurrentUser::role = Roles(model->index(0, 4).data().toInt());
}

void dbmanager::regUser(const QString &login, const QString &password, const QString &email, Roles role,
    const QString &salt) {
    QSqlQuery query;
    query.prepare("INSERT INTO Users(username, password, email, salt, role_id) VALUES (:login, :password, :email, :salt, :role_id)");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":salt", salt);
    query.bindValue(":role_id", static_cast<int>(role));

    if (!query.exec()) {
        MuzMsgBox::createMessageBox("Ошибка регистрации!\n" + query.lastError().text());
        return;
    }
    MuzMsgBox::createMessageBox("Пользователь успешно зарегистрирован!");
}

QSqlQueryModel* dbmanager::getTablesName(){
    QSqlQueryModel* model(new QSqlQueryModel());
    model->setQuery(executeQuery("SHOW TABLES;"));

    return model;
}

QSqlRelationalTableModel* dbmanager::getUsersTable(){
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    model->setTable("Users");
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setRelation(4, QSqlRelation("Roles", "role_id", "role_name"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getRolesTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Roles");
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getAddressesTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Addresses");
    model->setRelation(1, QSqlRelation("Users", "user_id", "username"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getCategoriesTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Categories");
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getProductsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Products");
    model->setRelation(5, QSqlRelation("Categories", "category_id", "category_name"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getSuppliersTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Suppliers");
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getProductSuppliersTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("ProductSuppliers");
    model->setRelation(0, QSqlRelation("Products", "product_id", "product_name"));
    model->setRelation(1, QSqlRelation("Suppliers", "supplier_id", "supplier_name"));
    model->select();


    return model;
}

QSqlRelationalTableModel* dbmanager::getReviewsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Reviews");
    model->setRelation(1, QSqlRelation("Users", "user_id", "username"));
    model->setRelation(2, QSqlRelation("Products", "product_id", "product_name"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getPaymentsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Payments");
    model->setRelation(1, QSqlRelation("Orders", "order_id", "order_id"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getOrdersTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Orders");
    model->setRelation(1, QSqlRelation("Users", "user_id", "username"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getOrderItemsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("OrderItems");
    model->setRelation(1, QSqlRelation("Orders", "order_id", "order_id"));
    model->setRelation(2, QSqlRelation("Products", "product_id", "product_name"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getCartsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("Carts");
    model->setRelation(1, QSqlRelation("Users", "user_id", "username"));
    model->select();

    return model;
}

QSqlRelationalTableModel* dbmanager::getCartItemsTable(){
    QSqlRelationalTableModel* model(new QSqlRelationalTableModel());
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->setTable("CartItems");
    model->setRelation(1, QSqlRelation("Carts", "cart_id", "cart_id"));
    model->setRelation(2, QSqlRelation("Products", "product_id", "product_name"));
    model->select();

    return model;
}

QSqlQuery dbmanager::executeQuery(const QString &queryStr) {
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
    }
    return query;
}
