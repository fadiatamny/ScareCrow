#include <iostream>
#include <string>
#include "crow.h"
#include "routers/user.router.hpp"

int main(int argc, char *argv[])
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]()
     { return "Hello world"; });

    UserRouter userRouter(app);

    app.port(18080).multithreaded().run();
    return 0;
}