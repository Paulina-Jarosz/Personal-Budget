#include "FileWithUsers.h"
#include "Markup.h"

FileWithUsers :: FileWithUsers(){
    fileNameWithUsers = "Users.xml";
}

void FileWithUsers :: addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( "Users.xml" );
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
    bool fileExists = xml.Load( "Users.xml" );

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int userId = atoi( MCD_2PCSZ(xml.GetData()));
            user.setupUserId(userId);
            xml.IntoElem();
            xml.FindElem( "Login");
            string login = xml.GetData().c_str();
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
    bool fileExists = xml.Load( "Users.xml" );
    xml.Load(fileNameWithUsers);
    xml.SetDoc( fileNameWithUsers );

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("LOGIN") ){
        if ( xml.GetChildData() == login ) {
            return true;
        }
    }
return false;
}

int FileWithUsers :: findLastUserId(){
    int lastUserId;
     CMarkup XmlFile;
    XmlFile.Load("C:\\1-PersBudget\\Users.xml");
    //XmlFile.SetDoc( fileNameWithUsers );

    XmlFile.ResetPos();
    XmlFile.FindElem();
    //XmlFile.IntoElem();
    while ( XmlFile.FindElem("USERID") ){
        lastUserId = atoi( MCD_2PCSZ(XmlFile.GetData()));
        cout<< " Last user ID is: "<< endl;
        cout << lastUserId << endl;
        }
return lastUserId;

}
