#include "FileWithUsers.h"
#include "Markup.h"

FileWithUsers :: FileWithUsers(){
    fileNameWithUsers = "Users.xml";
}

void FileWithUsers :: addUserToFile(User user)
{
    CMarkup XmlFile;
    XmlFile.Load(fileNameWithUsers);
    //XmlFile.AddElem( "ROOT" );
    //XmlFile.IntoElem();
    XmlFile.AddElem( "USERID", user.getUserId() );
    XmlFile.IntoElem();
    XmlFile.AddElem( "LOGIN", user.getLogin() );
    XmlFile.AddElem( "PASSWORD", user.getPassword() );
    XmlFile.AddElem( "NAME", user.getUserName() );
    XmlFile.AddElem( "SURNAME", user.getUserSurname() );

    XmlFile.Save(fileNameWithUsers);

}

bool FileWithUsers :: checkLogin(string login) {
    CMarkup XmlFile;
    //bool bSuccess  = XmlFile.Load(fileNameWithUsers);
    XmlFile.Load(fileNameWithUsers);
    XmlFile.SetDoc( fileNameWithUsers );

    XmlFile.ResetPos();
    XmlFile.FindElem();
    XmlFile.IntoElem();
    while ( XmlFile.FindElem("LOGIN") ){
        if ( XmlFile.GetChildData() == login ) {
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
