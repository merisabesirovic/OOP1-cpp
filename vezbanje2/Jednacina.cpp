/*Realizovati nasledjivanje Linearna->Kvadratna sa virtuelnim metodama resenje i ispis
Klasa Linarna( 2x+3=0, resenja :1)  x=-b/c za c?0   2) inace nema resenja )   sadrzi polja (b i c) .
Klasa Kvadratna(  ax2+bx+c=0,  resenja:    1) x1/2=(-b+/-sqrt(D))/2a , D>0,D=b2-4ac
                                                                     2) D<0 nema realnih resenja
                                                                     3) D=0 x=-b/2a
sadrzi dodatno polje a.
Napraviti odgovarajuce konstruktore sa i bez argumenata za obe klase ,destruktore i metodu  za ispis jednacine.Realizovati metodu resenje za obe jednacine tako da ispisuje poruku o resenju jednacine i vraca koliko resenja ima jednacina 0-nema resenja, 1-jedno resenje ,2-dva resenja.
Fomirati polimorfne metode:
A)    ispis koja ispisuje jednacinu i njeno resenje
B)     ima_resenja koja vraca tacno ako jednacina ima resenja netacno ako nema.
Testirati klasu u main f-ji.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Linearna{
protected:
float b,c;
public:
Linearna(float b, float c){
    this->b=b; this->c=c;
}
virtual void Resenja(){
    if(b==0) cout<<"nema resenja"<<endl;
    else{
        float x=-c/b;
        cout<<"Linearna jednacina ima resenja"<<endl;
        cout<<x<<endl;
    }
}
virtual void Ispis(){
    cout<<"Linearna jednacina ima oblik"<<endl;
    cout<<b<<"x + "<<c<<"=0"<<endl;
}
};
class Kvadratna : Linearna{
    protected:
    float a;
    public:
    Kvadratna(float a, float b, float c):Linearna(b,c){
        this->a=a;
    }
    void Resenja(){
        float D=b*b-4*a*c;
        if(D<0)
        cout<<"Kvadratna jednacina nema realnih resenja"<<endl;
        else if(D==0){
            float x=-b/(a*c);
            cout<<"Jednacina ima jedno resenje i to"<<x<<endl;
        }
        else{
            float x1=((-b+sqrt(D))/(2*a));
            float x2=((-b-sqrt(D))/(2*a));
            cout<<"Jednacina ima dva realna resenja"<<endl;
            cout<<"x1="<<x1<<"x2="<<x2<<endl;
        }
    }
    void Ispis(){
        cout<<"Kvadratan jednacina ima oblik"<<endl;
        cout<<a<<"x2 + "<<b<<"x + "<<c<<"=0"<<endl;
    }
};
int main(){
    Linearna l(2,5);
    Kvadratna k(3, 10, 4);
    l.Ispis();
    k.Ispis();
}