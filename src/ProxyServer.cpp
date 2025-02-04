#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ProxyServer.h"
#include "ClientHandler.h"

ProxyServer::ProxyServer(int port) : port(port), isRunning(false) {}

void ProxyServer::start() {
    // Setup and bind server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed!" << std::endl;
        exit(1);
    }

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Listen failed!" << std::endl;
        exit(1);
    }

    std::cout << "Proxy server started on port " << port << std::endl;
    acceptConnections();
}

void ProxyServer::acceptConnections() {
    while (isRunning) {
        sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
        
        if (clientSocket < 0) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }

        // Handle each client request in a separate thread
        std::thread clientThread(ClientHandler(clientSocket));
        clientThread.detach();  // Detach the thread so it runs independently
    }
}
