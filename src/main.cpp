#include <iostream>
#include "ProxyServer.h"

int main() {
    // Initialize and start the proxy server
    ProxyServer server(8080);  // Listen on port 8080
    server.start();
    return 0;
}
