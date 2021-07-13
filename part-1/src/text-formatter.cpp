#include<sstream>
#include<vector>

#include"../include/text-formatter.hpp"
#include"../include/string-utils.hpp"

namespace textFormatter {
    
    std::string justifyParagraph(const std::string& input, int targetLength){
        long unsigned int lineStart = 0;
        std::stringstream outputStream;

        while(lineStart < input.length()){
            std::vector<int> whiteSpacePositions = stringUtils::getWhiteSpaces(input, lineStart, targetLength);
            long unsigned int lineEnd, lineLength;

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
                    std::string lineSubstring = input.substr(lineStart, lineLength);

                    outputStream << stringUtils::expandLine(lineSubstring, targetLength, whiteSpacePositions, FILL_CHAR);

                    lineStart = lineEnd + 1;
                }
            }

            outputStream << '\n';
        }

        return outputStream.str();
    }

}