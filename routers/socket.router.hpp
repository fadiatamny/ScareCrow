#ifndef SOCKET_ROUTER_HPP
#define SOCKET_ROUTER_HPP

#include "crow.h"
#include "../controllers/SocketController/socket.controller.hpp"

class SocketRouter
{
public:
    SocketRouter(crow::SimpleApp &app) : _app(app)
    {
        this->index();
        this->ws();
    }
    ~SocketRouter() {}

    void index()
    {
        CROW_ROUTE(this->_app, "/")
        ([this]()
         {
            char name[256];
            gethostname(name, 256);        
            auto page = crow::mustache::load("index.html");
            return page.render(); });
    }
    void ws()
    {
        CROW_ROUTE(this->_app, "/ws")
            .websocket()
            .onopen([&](crow::websocket::connection &conn)
                    { this->_controller.onOpen(conn); })
            .onclose([&](crow::websocket::connection &conn, const std::string &reason)
                     { this->_controller.onClose(conn, reason); })
            .onmessage([&](crow::websocket::connection &conn, const std::string &data, bool is_binary)
                       { this->_controller.onMessage(conn, data, is_binary); });
    }

private:
    crow::SimpleApp &_app;
    SocketController _controller;
};

#endif // SOCKET_ROUTER_HPP