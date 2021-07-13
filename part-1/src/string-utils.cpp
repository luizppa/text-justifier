#include <cstring>
#include<sstream>
#include<cmath>

#include"../include/string-utils.hpp"

namespace stringUtils {

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

    std::string expandLine(std::string& input, int targetLength, std::vector<int>& whiteSpacePositions, char fillChar){
        int targetSpacesNumber, spacesMultiplier, whiteSpaces, remainderSpaces;
        std::stringstream outputStream;

        whiteSpaces = whiteSpacePositions.size();
        targetSpacesNumber = targetLength - (input.length() - whiteSpaces);
        spacesMultiplier = std::floor(targetSpacesNumber / whiteSpaces);
        remainderSpaces = targetSpacesNumber % whiteSpaces;

        std::string::const_iterator it;
        for(it = input.begin(); it != input.end(); ++it){
            if(*it == ' '){
                outputStream << fillString(fillChar, spacesMultiplier);
                if(remainderSpaces > 0){
                    outputStream << fillChar;
                    remainderSpaces--;
                }
            }
            else{
                outputStream << *it;
            }
        }

        return outputStream.str();
    }

}