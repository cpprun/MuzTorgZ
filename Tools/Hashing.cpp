//
// Created by vladislav on 6/21/24.
//

#include "Hashing.h"

std::string Hashing::generateSalt(size_t length){
    unsigned char salt[length];
    if (!RAND_bytes(salt, length)) {
        throw std::runtime_error("Unable to generate random salt");
    }

    std::stringstream ss;
    for (size_t i = 0; i < length; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(salt[i]);
    }
    return ss.str();
}

std::string Hashing::hashPassword(const std::string& password, const std::string& salt){
    std::string saltedPassword = salt + password;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, saltedPassword.c_str(), saltedPassword.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();

}
