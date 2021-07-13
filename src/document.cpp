#include<iostream>

#include"../include/document.hpp"

Document::Document(const std::string& input, IFormatter* formatter) {
    std::stringstream inputStream(input);
    this->read(inputStream);
    this->formatter = formatter;
}

Document::~Document() { }

void Document::read(std::stringstream& inputStream){
    std::string paragraphText;
    while(std::getline(inputStream, paragraphText, '\n')){
        this->paragraphs.push_back(Paragraph(paragraphText));
    }
}

void Document::render(){
    for(std::vector<Paragraph>::iterator it = this->paragraphs.begin(); it != this->paragraphs.end(); ++it){
        it->render(this->formatter);
        std::cout << "\n\n";
    }
}
