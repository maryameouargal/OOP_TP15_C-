#ifndef PILEVIDEEXCEPTION_HPP
#define PILEVIDEEXCEPTION_HPP

#include <exception>
#include <string>

// Exception personnalisee pour la pile vide
class PileVideException : public std::exception {
private:
    std::string message;
public:
    PileVideException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif