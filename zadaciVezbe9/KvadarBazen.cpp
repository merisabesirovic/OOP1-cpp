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
    Kvadar(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
        cout<<"Pozvao se konstuktor sa argumentima"<<endl;
    }
    Kvadar(){
        a = 5;
        b = 10;
        c = 4;
        cout<<"Pozvao se konstuktor bez argumenata"<<endl;
    }
    void ispis(){
        cout<<"Dimenzije su "<<a<<","<<b<<","<<c<<endl;
    }};
    class Bazen : Kvadar{
        protected:
        int d;
        public:
        Bazen(){
            d = 3;
        }
        void ispis(){
            Kvadar :: ispis();
            cout<<"Dubina napunjena vodom je: "<<d<<endl;
        }

    };
int main(){
    Kvadar k;
    Bazen b;
    k.ispis();
    b.ispis();

}