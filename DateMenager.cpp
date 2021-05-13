#include "DateMenager.h"

bool DateMenager :: isDateCorrect (string date){

    Date dateOb = divideDate(date);
    if (isValidDate(dateOb) == true){
            return true;
    }
    else return false;
}

Date DateMenager :: divideDate(string date){

    Date dateOb;
    string day, month, year;
    string dateDivided = "";
    int countNum =1;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            dateDivided += date[i];
        } else {
            switch(countNum) {
            case 1:
                dateOb.setYear(dateDivided);
                break;
            case 2:
                dateOb.setMonth(dateDivided);
                break;
            }
            dateDivided = "";
            countNum++;
        }
        if (date[i] != ' ' ) {
            dateOb.setDay(dateDivided);
        } else cout << "incorrect date"<<endl;
    }
    showDate(dateOb);
    return dateOb;
}

int DateMenager :: convertStringDateToInt(string date)
{
    int numberInt;
    istringstream iss(date);
    iss >> numberInt;

    return numberInt;
}

bool DateMenager :: isValidYear (int year) {

    if (year > MAX_VALID_YR || year < MIN_VALID_YR) {
        return false;
    }
    return true;
}

bool DateMenager :: isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

bool DateMenager :: isValidDay (int dayConverted, int monthConverted, int yearConverted) {

    if (monthConverted == 2) {
        if ((isLeap(yearConverted) == true) && (dayConverted == 29)) {
            //if (dayConverted >= 1 && dayConverted <= 29)
                return true;
        } else if (dayConverted >= 1 && dayConverted <= 28)
        {
            return true;
        }
        else if (dayConverted < 1 && dayConverted >= 30)
        {
            return false;
        }
    }

    else if (monthConverted == 4 || monthConverted == 6 ||
             monthConverted == 9 || monthConverted == 11) {
        if (dayConverted >= 1 && dayConverted <= 30) {
            return true;
        } else return false;
    }
}

bool DateMenager :: isValidDate(Date dateOb)
{
    string year = dateOb.getYear();
    string month = dateOb.getMonth();
    string day = dateOb.getDay();
    int monthConverted = convertStringDateToInt(month);
    int yearConverted = convertStringDateToInt(year);
    int dayConverted = convertStringDateToInt(day);

    cout << "konwertowany miesiac : "<<monthConverted <<endl;

    if (isValidYear (yearConverted) == false) {
        return false;
    } else if (isValidMonth(monthConverted) == false) {
        return false;
    } else if (dayConverted >= 1 && dayConverted <= 31) {
        if (isValidDay(dayConverted,monthConverted,monthConverted) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool DateMenager :: isLeap(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else return false;
}

string DateMenager :: currentDate(){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%Y-%m-%d",timeinfo);
  std::string str(buffer);

  std::cout << str;
  return str;
}

void DateMenager :: showDate(Date dateOb)
{
    cout << endl << "Rok: " << dateOb.getYear() << endl;
    cout << "miesiac: " << dateOb.getMonth() << endl;
    cout << "dzien: " << dateOb.getDay() << endl;
}
