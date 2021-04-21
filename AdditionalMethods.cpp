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
