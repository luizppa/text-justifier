#include<iostream>

#include"../include/paragraph.hpp"

Paragraph::Paragraph(const std::string& input){
    this->input = input;
}

Paragraph::~Paragraph(){ }

void Paragraph::render(IFormatter* formatter){
    std::cout << formatter->align(this->input);
}