//
// Created by vladislav on 6/21/24.
//

#ifndef HASHING_H
#define HASHING_H
#include <string>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <iostream>
#include <iomanip>
#include <sstream>

class Hashing {
public:
    static std::string generateSalt(size_t legth);
    static std::string hashPassword(const std::string& password, const std::string& salt);
};



#endif //HASHING_H
