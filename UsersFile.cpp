#include "UsersFile.h"

void UsersFile::loadUsers() {

    User user;

    if (xml.Load(NAME_OF_USERS_FILE) == true) {
        xml.ResetMainPos();
        xml.FindElem("UsersFile");
        xml.IntoElem();

        while (xml.FindElem() == true) {

            user.setId(auxiliaryMethods.changeIdToInteger(xml.GetTagName()));

            xml.FindChildElem("Name");
            user.setName(xml.GetChildData());

            xml.FindChildElem("Surname");
            user.setSurname(xml.GetChildData());

            xml.FindChildElem("Login");
            user.setLogin(xml.GetChildData());

            xml.FindChildElem("Password");
            user.setPassword(xml.GetChildData());

            users.push_back(user);
        }
    }
    else {
        cout << "File with users does not exist! " << endl;
    }
}
void UsersFile::addNewUser(User user) {

    CMarkup xml;
    if (xml.Load(NAME_OF_USERS_FILE) == true) {

        xml.FindElem("UsersFile");
        xml.IntoElem();
        xml.AddElem(auxiliaryMethods.idWithNumber(users[users.size()-1].getId()+1));
        xml.IntoElem();
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.Save(NAME_OF_USERS_FILE);

    }
    else {
        xml.AddElem("UsersFile");
        xml.IntoElem();
        xml.AddElem("ID1");
        xml.IntoElem();
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.Save(NAME_OF_USERS_FILE);
    }
    loadUsers();
}
vector <User> UsersFile::getUsersVector() {
    return users;
}
int UsersFile::checkLoginAndPassword(string login, string password) {

    string checkedLogin, checkedPassword, logedUserIdInString;
    int logedUserId = 0;

    if (xml.Load(NAME_OF_USERS_FILE) == true) {

        xml.FindElem("UsersFile");
        xml.IntoElem();

        while(xml.FindElem() == true) {

            logedUserIdInString = xml.GetTagName();
            xml.FindChildElem("Login");
            checkedLogin = xml.GetChildData();
            xml.FindChildElem("Password");
            checkedPassword = xml.GetChildData();

            if(checkedLogin == login && checkedPassword == password) {
                logedUserId = auxiliaryMethods.changeIdToInteger(logedUserIdInString);
                break;
            }
        }
    }
    else {
        cout << "Users file not found" << endl;
    }
    return logedUserId;
}
void UsersFile::save(string newPassword, int logedUserId) {


    CMarkup xml;
    if (xml.Load(NAME_OF_USERS_FILE) == true) {

        xml.ResetMainPos();
        xml.FindElem("UsersFile");
        xml.IntoElem();

        while (xml.FindElem()==true) {

            if(auxiliaryMethods.changeIdToInteger(xml.GetTagName()) == logedUserId) {
                xml.FindChildElem("Password");
                xml.SetChildData(newPassword);
            }
        }
        xml.Save(NAME_OF_USERS_FILE);
        cout << "Password sccesfully changed! " << endl;
        system("Pause");
    }
    else {
        cout << "Cannot change password! " << endl;
    }
    loadUsers();
}
