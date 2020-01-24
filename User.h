#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    string name, surname, login, password;
    int id;
public:

    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    int getId();
    void setId(int newId);
    void setName(string userName);
    void setSurname(string userSurname);
    void setLogin(string userLogin);
    void setPassword(string userPassword);

};

#endif
