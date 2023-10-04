#ifndef SOCKET_CONTROLLER_HPP
#define SOCKET_CONTROLLER_HPP

#include <mutex>
#include <unordered_set>
#include "crow.h"

class SocketController
{
public:
    SocketController() {}
    ~SocketController() {}

    void onOpen(crow::websocket::connection &conn);
    void onClose(crow::websocket::connection &conn, const std::string &reason);
    void onMessage(crow::websocket::connection &conn, const std::string &data, bool is_binary);

public:
    std::mutex mutex;
    std::unordered_set<crow::websocket::connection *> users;
};

#endif // SOCKET_CONTROLLER_HPP
