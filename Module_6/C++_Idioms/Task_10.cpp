#include "networkconnection.h"
#include <iostream>

// Simulated platform-specific/network details are hidden here
struct NetworkConnection::Impl {
    std::string endpoint;
    bool connected;

    Impl(const std::string& ep) : endpoint(ep), connected(false) {
        // Simulate opening a socket or connection
        connected = true;
        std::cout << "[Impl] Connected to " << endpoint << std::endl;
    }
    ~Impl() {
        // Simulate closing the socket/connection
        if (connected) {
            std::cout << "[Impl] Connection to " << endpoint << " closed" << std::endl;
        }
    }
    void sendData(const std::string& data) {
        if (!connected) {
            std::cerr << "[Impl] Not connected!\n";
            return;
        }
        std::cout << "[Impl] Sending data to " << endpoint << ": " << data << std::endl;
    }
};

NetworkConnection::NetworkConnection(const std::string& ep)
    : impl(std::make_unique<Impl>(ep)) {}

NetworkConnection::~NetworkConnection() = default;

bool NetworkConnection::isConnected() const {
    return impl->connected;
}

void NetworkConnection::sendData(const std::string& data) {
    impl->sendData(data);
}
int main() {
    {
        NetworkConnection conn1("127.0.0.1:8080");
        conn1.sendData("Hello, server!");

        NetworkConnection conn2("192.168.1.5:7000");
        conn2.sendData("Quick check");

        // Connections are closed automatically at scope exit
    }
    std::cout << "All connections closed (destructor)." << std::endl;
    return 0;
}