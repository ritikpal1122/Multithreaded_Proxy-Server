#include <iostream>
#include <unistd.h>
#include "ClientHandler.h"
#include "RequestParser.h"

ClientHandler::ClientHandler(int clientSocket) : clientSocket(clientSocket) {}

void ClientHandler::operator()() {
    handleRequest();
}

void ClientHandler::handleRequest() {
    char buffer[1024];
    int bytesRead = read(clientSocket, buffer, sizeof(buffer));
    
    if (bytesRead <= 0) {
        close(clientSocket);
        return;
    }

    // Parse the incoming request
    RequestParser parser(buffer);
    std::string request = parser.parseRequest();

    // Forward the request to the target server and get the response
    std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nProxy Response";

    // Send the response to the client
    send(clientSocket, response.c_str(), response.size(), 0);
    
    close(clientSocket);
}
