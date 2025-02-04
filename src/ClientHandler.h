#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

class ClientHandler {
public:
    ClientHandler(int clientSocket);
    void operator()();

private:
    int clientSocket;
    void handleRequest();
};

#endif // CLIENTHANDLER_H
