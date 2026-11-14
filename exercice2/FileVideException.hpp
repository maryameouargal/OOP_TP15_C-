#ifndef FILEVIDEEXCEPTION_HPP
#define FILEVIDEEXCEPTION_HPP

#include <exception>
#include <string>

// Exception personnalisee pour la file vide
class FileVideException : public std::exception {
private:
    std::string message;
public:
    FileVideException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif