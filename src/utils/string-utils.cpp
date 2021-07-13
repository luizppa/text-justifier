#include<cstring>
#include<sstream>
#include<cmath>

#include"../../include/utils/string-utils.hpp"

namespace stringUtils {

    /**
     * @brief creates a string of the specified size by replicating
     * the received character
     * @param fillChar the character to be replicated
     * @param size the length of the resulting string
     * @returns the resulting string
     */
    std::string fillString(char fillChar, int size){
        std::string output;
        char* str = (char*) malloc((size + 1) * sizeof(char));

        std::memset(str, fillChar, size);
        str[size] = '\0';
        output = std::string(str);
        free(str);
        
        return output;
    }

    /**
     * @brief returns a vector containing the positions of the input string
     * that match a \s character
     * @param input the input string to be analyzed
     * @param begin the starting index to analyze (inclusive)
     * @param length the number of characters to be analyzed from the begining 
     * @returns a vector containing the white space indexes
     */
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

    /**
     * @brief returns the input string expanded to a specified size by
     * evenly inflating \s characters
     * @param input the input string to be expanded (non-destructive)
     * @param targetLength the target length of the output string
     * @param whiteSpacePositions the vector containing the positions of th input that are white spaces
     * @param fillChar the character used to inflate the whitespaces
     */
    std::string expandLine(const std::string& input, int targetLength, std::vector<int>& whiteSpacePositions, char fillChar){
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