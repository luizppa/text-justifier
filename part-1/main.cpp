#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <cmath>
#include <cstring>

#include "include/text-formatter.hpp"

int main(){
    std::string input;
    int n;

    std::getline(std::cin, input, '\n');
    std::cin >> n;
    std::cout << textFormatter::justifyParagraph(input, n) << '\n';
    
    return 0;
}