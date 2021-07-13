#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <cmath>
#include <cstring>

#define FILL_CHAR ' '

std::string fillString(char fillChar, int size){
    std::string output;
    char* str = (char*) malloc((size + 1) * sizeof(char));

    std::memset(str, fillChar, size);
    str[size] = '\0';
    output = std::string(str);
    free(str);
    
    return output;
}

std::vector<int> getWhiteSpaces(const std::string& input, int begin, int length){
    std::vector<int> whiteSpacePositions;
    std::string::const_iterator it = input.begin() + begin;

    for(int i = begin; it != input.end() && i < begin + length; ++it, i++){
        if(*it == ' '){
            whiteSpacePositions.push_back(i);
        }
    }

    return whiteSpacePositions;
}

std::string expandLine(std::string input, int targetLength, std::vector<int> whiteSpacePositions, char fillCharacter){
    int targetSpacesNumber, spacesMultiplier, whiteSpaces, remainderSpaces;
    std::stringstream outputStream;

    whiteSpaces = whiteSpacePositions.size();
    targetSpacesNumber = targetLength - (input.length() - whiteSpaces);
    spacesMultiplier = std::floor(targetSpacesNumber / whiteSpaces);
    remainderSpaces = targetSpacesNumber % whiteSpaces;

    std::string::const_iterator it;
    for(it = input.begin(); it != input.end(); ++it){
        if(*it == ' '){
            outputStream << fillString(fillCharacter, spacesMultiplier);
            if(remainderSpaces > 0){
                outputStream << fillCharacter;
                remainderSpaces--;
            }
        }
        else{
            outputStream << *it;
        }
    }

    return outputStream.str();
}

std::string justifyParagraph(const std::string& input, int targetLength){
    int lineStart = 0;
    std::stringstream outputStream;

    while(lineStart < input.length()){
        std::vector<int> whiteSpacePositions = getWhiteSpaces(input, lineStart, targetLength);
        int lineEnd, lineLength, spacesToInsert, spacesMultiplier, whiteSpaces, remainderSpaces;

        if(input.length() < lineStart + targetLength){ // Last line in paragraph, should not be justified
            outputStream << input.substr(lineStart);
            break;
        }
        else{
            if(input.at(lineStart + targetLength) == ' '){ // Line break at optimal length
                lineEnd = lineStart + targetLength;
                outputStream << input.substr(lineStart, targetLength);
                lineStart = lineEnd + 1;
            }
            else if(whiteSpacePositions.size() < 2){ // Impossible to justify without word wrap
                lineEnd = lineStart + targetLength - 1;
                outputStream << input.substr(lineStart, targetLength - 1) << '-';
                lineStart = lineEnd;
            }
            else { // Expand spaces to justify
                lineEnd = whiteSpacePositions.back();
                whiteSpacePositions.pop_back();
                lineLength = lineEnd - lineStart;

                outputStream << expandLine(input.substr(lineStart, lineLength), targetLength, whiteSpacePositions, FILL_CHAR);

                lineStart = lineEnd + 1;
            }
        }

        outputStream << '\n';
    }

    return outputStream.str();
}

int main(int argc, char const* argv[]){
    std::string input;
    int n;

    std::getline(std::cin, input, '\n');
    std::cin >> n;
    std::cout << justifyParagraph(input, n) << '\n';
    return 0;
}