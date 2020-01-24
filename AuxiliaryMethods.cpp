#include "AuxiliaryMethods.h"
#include <sstream>

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}
string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods::convertFloatToString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string AuxiliaryMethods::idWithNumber(int number){

    string word = "ID";
    word += convertIntToString(number);
    return word;
}
int AuxiliaryMethods::changeIdToInteger(string idWithNumber){
    string word = "";
    for (int i = 2; i < idWithNumber.length(); i++)
    {
        word += idWithNumber[i];
    }
    return convertStringToInt(word);
}
char AuxiliaryMethods::loadChar(){
    string input = "";
    char output  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            output = input[0];
            break;
        }
        cout << "This is not single char, try again." << endl;
    }
    return output;
}
string AuxiliaryMethods::changeCommaToDot(string word){

    string newWord;

    for (int i = 0; i < word.length(); i++){

        if (word[i] == ',')
            newWord += '.';
        else
            newWord += word[i];
    }
    return newWord;

}
float AuxiliaryMethods::convertToFloat(string amount){
    return  (float)atof(amount.c_str());
}
