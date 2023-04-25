// Realizovati klase Prava i Kvadrat. 
// Klasa Prava ima atribute x1,y1,x2,y2,d. 
// Metode: Konstruktor sa i bez argumenata, 
// set i get metode, 
// metoda racunajDuzinu() i metodu ispis(). 
// Kvadrat ima atribute:Prava vrh,Prava dno 
// Metode:Konstruktor sa i bez argumenata, povrsina(),obim() i ispis().
#include <iostream>
#include <cmath>
using namespace std;
class Prava{
float x1, y1, x2, y2;
public:
    Prava(){
        cout<<"Unesite koordinate x1 i y1"<<endl;
        cin>>x1>>y1;
        cout<<"Unesite koordinate x2 i y2"<<endl;
        cin>>x2>>y2;
    }
    Prava(float x1, float y1, float x2, float y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void setx1(float a){
        x1=a;
    }
    void sety1(float a){
        y1 = a;
    }
    void setx2(float a){
        x2 = a;
    }
    void sety2(float a){
        y2 = a;
    }
    float getx1(){
        return x1;
    }
    float gety1(){
        return y1;
    }
    float getx2(){
        return x2;
    }
    float gety2(){
        return y2;
    }
    float racunajDuzinu(){
    return sqrt(pow(x2-x1, 2)+ pow(y2-y1,2));
    }
    void ispis(){
        cout<<"Koordinate x1 i y1"<<x1<<","<<y1<<endl;
        cout<<"Koordinate x2 i y2"<<x2<<","<<y2<<endl;
    }
};
class Kvadrat {
    private:
    Prava vrh, dno;
    public:
    Kvadrat(){
        vrh.setx1(1);
        vrh.sety1(1);
        vrh.setx2(1);
        vrh.sety2(1);
        dno.setx1(1);
        dno.sety1(1);
        dno.setx2(1);
        dno.sety2(1);
    }
    Kvadrat(Prava po1, Prava po2){
        vrh.setx1(po1.getx1()); vrh.sety1(po1.gety1()); vrh.setx2(po1.getx2()); vrh.sety2(po1.gety2());
        dno.setx1(po2.getx1()); dno.sety1(po2.gety1()); dno.setx2(po2.getx2()); dno.sety2(po2.gety2()); }

    float Povrsina(){
        return pow(vrh.racunajDuzinu(),2);
    }
    float Obim(){
        return vrh.racunajDuzinu()*4;
    }
    void ispis2 (){ 
cout << "Povrsina=" << Povrsina() << " Obim=" << Obim() << endl; }
};
int main(){
Prava po1(0,10,10,10), po2; 
Kvadrat ko1; 
ko1.ispis2(); 
return 0; 

}