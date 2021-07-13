#include<sstream>
#include<vector>

#include"../include/text-formatter.hpp"
#include"../include/string-utils.hpp"

TextFormatter::TextFormatter(){ }

TextFormatter::TextFormatter(char fillChar){
    this->fillChar = fillChar;
}

TextFormatter::~TextFormatter(){ }

std::string TextFormatter::justifyParagraph(const std::string& input, int targetLength){
    long unsigned int lineBegin = 0;
    std::stringstream outputStream;

    while(lineBegin < input.length()){
        std::vector<int> whiteSpacePositions = stringUtils::getWhiteSpaces(input, lineBegin, targetLength);
        long unsigned int lineEnd, lineLength;

        // Last line in paragraph, should not be justified
        if(input.length() < lineBegin + targetLength){
            outputStream << input.substr(lineBegin);
            break;
        }

        // Line break at optimal length
        else if(input.at(lineBegin + targetLength) == ' '){
            lineEnd = lineBegin + targetLength;
            outputStream << input.substr(lineBegin, targetLength);
            lineBegin = lineEnd + 1;
        }

        // Impossible to justify without word wrap
        else if(whiteSpacePositions.size() < 2){
            lineEnd = lineBegin + targetLength - 1;
            outputStream << input.substr(lineBegin, targetLength - 1) << '-';
            lineBegin = lineEnd;
        }

        // Expand spaces to justify
        else {
            lineEnd = whiteSpacePositions.back();
            whiteSpacePositions.pop_back();
            lineLength = lineEnd - lineBegin;
            std::string lineSubstring = input.substr(lineBegin, lineLength);

            outputStream << stringUtils::expandLine(lineSubstring, targetLength, whiteSpacePositions, this->fillChar);

            lineBegin = lineEnd + 1;
        }

        outputStream << '\n';
    }

    return outputStream.str();
}