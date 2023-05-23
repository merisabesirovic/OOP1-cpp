#include <iostream>
#include <cmath>
using namespace std;
class Krug{
int r;
public:
    Krug(){
        r=6;
    }
    Krug(int r){
        this->r = r;
    }
    virtual float Povrsina(){
        return r*r*M_PI;
    }
    void setPP(int r){
        this->r = r;
    }
    int getPP(){
        return r;
    }
};
class KruzniIsecak : public Krug{
int ugao;
public:
KruzniIsecak(int ugao, int r) : Krug(r){
    this->ugao = ugao;
}
float Povrsina(){
    return (Krug::Povrsina() * ugao)/360;
}
};
class KruzniPrsten : public Krug{
    Krug *unutrasnji;
    public:
    KruzniPrsten(int ppu, float pps) : Krug(pps){
        unutrasnji = new Krug(ppu);
    }
    float Povrsina(){
        return Krug::Povrsina() - unutrasnji->Povrsina();
    }
};
int main(){
    Krug k(2);
    KruzniIsecak ki(2,180);
    KruzniPrsten kp(2,5);
    cout<<"povrsina kruga "<<k.Povrsina()<<endl;
    cout<<"povrsina kruznog isecka "<<ki.Povrsina()<<endl;
    cout<<"povrsina kruznog prstena "<<kp.Povrsina()<<endl;
    
}