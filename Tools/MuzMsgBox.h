//
// Created by vladislav on 6/21/24.
//

#ifndef MUZMSGBOX_H
#define MUZMSGBOX_H

#include <QMessageBox>

class MuzMsgBox {
public:
    static void createMessageBox(const char* message){
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.exec();
    }
};



#endif //MUZMSGBOX_H
