#include<iostream>
#include<string>
using namespace std;
string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int dayInDays(string d){
    for (int i=0; i<7; i++){
        if (d == days[i]) return 1;
    }
    return 0;
}
int indexofDay(string d){
    for(int i=0; i<7;i++)
        if(d == days[i]) return i;
    return -1;
}

class DayType{
    string day;
    string nextDay(string d){
        for(int i = 0 ; i<6; i++){
            if (d == days[i]){
                return days[i+1];
            }
        }
        return days[0];
        
    }
    string prevDay(string d){
        if (d == days[0]) {
            return days[6];
        }
        int i = 1;
        for(i = 1 ; i<7; i++){
            if (d == days[i]){
                break;
            }
        }
        return days[i-1];
    }
    public:
    DayType(){
        day = days[1];
    }
    DayType(string d){
        if (dayInDays(d)) day = d;
        else {
            day = days[0];
            cout<<"Initialized with Sunday instead of the given day cause given day is inappropriate.\n";
        }
    }
    void setDay(string d){
        if (dayInDays(d)) day = d;
        else cout<<"Can't able to set the given day cause given day is inappropriate.\n";
    }
    void printDay(){
        cout<<day<<endl;
    }
    string returnDay(){
        return day;
    }
    string returnNextDay(){
        return nextDay(day);
    }
    string returnPrevDay(){
        return prevDay(day);
    }
    string addDays(int num){
        if (num >6){
            num = num % 7;
        }
        if (num == 0) {
            return day;
        }
        else if (num < 4){
            for (int i=0; i<num; i++){
                day = nextDay(day);
            }
        }
        else {
            for (int i=num; i<7; i++){
                day = prevDay(day);
            }
        }
        return day;
    }
};