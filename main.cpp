#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>


using namespace std;

struct fraction
{
    int nominator;
    int denominator;

};
int euclid (int a, int b){
    if (a == 0) return b;
    if (b ==0) return a;
    return(euclid(b, a%b));

}
fraction get_frac(int nom, int denom){
    fraction fr;
    fr.nominator = nom;
    fr.denominator = denom;
    return fr;
}
fraction cutter(fraction f){
    int gcd = euclid(f.nominator, f.denominator);
    f.nominator /= gcd; f.denominator /= gcd;
    return f;
}
fraction operator+ (fraction x, fraction y){
    fraction sum;
    sum.nominator = x.nominator*y.denominator + x.denominator*y.nominator;
    sum.denominator = x.denominator*y.denominator;
    sum = cutter(sum);
    return sum;
}

fraction operator- (fraction x, fraction y){
    fraction subtract;
    subtract.nominator = x.nominator*y.denominator - x.denominator*y.nominator;
    subtract.denominator = x.denominator*y.denominator;
    subtract = cutter(subtract);
    return subtract;
}
fraction operator* (fraction x, fraction y){
    fraction multiply;
    multiply.nominator = x.nominator*y.nominator;
    multiply.denominator = x.denominator*y.denominator;
    multiply = cutter(multiply);
    return multiply;
}
fraction operator/ (fraction x, fraction y){
    fraction divide;
    divide.nominator = x.nominator*y.denominator;
    divide.denominator = x.denominator*y.nominator;
    divide = cutter(divide);
    return divide;
}
bool operator> (fraction x, fraction y){
    x = cutter(x);
    y = cutter(y);
    int a = x.nominator*y.denominator;
    int b = x.denominator*y.nominator;
    if (a>b) return true;
    return false; // <, ==
}
bool operator== (fraction x, fraction y){
    x = cutter(x);
    y = cutter(y);
    if((x.denominator == y. denominator)&&(x.nominator == y. nominator)) return true;
    return false;
}
bool operator< (fraction x, fraction y){
    x = cutter(x);
    y = cutter(y);
    int a = x.nominator*y.denominator;
    int b = x.denominator*y.nominator;
    if (a<b) return true;
    return false; // <, ==
}
bool operator<=(fraction x, fraction y){
    if (x==y) return true;
    return (x<y);
}
bool operator>=(fraction x, fraction y){
    if (x==y) return true;
    return x>y;
}
void frac_test(){
    int a, b, c, d;
    cout <<"enter 4 numbers:"<<endl;
    cin >> a >> b >>c >> d;
    fraction x =get_frac(a, b);
    fraction y = get_frac(c, d);
    fraction z = x+y;
    cout <<"sum="<<z.nominator <<'/'<<z.denominator<< endl;
    z = x-y;
    cout <<"subt="<<z.nominator <<'/'<<z.denominator<< endl;
    z = x*y;
    cout <<"mult="<<z.nominator <<'/'<<z.denominator<< endl;
    z = x/y;
    cout<<"div="<<z.nominator <<'/'<<z.denominator<< endl;
    bool res = x>y;
    cout <<"x>y "<<res<<endl;
    res = x<y;
    cout <<"x<y "<<res<<endl;
    res = x==y;
    cout <<"x==y "<<res<<endl;
    res = x>=y;
    cout <<"x>=y "<<res<<endl;
    res = x<=y;
    cout <<"x<=y "<<res<<endl;
}
void sum_replace(){
    string s;
    getline(cin, s);
    string a="", b="";
    unsigned int j=0, k=0;
    int x, y;
    for(int i=0;i<s.size();++i){
        if (isdigit(s[i])){
            k=i;       //запоминаем индекс, с которого начинается первое число
            while (isdigit(s[i]))
                {a+=s[i]; ++j; ++i; }
        if((s[i]=='+')&&(isdigit(s[i+1]))){
            j=0;
            ++i;
            while (isdigit(s[i]))
            {b+=s[i]; ++j; ++i;}}
        x = stoi(a); // конвертирует строку в целое число
        y = stoi(b);
        x +=y;
        a = to_string(x);
        s.replace(k, i-k, a);
        i=k+a.size()-1;
        a="";
        b="";

    }}
    cout<<s;


}
enum direction {Up, Down, Right, Left};

class OffTheField{
public:
    OffTheField(int x, int y, direction d){
    a = x; b = y; drctn = d;
    }
    int a, b;
    direction drctn;

};
class IllegalCommand{
public:
    IllegalCommand(int com)
    {s = com;}
    int s;
};

struct robot{
    int x, y; //position
    void move(int a){
        if (a<0||a>3) throw IllegalCommand(a);
        direction d = static_cast<direction>(a); // magic code
        switch(d){
            case Up: if (y==10) {throw OffTheField(x,y,Up);}; ++y; break;
            case Down:  if (y==1) {throw OffTheField(x,y,Down);}; --y; break;
            case Right: if (x==10) {throw OffTheField(x,y,Right);};++x; break;
            case Left: if (x==1) {throw OffTheField(x,y,Left);};--x; break;
            default: throw IllegalCommand(a);
        }
    }
};

robot* new_robot(){
     robot* r2d2 = new struct robot ;
     r2d2->x=1+rand()%10;
     r2d2->y=1+rand()%10;
     return  r2d2;
}


int main() {
    robot* r2d2 = new_robot();
    cout<<r2d2->x<<r2d2->y<<endl;
    int a;
    for(int i=0; i<5; ++i){
        try{
        cin>>a;
        r2d2->move(a);}
    catch(OffTheField e)
    {cerr <<"OffTheField "<<e.a<<"."<<e.b<<", dir: "<<e.drctn<<endl; return EXIT_FAILURE;}
    catch(IllegalCommand e){
        cerr<<"IllegalCommand "<<e.s<<endl;
        return EXIT_FAILURE;
    }
    cout<<r2d2->x<<r2d2->y<<endl;
    }
    return 0;
}