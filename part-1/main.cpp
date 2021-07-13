#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <cmath>
#include <cstring>

#include "include/text-formatter.hpp"

int main(){
    TextFormatter* formatter = new TextFormatter();
    std::string input;
    int n;

    std::getline(std::cin, input, '\n');
    std::cin >> n;
    std::cout << formatter->justifyParagraph(input, n) << '\n';
    
    delete formatter;
    return 0;
}