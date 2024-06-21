#include <QApplication>
#include <QPushButton>
#include "authorizationwin.h"
#include "dbmanager.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    dbmanager::connectToDatabase();

    AuthorizationWin w;
    w.setWindowTitle("Страница авторизации");
    w.show();
    return QApplication::exec();
}
