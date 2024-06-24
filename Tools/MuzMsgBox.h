//
// Created by vladislav on 6/21/24.
//

#ifndef MUZMSGBOX_H
#define MUZMSGBOX_H

#include <QMessageBox>

class MuzMsgBox {
public:
    static void createMessageBox(const QString& title, const QString& message){
        QMessageBox msgBox;
        msgBox.setWindowTitle(title);
        msgBox.setText(message);
        msgBox.exec();
    }
};



#endif //MUZMSGBOX_H
