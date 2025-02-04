# Low-Level Design (LLD) for Proxy Server

## Classes and Methods:
### 1. **ProxyServer Class**:
   - **Methods**:
     - `start()`: Starts the server and binds to the given port.
     - `acceptConnections()`: Accepts incoming client connections.
   
   - **Responsibilities**:
     - Manages server socket.
     - Accepts client connections and passes them to a handler.

### 2. **ClientHandler Class**:
   - **Methods**:
     - `operator()`: Calls `handleRequest()` to manage the request.
     - `handleRequest()`: Reads client request, forwards it to the target server, and sends back a response.
   
   - **Responsibilities**:
     - Handles requests from individual clients in separate threads.
     - Interacts with the `RequestParser` to process the HTTP request.
     - Forwards the response to the client.

### 3. **RequestParser Class**:
   - **Methods**:
     - `parseRequest()`: Extracts necessary information from the HTTP request.
   
   - **Responsibilities**:
     - Parses the HTTP request to extract target server details and headers.

---

## Low-Level Architecture Diagram

![Low-Level Architecture](https://via.placeholder.com/600x400.png)
*Note: Replace with your actual low-level diagram*

