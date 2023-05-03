/*Realizovati klase krug i valjak i pravougaonik
valjak treba da nasledi klase krug i pravougaonik i na osnovu metoda iz ovih klasa vratiti Povrsinu i zapreminu Valjka*/
#include <iostream>
#include <cmath>
using namespace std;
class Krug{
    protected:
    int r;
    public:
    Krug(){
        r = 5;
    }
    Krug(int n){
        r=n;
    }
    float povrsina(){
        return pow(r,2)*M_PI;
    }
    void ispis(){
        cout<<"Povrsina kruga koji ima poluprecnik"<<r<<" je "<<povrsina()<<endl;
    }
    float obim(){
        return 2*r*M_PI;
    }
};
class Pravougaonik{
    protected:
float a;
float b;
    public:
    Pravougaonik(){
        a= 10;
        b= 20;
    }
    Pravougaonik(float a, float b){
        this->a=a;
        this->b=b;
    }
    float povrsinaPravougaonika(){
        return a*b;
    }
    void ispis(){
        cout<<"Povrsina pravougaonika dimenzija"<<a<<" "<<b<<"je"<<povrsinaPravougaonika()<<endl;  
}
};
class Valjak : protected Krug, protected Pravougaonik{
private:
float v;
public:
Valjak(){
    v = 10;
}
Valjak(float r, float v):Pravougaonik(r,2*r*M_PI),Krug(r){
    this->v = v;
}
float povrsinaValjka(){
    return (2*povrsina()+povrsinaPravougaonika());
}
float Zapremina(){
    return (povrsina()*v);
}
 };
int main(){
    Valjak v1(3,5);
    cout<<"Povrsina valjka"<<v1.povrsinaValjka()<<endl;
    cout<<"Zapremina valjka"<<v1.Zapremina()<<endl;
}