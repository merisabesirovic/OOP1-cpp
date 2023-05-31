/*) (укупно 70 поена) Написати на језику C++ следеће класе (класе опремити оним конструкторима,
деструктором и оператором за доделу вредности који су потребни за безбедно коришћење класа):
• (30 поена) Домина садржи два целобројна поља (a,b) – подразумевано (0,0). Може да се
дохвати вредност првог и другог поља домине, да се изврши међусобна замена поља (~dom), да
се одреди да ли су две домине једнаке (dom1==dom2) не водећи рачуна о редоследу поља и да
се домина упише у излазни ток (it<<dom) у облику (a,b).
• Апстрактан скуп домина садржи произвољан број различитих домина. Ствара се празан после
чега се домине додају појединачно и смештају у скуп по неком непознатом редоследу
(skup+=dom). Повратна вредност при додавању представља индикатор успеха. Може да се
испита да ли се нека домина налази у скупу и да се скуп упише у излазни ток уписивањем садржаних домина.
• (30 поена) Кутија је скуп домина код које се домине додају на крај скупа. Може да се напуни
свим могућим доминама, по случајном редоследу, с вредностима поља у опсегу од 0 до n−1
(број таквих домина је n(n+1)/2, пуњење може да се врши по систему покушаја стављања у
кутију случајно генерисане домине док се кутија не напуни) и да се узме домина са почетка
кутије (uzmi(dom); повратна вредност је индикатор успеха). Библиотечка функција rand()
при сваком позивању даје случајан цео број у опсегу [0,RAND_MAX].
• Табла је скуп домина код којег се домине додају на почетак или крај тако да суседна поља
суседних домина буду једнака (тј. да друго поље претходне домине буде једнако првом пољу
наредне домине).
(10 поена) Написати на језику C++ програм који направи једну кутију и једну таблу, напуни
кутију за фиксно одабрани параметар n, испише кутију на главном излазу, узима домине из
кутије и ставља их на таблу све док може и испише завршни садржај табле на главном излазу. */
#include <iostream>
using namespace std;
using std::string;
class Domina{
int a;
int b;
public:
Domina(){
    a=0;
    b=0;
}
Domina(int a, int b){
    this->a=a;
    this->b=b;
}
int getA()const{return a;}
int getB()const{return b;}

void zameni(){
    int pom=a;
    a=b;
    b=pom;
}
bool operator==(const Domina &d1){
    return ((a==d1.a && b==d1.b)||(a==d1.b && b==d1.a));
}
friend ostream& operator<<(ostream &os, Domina &d){
    os<<d.a<<" "<<d.b<<endl;
    return os;
}
};
class SkupDomina{
protected:
Domina *d;
int tr;
int max;
public:
SkupDomina(int m){
    max=m;
    d=new Domina[m];
    tr=0;
}
SkupDomina(){
    d=new Domina[20];
    tr=0;
}
virtual bool operator+=( Domina &d)=0;
~SkupDomina(){
    delete [] d;
}
bool daLiSeNalazi(Domina const &domina){
    for(int i=0;i<tr; i++){
        if(d[i]==domina)
        return true;
    }
}
friend ostream& operator<<(ostream &os, const SkupDomina &s){
    for(int i=0;i<s.tr; i++){
        os<<s.d[i]<<" ";
    }
    os<<endl;
}
};
class Kutija:public SkupDomina{
    public:
    Kutija(int m):SkupDomina(m){};
    Kutija():SkupDomina() {};
    bool operator+=( Domina &dom){
        if(daLiSeNalazi(dom))
        return false;
        else {
            if(max>tr)
            d[tr]=dom;
            tr++;
            return true;
        }
    }
    Domina getDomina() const {
        return d[tr-1];
    }
};
class Tabla:public SkupDomina{
    public:
    Tabla(int m):SkupDomina(m){};
    Tabla():SkupDomina() {};
    bool operator+=( Domina &dom){
        if(tr==0){
            d[tr]=dom;
            tr++;
            return true;
        }
        else if(d[tr-1].getB()==dom.getA()){
            d[tr]=dom;
            tr++;
            return true;
        }
        else if(d[tr-1].getB()==dom.getB()){
            dom.zameni();
            d[tr]=dom;
            tr++;
            return true;

        }
        else if(d[0].getA()==dom.getA()){
            for(int i=tr-1; i>=0; i--){
                d[i+1]=d[i];
            }
            d[0]=dom;
            tr++;
        }
        else if(d[0].getA()==dom.getB()){
            dom.zameni();
            tr++;
           for(int i=tr-1; i>=0; i--){
                d[i+1]=d[i];}
            d[0]=dom;
            tr++;
        }
        else{
            cout<<"Ne mozete dodati dominu"<<endl;
            return false;
        } 
    }
};
int main(){
Domina d;
Domina dom(5,4);
Domina dom2(4,7);
Domina dom3(5,4);
Domina dom4(5,5);
// Domina dom4(4,3);
// Domina dom5(6,5);
Tabla tabla(6);
tabla+=dom;
tabla+=dom2;
tabla+=d;
tabla+=dom3;
tabla+=dom4;
// tabla+=dom5;
cout<<tabla<<endl;
return 0;
};