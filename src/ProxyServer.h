#ifndef PROXYSERVER_H
#define PROXYSERVER_H

#include <string>
#include <thread>
#include <vector>
#include <atomic>

class ProxyServer {
public:
    ProxyServer(int port);
    void start();
    void acceptConnections();

private:
    int serverSocket;
    int port;
    std::atomic<bool> isRunning;
};

#endif // PROXYSERVER_H
