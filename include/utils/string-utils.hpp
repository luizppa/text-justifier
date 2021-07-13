#include<string>
#include<vector>

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

namespace stringUtils {

    std::string fillString(char fillChar, int size);
    std::vector<int> getWhiteSpaces(const std::string& input, int begin, int length);
    std::string expandLine(const std::string& input, int targetLength, std::vector<int>& whiteSpacePositions, char fillChar);

}

#endif