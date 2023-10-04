#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include <string>

typedef struct
{
    std::string name;
    std::string email;
    std::string password;
} UserPayload;

#include "crow.h"

class UserController
{
public:
    UserController() {}
    ~UserController() {}
    UserPayload get();
    void create(UserPayload obj);

private:
};


#endif // USER_CONTROLLER_HPP
