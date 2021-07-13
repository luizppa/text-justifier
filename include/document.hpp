#include<vector>
#include<sstream>
#include<string>

#include"./paragraph.hpp"
#include"./formatters/formatter.hpp"

#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document {

    private:
        std::vector<Paragraph> paragraphs;
        IFormatter* formatter;
        void read(std::stringstream& inputStream);

    public:
        Document(const std::string& input, IFormatter* formatter);
        ~Document();

        void render();

};

#endif