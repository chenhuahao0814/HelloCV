#include "../includes/Crypto.h"
#include <string>
using namespace std;
string Crypto::encrypt(string& text,int key){
    string result = text;    
for(size_t i=0;i<result.length();i++){        
if(isalpha(result[i])){
            char base=islower(result[i])?'a':'A';
            result[i]=base+((result[i]-base)+key)%26;
        }
    }
    return result;
}
string Crypto::decrypt(string& text,int key){
    string result = text;    
for(size_t i=0;i<result.length();i++){        
if(isalpha(result[i])){
            char base=islower(result[i])?'a':'A';
            result[i]=base+((result[i]-base)-key)%26;
        }
    }
    return result;
}
