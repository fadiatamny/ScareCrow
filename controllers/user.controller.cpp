#include "user.controller.hpp"

UserPayload UserController::get()
{
    UserPayload obj;
    obj.name = "John Doe";
    obj.email = "John@Doe.com";
    obj.password = "123456";
    return obj;
}

void UserController::create(UserPayload obj)
{
    std::cout << obj.name << std::endl;
    std::cout << obj.email << std::endl;
    std::cout << obj.password << std::endl;
}