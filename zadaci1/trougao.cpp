/**
 ** In line f-je preporuka kompajleru da se na mestu poziva f-je umetne njen kod cime se vrsi usteda.
 ** D je f-ja inline oznacavamo prefiksom inline i koristi se samo kod jako malih  f-ja
 ** f-je koju su definisane unutar definicije klase su inline
**/
/*
   Realizovati klasu Trougao koja ima tri privatna atributa a,b i c (realne vrednosti)
   i metode: inicijalizacija(a,b,c) postavlja vrednosti atributa na vrednosti argumenata;
   pisi - metoda koja ispisuje podatke o atributima a,b i c;
   P() - metoda koja racuna povrsinu trougla; O() racuna i vraca obim trougla;
*/
#include <iostream>
#include <math.h>
using namespace std;
class Trougao{
    int a, b,c;
    public:
    void inicijaliazacija(int a, int b, int c){
        this->a = a; this->b = b; this->c = c;
    };
    void pisi(){
        cout << "Duzina stranice a je "<<a<<" b "<<b<<" c "<<c<<endl;
    };
    float P(){
        double s=(a+b+c)/2.0;
        return (sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    int O(){
        return (this->a+this->b+this->c);
    }
};
int main(){
    Trougao ABC;
    ABC.inicijaliazacija(3,3,3);
    ABC.pisi();
    cout << ABC.O() << endl;
    cout << ABC.P() << endl;

}