# Proxy Server - Multithreaded Proxy in C++

## Overview

This is a simple **multithreaded proxy server** written in C++ which forwards HTTP requests from clients to the target server and returns the server's response back to the client.

### Features:
- Multithreading using `std::thread` to handle multiple client requests concurrently.
- Basic HTTP Proxy functionality, capable of receiving and forwarding HTTP requests.
- Request handling through a separate `ClientHandler` class.

---

## How to Build and Run

### Prerequisites:
1. **C++ Compiler**: Ensure you have a C++ compiler that supports C++11 or later (e.g., `g++`).
2. **Operating System**: This proxy server is designed to run on **Linux**. It may require minor adjustments for Windows/MacOS.

### Steps to Build:
1. Clone or copy the source files.
2. Open a terminal and navigate to the project directory.

3. **Compile the code**:
    ```bash
    g++ -std=c++11 src/*.cpp -o proxy-server -pthread
    ```

4. **Run the Proxy Server**:
    ```bash
    ./proxy-server
    ```

   This will start the server and listen on **port 8080**.

5. **Test the Proxy**: You can test the proxy using any web browser by setting your browser's proxy settings to `localhost:8080`. Any HTTP request will go through the proxy.

---

## How It Works:
- **ProxyServer**: Listens for client connections on port 8080.
- **ClientHandler**: When a client sends a request, it creates a new thread to handle that client.
- **RequestParser**: Parses the HTTP request from the client.

---

## License:
MIT License
