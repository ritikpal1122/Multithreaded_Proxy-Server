#include "RequestParser.h"

RequestParser::RequestParser(const char* request) : request(request) {}

std::string RequestParser::parseRequest() {
    // For simplicity, let's just return the request string for now
    return std::string(request);
}
