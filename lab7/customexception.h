#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H
#include <iostream>
#include <exception>

class CustomException : public std::exception {
public:
    CustomException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

#endif // CUSTOMEXCEPTION_H
