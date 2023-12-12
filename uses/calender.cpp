#include <iostream>
#include "dayOfWeek.h"
using namespace std;

class DateType
{
public:
    DateType(int day = 1, int month = 1, int year = 1900)
    {
        setDate(day, month, year);
    }
    void setDate(int day, int month, int year)
    {
        if(year >= 1500) dYear = year;
        else {
            dYear = 1900;
            cout<<"year is less than 1500. year initialized to 1900.\n";
        }
        if(month >0 && month <= 12) dMonth = month;
        else {
            dMonth = 1;
            cout<<"inappropriate month given. initialized to 1.\n";
        }
        if(day > 0 && day <= this->daysInThisMonth()) dDay = day;
        else {
            dDay = 1;
            cout<<"given date is not in the given month so initialized with 1.\n";
        }
    }
    void setDay(int day){
        if(day > 0 && day <= this->daysInThisMonth()) dDay = day;
        else {
            dDay = 1;
            cout<<"given date is not in the given month so initialized with 1.\n";
        }
    }
    void setMonth(int month){
        if(month >0 && month <= 12) dMonth = month;
        else {
            dMonth = 1;
            cout<<"inappropriate month given. initialized to 1.\n";
        }
    }
    void setYear(int year){
        if(year >= 1500) dYear = year;
        else {
            dYear = 1900;
            cout<<"year is less than 1500. year initialized to 1900.\n";
        }
    }
    int getDay() const
    {
        return dDay;
    }
    int getMonth() const
    {
        return dMonth;
    }
    int getYear() const
    {
        return dYear;
    }
    void printDate() const
    {
        cout <<dDay << "-" << dMonth  <<  "-" << dYear;
    }
    bool isLeapYear(){
        if (dYear%400 == 0) return true;
        else if (dYear % 100 == 0) return false;
        else if (dYear % 4 == 0) return true;
        else return false; 
    }
    int daysInThisMonth(){
        if (dMonth == 2 && this->isLeapYear()) return 29;
        else if (dMonth == 2) return 28;
        else if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11) return 30;
        else return 31;
    }
    int daysPassedInYear(){
        int m = dMonth;
        int dayPassed =0;
        for (dMonth = 1; dMonth<m; dMonth++){
            dayPassed += this->daysInThisMonth();
        }
        return dayPassed+dDay;
    }
    int daysRemainingInYear(){
        if(this->isLeapYear()){
            return 366 - this->daysPassedInYear();
        }
        else return 365 - this->daysPassedInYear();
    }
    void addDays(int days){
        while(days > 0){
            int daysLeftInThisMonth = this->daysInThisMonth()-dDay;
            if (days > daysLeftInThisMonth){
                if (dMonth != 12){
                    dMonth++;
                    dDay =1;
                }
                else {
                    dYear++;
                    dMonth = 1;
                    dDay = 1;
                }
                days -= daysLeftInThisMonth +1;
            }
            else {
                dDay += days;
                days =0;
            };
        }
    }
    void printMonth(bool nextline = false){
        cout<<months[(this->getMonth()-1)]<<" "<<this->getYear();
        if (nextline) cout<<endl;
    }
private:
    string months[12] = {"January", "February", "March",
                         "April",   "May",      "June", 
                         "July",    "August",   "September",
                         "Octomber","November", "December"};
    int dMonth; 
    int dDay;   
    int dYear; 
};

class CalenderType{
    private:
    DayType day;
    DateType date;
    int leapYears(int start, int end){
        int a = (start/4)-(start/100)+(start/400);
        int b = (end/4)-(end/100)+(end/400);
        return b-a;
    }
    public:
    CalenderType(int month, int year):date(1, month, year){
        this->firstDayofMonth();
    }
    void firstDayofMonth(){
        int lpyr = leapYears(1500, date.getYear());
        int days = ((date.getYear()-1500)*365)+lpyr;
        int actualMonth = date.getMonth();
        for(int i = 1; i<actualMonth;i++){
            date.setMonth(i);
            days = days + date.daysInThisMonth();
        }
        date.setMonth(actualMonth);
        day.setDay("Monday");
        day.addDays(days);
    }

    void setMonth(int month){
        date.setMonth(month);
        this->firstDayofMonth();
    }
    void setYear(int year){
        date.setYear(year);
        this->firstDayofMonth();
    }
    int getMonth(){
        return date.getMonth();
    }
    int getYear(){
        return date.getYear();
    }
    void printCalender(){
        cout<<"\t";
        date.printMonth(true);
        cout<<"Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        int din = date.getDay(), month = date.getMonth(), year = date.getYear();
        int count=0;
        for (int i=0; i<7; i++){
            if (days[i] == day.returnDay() && month == date.getMonth()) {
                if (date.getDay() < 10) cout<<"  "<<date.getDay()<<"  ";
                else cout<< " "<<date.getDay()<<"  ";
                date.addDays(1);
                day.addDays(1);
            }
            else cout<<"     ";
            if( i == 6 && month == date.getMonth() && count < 6) {
                i = -1;
                count++;
                cout<<endl;
            }
        }
        cout<<endl;
        date.setDate(din, month, year);
    }
};

int main(){
    int m,y;
    cout<<"Enter month and year to print calender:";
    cin>>m>>y;
    CalenderType d(m, y);    
    d.printCalender();

    return 0;
}