//
// Created by vladislav on 6/21/24.
//

#include "CurrentUser.h"

std::string CurrentUser::login;
std::string CurrentUser::password;
std::string CurrentUser::email;
std::string CurrentUser::salt;
Roles CurrentUser::role = Roles::None;
