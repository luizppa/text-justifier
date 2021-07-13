#include<iostream>
#include<string>
#include<sstream>
#include<limits>

#include"include/formatters/justify-formatter.hpp"
#include"include/exceptions/formatter-exception.hpp"
#include"include/document.hpp"

void justifyParagraph(const std::string& input, int targetLength){
    try{
        JustifyFormatter* justify = new JustifyFormatter(' ', targetLength);
        std::cout << justify->align(input.substr(0)) << '\n';
        delete justify;
    }
    catch(FormatterException& e){
        std::cout << "Error creating formater: " << e.what() << '\n';
    }
}

void justifyDocument(const std::string& input, int targetLength){
    try{
        JustifyFormatter* justify = new JustifyFormatter(' ', targetLength);
        Document document(input, justify);
        document.render();
        delete justify;
    }
    catch(FormatterException& e){
        std::cout << "Error creating formater: " << e.what() << '\n';
    }
}

int main(){
    std::string input;
    std::stringstream inputStream;
    int targetLength;
    char mode;

    std::cin >> mode >> targetLength;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(mode == 'P'){
        std::getline(std::cin, input, '\n');
        justifyParagraph(input, targetLength);
    }
    else if(mode == 'D'){
        while(std::getline(std::cin, input, '\n')){
            inputStream << input << '\n';
        }
        justifyDocument(inputStream.str(), targetLength);
    }
    
    return 0;
}