#ifndef USER_ROUTER_HPP
#define USER_ROUTER_HPP

#include "crow.h"
#include "../controllers/UserController/user.controller.hpp"

class UserRouter
{
public:
    UserRouter(crow::SimpleApp &app) : _app(app)
    {
        this->get();
        this->create();
    }
    ~UserRouter() {}

    void get()
    {
        CROW_ROUTE(this->_app, "/user")
        ([this]()
         {
             crow::json::wvalue payload;
             UserPayload obj = this->_controller.get();

             payload["name"] = obj.name;
             payload["email"] = obj.email;
             payload["password"] = obj.password;

             return payload; });
    }
    void create()
    {
        CROW_ROUTE(this->_app, "/user")
            .methods("POST"_method)([this](const crow::request &req)
                                    {
                auto x = crow::json::load(req.body);
                if (!x)
                    return crow::response(crow::status::BAD_REQUEST);

                UserPayload obj = { x["name"].s(), x["email"].s(), x["password"].s() };
                this->_controller.create(obj);
                return crow::response{}; });
    }

private:
    crow::SimpleApp &_app;
    UserController _controller;
};

#endif // USER_ROUTER_HPP