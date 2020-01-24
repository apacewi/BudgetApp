#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    int logedUserId;
    AuxiliaryMethods auxiliaryMethods;
    UsersFile usersFile;
    vector <User> users;

public:
    UserManager (string usersFileName) : usersFile(usersFileName) {
    logedUserId = 0;
    users = usersFile.getUsersVector();
    };
    void changePassword();
    int loginUser();
    void registerUser();
};

#endif
