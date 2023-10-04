#include "socket.controller.hpp"

void SocketController::onOpen(crow::websocket::connection& conn)
{
    CROW_LOG_INFO << "new websocket connection";
    std::lock_guard<std::mutex> _(this->mutex);
    this->users.insert(&conn);
}

void SocketController::onClose(crow::websocket::connection& conn, const std::string& reason)
{
    CROW_LOG_INFO << "websocket connection closed: " << reason;
    std::lock_guard<std::mutex> _(this->mutex);
    this->users.erase(&conn);
}

void SocketController::onMessage(crow::websocket::connection& conn, const std::string& data, bool is_binary)
{
    CROW_LOG_INFO << "message from websocket, is_binary = " << is_binary << ", data size = " << data.size();

    std::lock_guard<std::mutex> _(this->mutex);
    for(auto u: this->users)
    {
        if(u != &conn)
        {
            if(is_binary)
                u->send_binary(data);
            else
                u->send_text(data);
        }
    }
}