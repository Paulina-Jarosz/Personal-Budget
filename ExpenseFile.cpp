#include "ExpenseFile.h"
#include "Markup.h"

void ExpenseFile :: addExpenseToFile(Item expense)
{
    //Item incomeOb = changeIntDateFormat(income);
    //string iteamStringDate = AdditionalMethods :: convertIntToString (income.getIntDate());
    //string dateItemWithDash = AdditionalMethods :: addDashToDate(iteamStringDate);
    //income.setupStringDate(iteamStringDate);
    string amount = AdditionalMethods :: convertFloatToString (expense.getItemAmount());
    CMarkup xml;
    string FileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(FileNameWithExpenses);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getItemId() );
    xml.AddElem( "UserId", expense.getUserId() );
    xml.AddElem( "Date", expense.getItemDate() );
    //xml.AddElem( "Date", expense.getIntDate() );
    xml.AddElem( "Item", expense.getItemName() );
    xml.AddElem( "Amount", amount );

    xml.Save(FileNameWithExpenses);

}
vector <Item> ExpenseFile :: getExpenseFromFile(int idLoggedUser) {
    Item item;
    vector <Item> incomes;
    CMarkup xml;
    string FileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(FileNameWithExpenses);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true) {
            xml.IntoElem();
            //while ( xml.FindElem("User Id") == idLoggedUser ) {
            //int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            //while ( xml.FindElem("User Id") == idLoggedUser ) {
            /*xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            if ( userId == idLoggedUser ) {
                item.setupUserId(userId);*/

                xml.FindElem( "ExpenseId");
                int itemId = atoi(xml.GetData().c_str());
                item.setupItemId(itemId);
                xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            //if ( userId == idLoggedUser ) {
                item.setupUserId(userId);

                xml.FindElem( "Date");
                string itemDate = xml.GetData();
                item.setupStringDate(itemDate);

                xml.FindElem( "Item");
                string expenseName = xml.GetData();
                item.setupItemName(expenseName);

                xml.FindElem( "Amount");
                float itemAmount = atoi(xml.GetData().c_str());
                item.setupItemAmount(itemAmount);
                expenses.push_back(item);

                xml.OutOfElem();
            //}
        }
    }
    return expenses;
}
