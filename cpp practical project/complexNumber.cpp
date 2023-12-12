#include<iostream>
#include<string>
using namespace std;

int stToInt(char s){
    switch (s)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    
    default:
        return -1;
        break;
    }
}

class Complex{
    private:
    double real, imaginary;
    public:
    Complex(double r=0, double i=0){
        real = r;
        imaginary = i;
    }
    void setValue(double r=0, double i=0){
        real = r;
        imaginary = i;
    }
    void getValue(double& r, double& i){
        r = real;
        i= imaginary;
    }
    Complex& strToCmplx(string s){
        double r = 0 , im= 0;
        int x;
        bool dot = false;
        bool alphai = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] != '.' && s[i] != ' ' && s[i] != '+' && s[i] != 'i'){
                x = stToInt(s[i]);
            }
            else if (s[i] == '.'){
                dot = true;
                continue;
            }
            else if (s[i] == ' ' && s[i] != '+') continue;
            else if (s[i] == 'i'){
                alphai = true;
                dot = false;
                continue;
            }
            else continue;
            if (dot == false && alphai == false){
                r = r*10 + x;
            }
            else if (dot && alphai == false){
                r = r + (x/10.0);
            }
            else if (dot == false && alphai){
                im = im*10 +x;
            }
            else if (dot && alphai){
                im = im + (x/10.0);
            }
        }
        real = r;
        imaginary = im;
        return *this;
    }
    friend ostream& operator<<(ostream& osObj, Complex& c1);
    friend istream& operator>>(istream& isObj, Complex& c1);
    Complex& operator=(string s){
        strToCmplx(s);
        return *this;
    }
    Complex& operator+(Complex cOther){
        Complex* result = &cOther;
        result->real += this->real;
        result->imaginary += this->imaginary;
        return *result;
    }
    Complex operator*(Complex& cOther){
        Complex temp = cOther;
        temp.real = (real * cOther.real) - (imaginary * cOther.imaginary);
        temp.imaginary = (imaginary * cOther.real) + (cOther.imaginary * real);
        return temp; 
    }
    bool operator==(Complex& cOther){
        return (real == cOther.real && imaginary == cOther.imaginary); 
    }
};
ostream& operator<<(ostream& osObj, Complex& c1){
    osObj << c1.real;
    osObj << " + i";
    osObj << c1.imaginary;
    return osObj;
}
istream& operator>>(istream& isObj, Complex& c1){
    string s;
    getline(isObj, s);
    c1.strToCmplx(s);
    return isObj;
}
int main(){
    Complex c1, c2 , c3;
    c1 = "5 + i5";
    cin>>c2;
    c3 = c1 * c2;
    cout<< c1<< endl<<c2<<endl<<c3<<endl;
    if(c1==c2) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}