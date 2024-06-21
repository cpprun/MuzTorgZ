//
// Created by vladislav on 6/21/24.
//

#ifndef CURRENTUSER_H
#define CURRENTUSER_H
#include <string>
#include "Roles.h"

class CurrentUser {
public:
    static std::string login;
    static std::string password;
    static std::string email;
    static std::string salt;
    static Roles role;
};



#endif //CURRENTUSER_H
