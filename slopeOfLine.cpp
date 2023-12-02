#include<iostream>
using namespace std;

class LineType{
    private:
        float a;
        float b;
        float c;
    public:
        LineType(float x, float y, float z){
            c = z;
            while(x == 0 && y == 0){
                cout<< "please enter valid value for coefficient of x and y."<<endl;
                cin>>x>>y;
            }
            a = x;
            b = y;
        }
        float slope() const{
            float ans;
            if (b == 0 ){
                cout<< "line is verticle. slope is undefined.returning 0\n";
                return 0.0;
            }
            else {
                ans = (-a/b);
                return (float)ans;
            }
        }
        void checkEquality(LineType line) const{
            if ((a/line.a) == (b/line.b) && (b/line.b) == (c/line.c)){
                cout<< "Lines are equal."<<endl;
            }
            else 
                cout<<"Lines are not equal.\n";
        }
        int checkParallel(LineType line) const{
            if (b == 0  && line.b == 0){
                cout<< "both lines are parallel.\n";
                return 1;
            }
            else if ((this->slope() == line.slope()) && line.b != 0 && b !=0){
                cout<<"both lines are parallel."<<endl;
                return 1;
            }
            else 
                cout<<"lines are not parallel.\n";
                return 0;
        }
        int checkPerpendicular(LineType line) const{
            if ((a == 0  && line.b == 0) || (b == 0 && line.a == 0)){
                cout<< "both lines are perpendicular.\n";
                return 1;
            }
            else if (this->slope()*line.slope() == -1){
                cout<< "both lines are perpendicular."<<endl;
                return 1;
            }
            else 
                cout<<"lines are not perpendicular."<<endl;
                return 0;
        }
        void pointofIntersection(LineType line) const{
            float x, y;
            if (this->checkParallel(line) == 1){
                cout<<"lines are parallel so no point of intersection."<<endl;
            }
            else {
                x = ((b*line.c)- (c*line.b))/((a*line.b)-(b*line.a));
                y = ((c*line.a)- (a*line.c))/((a*line.b)-(b*line.a));
                cout<<"point of intersection is (x,y) => ("<<x<<" "<<y<<")\n";
            }
        }
};
int main(){
    LineType l1(0,3,3), l2(4,0,6);
    cout.precision(3);
    cout<<l1.slope()<<"    "<<l2.slope()<<endl;
    l1.checkEquality(l2);
    l1.checkParallel(l2);
    l1.checkPerpendicular(l2);

    return 0;
}