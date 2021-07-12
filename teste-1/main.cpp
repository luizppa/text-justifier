#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <cmath>

#define FILL_CHAR ' '

std::vector<int> getWhiteSpaces(const std::string& input, int begin, int length){
    std::vector<int> whiteSpacePositions;
    std::string::const_iterator it = input.begin() + begin;

    // std::cout << '[';
    for(int i = begin; it != input.end() && i < begin + length; ++it, i++){
        if(*it == ' '){
            // std::cout << i << ", ";
            whiteSpacePositions.push_back(i);
        }
    }
    if(whiteSpacePositions.size() > 0){
        // std::cout << "\b\b";
    }
    // std::cout << "]\n";

    return whiteSpacePositions;
}

// std::string expandLine(std::string input, int targetLength, std::vector<int> whiteSpacePositions, char fillCharacter){
//     int lineEnd, lineLength, spacesToInsert, spacesMultiplier, whiteSpaces, remainderSpaces;

//     whiteSpaces = whiteSpacePositions.size() - 1;
//     spacesToInsert = targetLength - lineLength + whiteSpaces;
//     spacesMultiplier = std::ceil(spacesToInsert / whiteSpaces);
//     remainderSpaces = targetLength - (lineLength - whiteSpaces + (whiteSpaces * spacesMultiplier));

//     // std::cout << "Início da linha: " << lineStart << "\n";
//     // std::cout << "Fim da linha " << lineEnd << "\n";
//     // std::cout << "Tamanho da linha: " << lineLength << "\n";
//     // std::cout << "Número de espaços: " << whiteSpaces << "\n";
//     // std::cout << "Linha deve ter " << spacesToInsert << " espaços\n";
//     // std::cout << "Espaços restantes " << remainderSpaces << "\n\n";

//     for(int i = 0; i < lineEnd; i++){
//         if(input.at(i) == ' '){
//             for(int j = 0; j < spacesMultiplier; j++){
//                 outputStream << FILL_CHAR;
//             }
//             if(remainderSpaces > 0){
//                 outputStream << FILL_CHAR;
//                 remainderSpaces--;
//             }
//         }
//         else{
//             outputStream << input.at(i);
//         }
//     }
// }

std::string justifyParagraph(const std::string& input, int targetLength){
    int lineStart = 0;
    std::stringstream outputStream;

    while(lineStart < input.length()){
        std::vector<int> whiteSpacePositions = getWhiteSpaces(input, lineStart, targetLength);
        int lineEnd, lineLength, spacesToInsert, spacesMultiplier, whiteSpaces, remainderSpaces;

        if(input.length() < lineStart + targetLength){
            outputStream << input.substr(lineStart);
            lineStart = input.length() + 1;
        }
        else{
            if(input.at(lineStart + targetLength) == ' '){
                // std::cout << "Início da linha: " << lineStart << "\n";
                lineEnd = lineStart + targetLength;
                // std::cout << "Fim da linha " << lineEnd << "\n";
                outputStream << input.substr(lineStart, targetLength);
                lineStart = lineEnd + 1;
                // std::cout << "Novo início da linha " << lineStart << "\n\n";
            }
            else {
                if(whiteSpacePositions.size() < 2){
                    lineEnd = lineStart + targetLength - 1;
                    outputStream << input.substr(lineStart, targetLength - 1) << '-';
                    lineStart = lineEnd;
                }
                else {
                    lineEnd = whiteSpacePositions.back();
                    lineLength = lineEnd - lineStart;
                    whiteSpaces = whiteSpacePositions.size() - 1;
                    spacesToInsert = targetLength - lineLength + whiteSpaces;
                    spacesMultiplier = std::ceil(spacesToInsert / whiteSpaces);
                    remainderSpaces = targetLength - (lineLength - whiteSpaces + (whiteSpaces * spacesMultiplier));

                    // std::cout << "Início da linha: " << lineStart << "\n";
                    // std::cout << "Fim da linha " << lineEnd << "\n";
                    // std::cout << "Tamanho da linha: " << lineLength << "\n";
                    // std::cout << "Número de espaços: " << whiteSpaces << "\n";
                    // std::cout << "Linha deve ter " << spacesToInsert << " espaços\n";
                    // std::cout << "Espaços restantes " << remainderSpaces << "\n\n";

                    for(int i = lineStart; i < lineEnd; i++){
                        if(input.at(i) == ' '){
                            for(int j = 0; j < spacesMultiplier; j++){
                                outputStream << FILL_CHAR;
                            }
                            if(remainderSpaces > 0){
                                outputStream << FILL_CHAR;
                                remainderSpaces--;
                            }
                        }
                        else{
                            outputStream << input.at(i);
                        }
                    }
                    lineStart = lineEnd + 1;
                }
            }
        }

        outputStream << '\n';
        // std::cout << "\n=================================\n" << outputStream.str() << "\n=================================\n";
    }

    return outputStream.str();
}

int main(int argc, char const* argv[]){
    std::string input;
    int n;

    std::getline(std::cin, input, '\n');
    std::cin >> n;
    std::cout << justifyParagraph(input, n);
    return 0;
}