#include"./formatter.hpp"

#ifndef JUSTIFY_FORMATTER_H
#define JUSTIFY_FORMATTER_H

class JustifyFormatter : public IFormatter {
    private:
        char fillChar = ' ';
        int lineLength = 32;

    public:
        JustifyFormatter();
        JustifyFormatter(char fillChar, int lineLength);
        ~JustifyFormatter();
        std::string align(const std::string& input) override;
};

#endif