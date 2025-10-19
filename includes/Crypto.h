#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
class Crypto{
public:
    static std::string encrypt(std::string& text,int key);
    static std::string decrypt(std::string& text,int key);
        
};
#endif
