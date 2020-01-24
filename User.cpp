#include "User.h"

string User::getName(){
    return name;
}
string User::getSurname(){
    return surname;
}
string User::getLogin(){
    return login;
}
string User::getPassword(){
    return password;
}
int User::getId(){
    return id;
}
void User::setId(int newId){
    id = newId;
}
void User::setName(string userName){
    name = userName;
}
void User::setSurname(string userSurname){
    surname = userSurname;
}
void User::setLogin(string userLogin){
    login = userLogin;
}
void User::setPassword(string userPassword){
    password = userPassword;
}

