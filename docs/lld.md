# Low-Level Design (LLD)

## Class Design

1. **ProxyServer Class**:
   - **Methods**: `start()`, `acceptConnections()`
   - **Responsibilities**: Manages server socket, accepts client connections.

2. **ClientHandler Class**:
   - **Methods**: `operator()`, `handleRequest()`
   - **Responsibilities**: Handles client request and sends response.

3. **RequestParser Class**:
   - **Methods**: `parseRequest()`
   - **Responsibilities**: Parses HTTP requests.
