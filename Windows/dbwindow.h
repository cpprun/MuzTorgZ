//
// Created by vladislav on 6/21/24.
//

#ifndef DBWINDOW_H
#define DBWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QKeyEvent>
#include <QSqlRelationalTableModel>


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
        void onSubmitBtnClicked();
protected:
    void keyPressEvent(QKeyEvent* event) override;
private:
    bool addBtnMode = false;
    Ui::DbWindow *ui;
    QAction* currentTable;
    QMenu* tabMenu;
    QMenu* addTab(QString tabName);
    QSqlRelationalTableModel* model;
    void addMenuAction(std::vector<QString> array);
    void updateTable();
    bool isRowEmpty(const int row) const;

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
                                         "OrderItems",
                                         "Orders",
                                         "Payments",
                                         "Products",
                                         "Reviews",

    };

    std::vector<QString> guestTables{"CartItems",
                                         "Carts",
                                         "OrderItems",
                                         "Orders",
                                         "Products",
                                         "Reviews",

    };
};



#endif //DBWINDOW_H
