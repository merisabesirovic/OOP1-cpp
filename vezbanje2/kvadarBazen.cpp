// Realizovati klase Kvadar i Bazen (klasa Bazen nasleđuje klasu Kvadar).
// Klasa Kvadar ima zaštićene celobrojne atribute a,b i c.
// Metode: konstruktor sa i bez argumenata i metodu ispis().
// Klasa Bazen ima a,b,c i d (gde je d dubina vode u bazenu).
// Metode konstruktor bez argumenata, void ispis().
// Kako bi se smanjio kod gde je god moguće pozvati metode bazne klase (Kvadar).

#include <iostream>
using namespace std;
class Kvadar{
protected:
int a, b, c;
public:
Kvadar(){
    a=4;
    b=4;
    c=4;

    cout<< "Kvadar ima"<<a<<" "<<b<<" "<<c<< "Pozvao se konstruktor bez argumenata"<<endl;
}
Kvadar(int a, int b, int c){
    this->a=a;
    this->b=b;
    this->c=c;
    cout << "Pozvao se konstruktor sa argumentima"<<endl;
}
void ispis(){
     cout<< "Kvadar ima"<<a<<" "<<b<<" "<<c<<endl;
}
};
class Bazen : public  Kvadar{
    int d;
    public:
    Bazen():Kvadar(){
        d=50;
    }
    void ispis(){
        Kvadar::ispis();
        cout<<" d "<<d<<endl; 
    }

};
int main(){
    Kvadar k;
    Kvadar k1(8,8,8);
    k.ispis();
    k1.ispis();
    Bazen b;
    b.ispis();

}