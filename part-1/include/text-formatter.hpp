#include<string>

#ifndef TEXT_FORMATTER_H
#define TEXT_FORMATER_H

class TextFormatter {

    private:
        char fillChar = ' ';

    public:
        TextFormatter();
        TextFormatter(char fillChar);
        ~TextFormatter();
        void setFillChar(char fillChar) { this->fillChar = fillChar; }
        std::string justifyParagraph(const std::string& input, int targetLength);

};

#endif