#include<sstream>
#include<vector>

#include"../../include/formatters/justify-formatter.hpp"
#include"../../include/utils/string-utils.hpp"
#include"../../include/exceptions/formatter-exception.hpp"

JustifyFormatter::JustifyFormatter(){ }

JustifyFormatter::JustifyFormatter(char fillChar, int lineLength){
    this->fillChar = fillChar;
    if(lineLength < 2) {
        throw FormatterException("Justification line length must be at least 2");
    }
    this->lineLength = lineLength;
}

JustifyFormatter::~JustifyFormatter(){ }

std::string JustifyFormatter::align(const std::string& input) {
    long unsigned int lineBegin = 0;
    std::stringstream outputStream;

    while(lineBegin < input.length()){
        std::vector<int> whiteSpacePositions = stringUtils::getWhiteSpaces(input, lineBegin, this->lineLength);
        long unsigned int lineEnd, lineLength;

        // Last line in paragraph, should not be justified
        if(input.length() < lineBegin + this->lineLength){
            outputStream << input.substr(lineBegin);
            break;
        }

        // Line break at optimal length
        else if(input.at(lineBegin + this->lineLength) == ' '){
            lineEnd = lineBegin + this->lineLength;
            outputStream << input.substr(lineBegin, this->lineLength);
            lineBegin = lineEnd + 1;
        }

        // Impossible to justify without word wrap
        else if(whiteSpacePositions.size() < 2){
            lineEnd = lineBegin + this->lineLength - 1;
            outputStream << input.substr(lineBegin, this->lineLength - 1) << '-';
            lineBegin = lineEnd;
        }

        // Expand spaces to justify
        else {
            lineEnd = whiteSpacePositions.back();
            whiteSpacePositions.pop_back();
            lineLength = lineEnd - lineBegin;
            std::string lineSubstring = input.substr(lineBegin, lineLength);

            outputStream << stringUtils::expandLine(lineSubstring, this->lineLength, whiteSpacePositions, this->fillChar);

            lineBegin = lineEnd + 1;
        }

        outputStream << '\n';
    }

    return outputStream.str();
}
