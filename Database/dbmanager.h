#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlRelationalDelegate>
#include "../Models/CurrentUser.h"
#include "Roles.h"

class dbmanager
{
private:
    static QSqlDatabase db;
public:
    static void connectToDatabase();
    static void closeDatabase();

    static void authorizeUser(QString& login);

    static QSqlQueryModel* getTablesName();

    static QSqlRelationalTableModel* getUsersTable();

    static QSqlRelationalTableModel* getRolesTable();

    static QSqlRelationalTableModel* getAddressesTable();

    static QSqlRelationalTableModel* getCategoriesTable();

    static QSqlRelationalTableModel* getProductsTable();

    static QSqlRelationalTableModel* getSuppliersTable();

    static QSqlRelationalTableModel* getProductSuppliersTable();

    static QSqlRelationalTableModel* getPaymentsTable();

    static QSqlRelationalTableModel* getReviewsTable();

    static QSqlRelationalTableModel* getOrdersTable();

    static QSqlRelationalTableModel* getOrderItemsTable();

    static QSqlRelationalTableModel* getCartsTable();

    static QSqlRelationalTableModel* getCartItemsTable();

    static QSqlQuery executeQuery(const QString &queryStr);
};


#endif // DBMANAGER_H
