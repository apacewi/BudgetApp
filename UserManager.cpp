#include "UserManager.h"

int UserManager::loginUser()
{
    string login, password;

    cout << "Give your login: ";
    login = auxiliaryMethods.loadLine();
    cout << "Give your password: ";
    password = auxiliaryMethods.loadLine();

    logedUserId = usersFile.checkLoginAndPassword(login, password);

    return logedUserId;
}
void UserManager::registerUser()
{
    User user;

    cout << "Give your name: ";
    user.setName(auxiliaryMethods.loadLine());
    cout << "Give your surname: ";
    user.setSurname(auxiliaryMethods.loadLine());
    cout << "Give your login (permanently): ";
    user.setLogin(auxiliaryMethods.loadLine());
    cout << "Give your password (You can change it later): ";
    user.setPassword(auxiliaryMethods.loadLine());

    usersFile.addNewUser(user);
}
void UserManager::changePassword(){

    string newPassword;
    cout << "New password: " << endl;
    newPassword = auxiliaryMethods.loadLine();

    usersFile.save(newPassword, logedUserId);

}
