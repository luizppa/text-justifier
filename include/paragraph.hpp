#include<string>

#include"./formatters/formatter.hpp"

#ifndef PARAGRAPH_H
#define PARAGRAPH_H

class Paragraph {

    private:
        std::string input;

    public:
        Paragraph(const std::string& input);
        ~Paragraph();

        void render(IFormatter* formatter);

};

#endif