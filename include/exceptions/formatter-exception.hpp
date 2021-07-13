#include<stdexcept>
#include<string>

#ifndef FORMATTER_EXCEPTION_H
#define FORMATTER_EXCEPTION_H

class FormatterException : public std::invalid_argument {
    public:
        FormatterException(const std::string message);
        ~FormatterException();
};

#endif