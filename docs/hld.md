# High-Level Design (HLD) for Proxy Server

## Overview
The Proxy Server acts as a middle layer between clients and the target server. It intercepts client requests, forwards them to the target server, and returns the response back to the client.

---

## Components:
### 1. **ProxyServer**:
   - **Role**: Accepts client connections and starts a `ClientHandler` thread for each client.
   - **Responsibilities**:
     - Listens on the specified port.
     - Accepts incoming client connections.
     - Starts a new thread to handle each client.
  
### 2. **ClientHandler**:
   - **Role**: Handles individual client requests in separate threads.
   - **Responsibilities**:
     - Reads the incoming client request.
     - Forwards the request to the appropriate target server.
     - Sends the response back to the client.

### 3. **RequestParser**:
   - **Role**: Parses incoming HTTP requests from the client.
   - **Responsibilities**:
     - Extracts necessary details from the HTTP request (headers, target server, etc.).
     - Provides the parsed data to the `ClientHandler`.

---

## High-Level Architecture Diagram

![High-Level Architecture](https://via.placeholder.com/600x400.png) 
*Note: Replace with your actual architecture diagram*

