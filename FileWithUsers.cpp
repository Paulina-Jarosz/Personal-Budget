#include "FileWithUsers.h"
#include "Markup.h"

FileWithUsers :: FileWithUsers(){
    fileNameWithUsers = "Users.xml";
}

void FileWithUsers :: addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load(fileNameWithUsers);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserID", user.getUserId() );
    xml.IntoElem();
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );
    xml.AddElem( "Name", user.getUserName() );
    xml.AddElem( "Surname", user.getUserSurname() );

    xml.Save(fileNameWithUsers);

}

vector <User> FileWithUsers :: loadUserFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            user.setupUserId(userId);
            xml.IntoElem();
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setupLogin(login);
            xml.FindElem( "Password");
            string password = xml.GetData();
            user.setupPassword(password);
            xml.FindElem( "Name");
            string userName = xml.GetData();
            user.setupUserName(userName);
            xml.FindElem( "Surname");
            string userSurname = xml.GetData();
            user.setupUserSurname(userSurname);
            users.push_back(user);

            xml.OutOfElem();
            xml.OutOfElem();
        }
    }

    return users;
}

bool FileWithUsers :: checkLogin(string login) {
    CMarkup xml;
    bool fileExists = xml.Load(fileNameWithUsers);
    xml.Load(fileNameWithUsers);
    xml.SetDoc( fileNameWithUsers );

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("LOGIN") ) {
        if ( xml.GetChildData() == login ) {
            return true;
        }
    }
    return false;
}

