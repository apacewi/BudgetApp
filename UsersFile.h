#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "User.h"
#include <vector>

using namespace std;

class UsersFile
{
    const string NAME_OF_USERS_FILE;
    AuxiliaryMethods auxiliaryMethods;
    CMarkup xml;
    vector <User> users;
public:
    UsersFile (string usersFileName): NAME_OF_USERS_FILE(usersFileName) {
    loadUsers();
    };
    void loadUsers();
    void addNewUser(User user);
    vector <User> getUsersVector();
    void save(string newPassword, int logedUserId);
    int checkLoginAndPassword(string login, string password);
};

#endif
