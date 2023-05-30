/*(15 поена) Боја садржи целобројне интензитете црвене, зелене и плаве компоненте, у опсегу од 0
до 255 (грешка је ако вредност компоненте није у том опсегу). Може да се утврди једнакост (==)
две боје и да се дохвате све три компоненте боје.
 Елемент слике се задаје помоћу боје (подразумевано бела боја – све компоненте имају
максималну вредност). Може да се дохвати и промени боја елемента слике, као и да се исти
упише у излазни ток (<<) у облику (црвена, зелена, плава).
 (15 поена) Слика правоугаоног облика садржи матрицу задатог броја врста и колона (подразумевано 3×4) елемената слике 
задате почетне боје (подразумевано беле). Могу да се дохвате димензије слике, да се приступи елементу са задатим индексима 
(sli(i,j); грешка је ако је индекс
изван опсега), да се промени боја елементу задате врсте и колоне и да се слика упише у излазни
ток (<<), свака врста у засебном реду. На црно-белој слици почетна боја мора бити црна или бела
и боја елемената се може променити само у црну или у белу боју. На слици у нијанси сиве
почетна боја мора бити у нијанси сиве и боја елемената се може променити само у боју чије све
три компоненте имају исте вредности.
 (15 поена) Листа садржи произвољан број података неког типа. Ствара се празна, након чега се
подаци додају појединачно. Не може да се копира ни на који начин. При уписивању у излазни ток
(<<) пишу се садржани подаци, сваки у засебном реду. Галерија је листа слика.
 (15 поена) Апстрактни филтер може да врши обраду задатог елемента слике. Такође, може да
се примени над задатом галеријом, када врши обраду сваког елемента сваке слике из галерије.
Обрада инвертујућег филтра састоји се у мењању све три компоненте боје елемента слике, по
формули: novaVrednost=255-staraVrednost.
(10 поена) Написати на језику C++ програм који створи неколико разнородних слика, промени им
боју на појединим елементима, затим створи галерију, у њу дода створене слике и испише је на
главном излазу. Потом над свим сликама у галерији примени инвертујући филтер и поново испише
галерију. Користити фиксне параметре – није потребно ништа учитати с главног улаза.*/
#include <iostream>
using namespace std;

class Boja {
    int zelena;
    int plava;
    int crvena;
public:
    Boja() {
        zelena = 255;
        plava = 255;
        crvena = 255;
    }
    
    Boja(int z, int p, int c) {
        if (z <= 255 && p <= 255 && c <= 255) {
            zelena = z;
            plava = p;
            crvena = c;
        } else {
            cout << "Invalid input" << endl;
        }
    }
    
    int getZelena() const { return zelena; }
    int getPlava() const { return plava; }
    int getCrvena() const { return crvena; }
    
    bool operator==(const Boja& b) {
        return (zelena == b.zelena && plava == b.plava && crvena == b.crvena);
    }
};

class ElementSlike {
protected:
    Boja boja;
    
public:
    ElementSlike(const Boja& boja) {
        this->boja = boja;
    }
    
    ElementSlike() {
        boja = Boja();
    }
    
    Boja getBoja() {
        return boja;
    }
    
    void setBoja(const Boja& boja) {
        this->boja = boja;
    }
    
    friend ostream& operator<<(ostream& stream, const ElementSlike& e) {
        stream << e.boja.getCrvena() << "," << e.boja.getZelena() << "," << e.boja.getPlava() << endl;
        return stream;
    }
};

class PravougaonaSlika {
protected:
    int n;
    int m;
    ElementSlike** boje;
    
public:
    PravougaonaSlika(int n = 3, int m = 4) {
        this->n = n;
        this->m = m;
        boje = new ElementSlike*[n];
        
        for (int i = 0; i < n; i++) {
            boje[i] = new ElementSlike[m];
        }
    }
    
    int getDimenzijeM() {
        return m;
    }
    
    int getDimenzijeN() {
        return n;
    }
    
    ElementSlike getBojaElementa(int i, int j) {
        if (i < n && j < m) {
            return boje[i][j];
        } else {
            cout << "Greska" << endl;
            return ElementSlike();
        }
    }
    
    virtual void promeniBoju(const Boja& b, int i, int j) {
        boje[i][j].setBoja(b);
    }
    
void ispis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Boja boja = boje[i][j].getBoja();
            cout << boja.getCrvena() << "," << boja.getZelena() << "," << boja.getPlava() << " ";
        }
        cout << endl;
    }
    cout << endl;
}
};

class CrnoBela : public PravougaonaSlika {
public:
    CrnoBela(int n, int m) : PravougaonaSlika(n, m) {}
    
    void promeniBoju(const Boja& b, int i, int j) {
        if (b.getCrvena() == 0  && b.getZelena() == 0 &&  b.getPlava() == 0) {
            PravougaonaSlika::promeniBoju(b, i, j);
        }
        else if(b.getCrvena() == 255  && b.getZelena() == 255 &&  b.getPlava() == 255) {
            PravougaonaSlika::promeniBoju(b, i, j);
    }
}};

class SivaSlika : public PravougaonaSlika {
public:
    SivaSlika(int n, int m) : PravougaonaSlika(n, m) {}
    
    void promeniBoju(const Boja& b, int i, int j) {
        if (b.getZelena() == b.getCrvena() && b.getCrvena() == b.getPlava()) {
            PravougaonaSlika::promeniBoju(b, i, j);
        }
    }
};
template <typename T>
class Lista{
T *galerija;
int tr;
int max;
public:
Lista(){
galerija = new T[10];
tr=0;
max=10;
}
Lista(int m){
    max = m;
    galerija = new T[max];
    tr=0;
}
void operator+=(T const & a){
    if(max>tr){
        galerija[tr]=a;
        tr++;
    }else cout<<"Greska";
}
void ispisGalerije(){
    for(int i=0; i<tr; i++){
        galerija[i].ispis();
    }
    cout<<endl;
}
};


int main() {
    Lista<PravougaonaSlika> galerija(2);  

 
    CrnoBela slika1(3, 4);
    Boja crna(0, 0, 0);
    Boja bela(255, 255, 255);
    Boja siva(128, 128, 128);
    slika1.promeniBoju(crna, 1, 2);
    slika1.promeniBoju(bela, 2, 3);

    SivaSlika slika2(2, 2);
    slika2.promeniBoju(siva, 0, 0);
    slika2.promeniBoju(bela, 1, 1);

    galerija += slika1;
    galerija += slika2;

    galerija.ispisGalerije();

    return 0;
}

