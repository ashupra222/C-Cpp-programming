#include <iostream>
#include <string>
using namespace std;

class PersonType
{
    private:
    string firstName;
    string middleName;
    string lastName;
    public:
        PersonType()
        {
            firstName = "";
            middleName = "";
            lastName = "";
        }
        PersonType(string first, string last)
        {
            firstName = first;
            lastName = last;
        }
        PersonType(string first, string middle, string last){
            firstName = first;
            middleName = middle;
            lastName = last;
        }
        void setName(string first,string middle, string last)
        {
            firstName = first;
            middleName = middle;
            lastName = last;
        }
        void setFirstName(string first){
            firstName = first;
        }
        void setMiddleName(string middle){
            middleName = middle;
        }
        void setLastName(string last){
            lastName = last;
        }
        void print() const
        {
            cout << firstName << " " << middleName <<" "<< lastName<< endl;
        }
        string getFirstName() const
        {
            return firstName;
        }
        string getMiddleName() const 
        {
            return middleName;
        }
        string getLastName() const
        {
            return lastName;
        }
        void checkFirstName(string str){
            if (firstName == str){
                cout<<"Given name matches this person's first name."<<endl;
            }
            else 
                cout<<"Given name doesn't mactch this person's first name."<<endl;
        }
        void checklastName(string str){
            if (lastName == str){
                cout<<"Given name matches this person's last name."<<endl;
            }
            else 
                cout<<"Given name doesn't mactch this person's last name."<<endl;
        }
};
int main(){
    PersonType p1;
    PersonType p2("example", "name");
    PersonType p3("an", "exam.", "name");

    p1.print();
    p1.setName("setted", "person", "name");
    p1.print();

    p2.checkFirstName("example");
    p3.checklastName("name");
    p2.checkFirstName(p3.getFirstName());

    return 0;
}