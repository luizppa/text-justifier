#include<string>

#ifndef IFORMATTER_H
#define IFORMATTER_H

class IFormatter {

    public:
        virtual ~IFormatter() {}
        virtual std::string align(const std::string& input) = 0;

};

#endif