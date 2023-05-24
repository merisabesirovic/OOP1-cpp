/*Kreirati apstaktnu klasa Oblik i klasu Trougao i klase kvadrat.., kreirati klasu skup koja ima n oblika*/
#include <iostream>
#include <cmath>
using namespace std;
using std::string;
class Oblik{
public:
double a;
public:
Oblik()
{
    a=5;
}
virtual double Povrsina() = 0;
virtual double Obim()=0;

};
class Trougao : public Oblik{
    public:
    double b, c;
    public:
    Trougao(){
        b=2;
        c=3;
    }
    double Povrsina(){
        double S = (a+b+c)/2;
        return sqrt(S*(S-a)*(S-b)*(S-c));
    }
    double Obim(){
        return a+b+c;}
};
class Kvadrat:public Oblik{
public:
double Povrsina(){return a*a;};
double Obim(){return a*4;}
};
class Skup{
    public:
    Oblik* *oblici;
    int broj;
    int trenutno=0;
    public:
    Skup(int b){
        broj = b;
        oblici = new Oblik*[broj];
    }
    void dodajOblik(Oblik *o){
        oblici[trenutno++] = o;
    }
    double ukupnaPovrsina(){
        double s=0;
        for(int i = 0; i < trenutno; i++){
            s+= oblici[i]->Povrsina();
        }
        return s;
    }
};