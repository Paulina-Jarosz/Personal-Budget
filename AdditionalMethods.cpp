#include "AdditionalMethods.h"


char AdditionalMethods :: getCharacter()
{
    string providedCharacter = "";
    char character  = {0};

    while (true)
    {
        getline(cin, providedCharacter);

        if (providedCharacter.length() == 1)
        {
            character = providedCharacter[0];
            break;
        }
        cout << "This is not one character. Please enter one more time." << endl;
    }
    return character;
}

string AdditionalMethods :: changeFirstLetterToCapitalAndOtherToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AdditionalMethods :: getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

float AdditionalMethods :: loadFloat()
{
    string providedData = "";
    float number = 0.0;

    while (true)
    {
        cin.clear();
        getline(cin, providedData);

        stringstream myStream(providedData);
        if (myStream >> number)
            break;
        cout << "This is not the amount. Please add again. " << endl;
    }
    return number;
}

int AdditionalMethods :: convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AdditionalMethods :: convertIntNaString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
