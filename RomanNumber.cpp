#include <iostream>
#include <string>
using namespace std;
string romDig = "mdclxvi";
int decDig[] = {1000, 500, 100, 50, 10, 5, 1};
class RomanType{
    string romNum;
    int decNum;
    int romIndex(char rom){
        int i;
        for (i = 0; i < 7; i++){
            if (rom == romDig[i]){
                return i;
            }
        }
        return 7;
    }
    public:
    int romDecValue(char rom){
        int i;
        for (i = 0; i < 7; i++){
            if (rom == romDig[i]){
                break;
            }
        }
        if (i > 6) return 0;
        return decDig[i];
    }
    RomanType();
    void printRom();
    void printDec();
};

RomanType::RomanType(){
    cin>>romNum;
    decNum = 0;
    for(int i=0; i<romNum.length(); i++){
        if (i == romNum.length()-1){
            decNum = decNum + romDecValue(romNum[i]);
        }
        else if (romIndex(romNum[i])==-1) ;
        else if (romIndex(romNum[i])<= romIndex(romNum[i+1])){
            decNum = decNum + romDecValue(romNum[i]);
        }
        else {
            decNum = decNum + romDecValue(romNum[i+1])-romDecValue(romNum[i]);
            i++;
        }
    }
    
}

void RomanType::printRom(){
    cout<<romNum<<endl;
}
void RomanType::printDec(){
    cout<<decNum<<endl;
}

int main(){
    RomanType r1;
    cout<<"roman representation: ";
    r1.printRom();
    cout<<"Decimal Representation: ";
    r1.printDec();

    cout<<endl;
    return 0;
}