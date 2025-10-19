#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
class FileHandler{
public:
    static std::string readFile(const std::string& filename);
    static void fileSave(const std::string& filename,std::string& content);    
};
#endif
