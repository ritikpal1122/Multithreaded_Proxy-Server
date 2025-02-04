#ifndef REQUESTPARSER_H
#define REQUESTPARSER_H

#include <string>

class RequestParser {
public:
    RequestParser(const char* request);
    std::string parseRequest();

private:
    std::string request;
};

#endif // REQUESTPARSER_H
