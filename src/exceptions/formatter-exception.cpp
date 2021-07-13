#include"../../include/exceptions/formatter-exception.hpp"

FormatterException::FormatterException(std::string message) : std::invalid_argument(message) { }

FormatterException::~FormatterException() { }