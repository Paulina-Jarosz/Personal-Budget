#include "IncomeFile.h"
#include "Markup.h"

void IncomeFile :: addIncomeToFile(Item income)
{
    //Item incomeOb = changeIntDateFormat(income);
    //string iteamStringDate = AdditionalMethods :: convertIntToString (income.getIntDate());
    //string dateItemWithDash = AdditionalMethods :: addDashToDate(iteamStringDate);
    //income.setupStringDate(iteamStringDate);
    string amount = AdditionalMethods :: convertFloatToString (income.getItemAmount());
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "Income Id", income.getItemId() );
    xml.AddElem( "User Id", income.getUserId() );
    xml.AddElem( "Date", income.getItemDate() );
    //xml.AddElem( "Date", income.getIntDate() );
    xml.AddElem( "Item", income.getItemName() );
    xml.AddElem( "Amount", amount );

    xml.Save(fileNameWithIncomes);

}
vector <Item> IncomeFile :: getIncomeFromFile(int idLoggedUser) {
    Item item;
    vector <Item> incomes;
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") == true) {
            xml.IntoElem();
            //while ( xml.FindElem("User Id") == idLoggedUser ) {
                //int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
                //while ( xml.FindElem("User Id") == idLoggedUser ) {
                xml.FindElem("User Id");
                int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
                if ( userId == idLoggedUser ){
                item.setupUserId(userId);

                xml.FindElem( "Income Id");
                int itemId = atoi(xml.GetData().c_str());
                item.setupItemId(itemId);

                xml.FindElem( "Date");
                string itemDate = xml.GetData();
                item.setupStringDate(itemDate);

                xml.FindElem( "Item");
                string incomeName = xml.GetData();
                item.setupItemName(incomeName);

                xml.FindElem( "Amount");
                float itemAmount = atoi(xml.GetData().c_str());
                item.setupItemAmount(itemAmount);
                incomes.push_back(item);

            }
            else
            xml.OutOfElem();
        }
    }
    return incomes;
}

/*int IncomeFile  :: getLastItemId(){
    int lastItemId = 0;

    system("cls");
    if (!incomes.empty())
    {
        for (vector <Item>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr -> getItemId() == lastItemId)
            {
                 cout <<"id to : " <<lastItemId << endl; //return lastItemId;
            }
        }
    }
    else
    {
        cout << endl << "There is no item" << endl << endl;
    }
    cout << endl;
    system("pause");


return lastItemId;
}*/

Item IncomeFile :: changeIntDateFormat(Item income){

    Item incomeOb;
    int itemId = income.getItemId();
    incomeOb.setupItemId(itemId);
    int userId = income.getUserId();
    incomeOb.setupUserId(userId);
    //string itemDate;
    string itemName = income.getItemName();
    incomeOb.setupItemName(itemName);
    float itemAmount = income.getItemAmount();
    incomeOb.setupItemAmount(itemAmount);

    string iteamStringDate = AdditionalMethods :: convertIntToString (income.getIntDate());
    string dateItemWithDash = AdditionalMethods :: addDashToDate(iteamStringDate);
    incomeOb.setupStringDate(dateItemWithDash);
    cout << "po zmienie formatu data: " << dateItemWithDash <<endl;
     return incomeOb;
}
