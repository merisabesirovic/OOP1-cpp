#include <iostream>
#include <cmath>
using namespace std;
class Linearna{
    protected:
    float b,c;
    public:
    Linearna(float b, float c){
        this->b = b;
        this->c = c;
    }
    virtual void Resenja(){
        if(b==0) cout<<"nema resenja";
        else{
        float x=-c/b;
        cout<<"Linearna jednacina ima resenje"<<x<<endl;
        }
    }
    virtual void Ispis(){
        cout<<"Linearna jednacina ima oblik "<<endl;
        cout<<b<<"x + "<<c<<"=0"<<endl;
    }
};
class Kvadratna : Linearna{
    protected:
    float a;
    public:
    Kvadratna(float a, float b, float c) : Linearna(b,c){
        this->a = a;
    }
    void Resenja(){
        float D=b*b-4*a*c;
        if(D<0){
            cout<<"Kvadratna jednacina nema resenja (realna)"<<endl;
        }
        else if(D==0){
            float x=-b/(2*a);
            cout<<"Jendaicna ima jedno resenje i to je "<<x<<endl;
        }
        else{
            float x1 = ((-b+sqrt((D))/(2*a)));
            float x2 = ((-b-sqrt((D))/(2*a)));
            cout<<"Jednacina ima dva realna resenja i to su"<<endl;
            cout<<"x1="<<x1<<" x2="<<x2<<endl;
        }
    }
    void Ispis(){
        cout<<"Kvadratna jednacina je oblika"<<endl;
        cout<<a<<"x2 +"<<b<<"x + "<<c<<" =0"<<endl;
    }

};
 int main(){
    Linearna l(2,5);
    Kvadratna k(3,10,4);
    l.Ispis();
    k.Ispis();
    l.Resenja();
    k.Resenja();
    return 0;
 }