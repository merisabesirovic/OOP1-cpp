// (укупно 70 поена) Написати на језику C++ следеће класе (класе опремити оним конструкторима,
// деструктором и операторима доделе који су потребни за безбедно и ефикасно коришћење класа):
// • (15 поена) Воћка има назив, реалан годишњи приход и целобројан животни век изражен у
// годинама који се задају при стварању и тренутну старост воћке која је при стварању нула. Могу
// да се дохвате годишњи приход и преостале године живота. Воћка може да остари годину дана
// (vocka++). Воћку је могуће уписати у излазни ток (it<<vocka) у облику
// назив(тренутна_старост/животни_век):годишњи_приход.
// • (30 поена) Воћњак садржи аутоматски генерисан јединствен целобројан идентификатор који
// може да се дохвати и матрицу показивача на воћке. Ствара се празан, задатих димензија
// матрице, после чега се воћке додају једна по једна (vocnjak+=vocka) на прву слободну
// локацију претражујући матрицу по редовима. Покушај додавања у попуњену матрицу се
// игнорише. Могућ је једногодишњи прогрес воћњака (vocnjak++) током којег све воћке у
// воћњаку остаре годину дана, а затим се из воћњака избаце све воћке које су достигле крај
// животног века. Могуће је одредити укупан годишњи приход воћњака као збир годишњих
// прихода свих воћки у воћњаку. Два воћњака је могуће упоредити на основу годишњег прихода
// (vocnjak1<vocnjak2). Воћњак се у излазни ток исписује (it<<vocnjak) у облику
// V_идент:годишњи_приход након чега се појединачне воћке исписују у матричном формату
// тако што се у засебним редовима исписују све воћке из одговарајућег реда матрице. За празна
// поља матрице треба исписати prazno_mesto. Воћке у појединачним редовима треба да буду
// одвојене једним знаком за табулацију.
// • (15 поена) Плантажа се састоји из произвољног броја воћњака и не може да се копира ни на
// који начин. Ствара се празна, након чега се воћњаци додају један по један
// (plantaza+=vocnjak). Могуће је извршити предикцију k-годишњег прихода свих воћњака
// на плантажи (plantaza(k)) при чему се на стандардном излазу, у засебним редовима за
// сваку годину, исписује идентификатор и годишњи приход воћњака са највећим годишњим
// приходом за ту годину.
// (10 поена) Написати на језику C++ програм који формира воћњак и у њега дода неколико воћки.
// Затим ствара нов воћњак као копију претходног и у оба воћњака дода још неколико различитих
// воћки. Након тога испише оба воћњака на стандардни излаз. Коначно ствара једну плантажу у
// коју се додају претходна два воћњака и симулира предикцију прихода од неколико година. Није
// потребно ништа учитавати с главног улаза.
#include <iostream>
using namespace std;
using std::string;
class Vocka{
    string naziv;
    float godisnjiP;
    int zivotniVek;
    int trGod;
    public:
    Vocka(){
        naziv = "";
        zivotniVek = 0;
        trGod = 0;
    }
    Vocka(string naziv, float prihod, int max){
        this->naziv = naziv;
        godisnjiP = prihod;
        zivotniVek = max;
        trGod = 0;
    }
    float godPrihod(){
        return godisnjiP;
    }
    int getZivot(){
        return zivotniVek-trGod;
    }
    void operator ++(int){
        trGod++;
    }
    string getIme(){
        return naziv;
    }
    friend ostream& operator<<(ostream& it, const Vocka& v){
        it<<v.naziv<<" "<<"Max zivotni vek"<<v.zivotniVek<<"|"<<v.trGod<<"|"<<v.godisnjiP<<endl;
        return it;
    }
 
};
class Vocnjak{
    Vocka ***vocnjak;
    int m;
    int n;
    public:
    int static Id;
    Vocnjak(){
        vocnjak = new Vocka**[1];
    }
    Vocnjak(int m, int n){
        this->m = m;
        this->n = n;
        vocnjak = new Vocka**[n];
      for (int i = 0; i < n; i++) {
            vocnjak[i] = new Vocka*[m];
            for (int j = 0; j < m; j++) {
                vocnjak[i][j] = nullptr;
            }
        }
        Id++;
    }
    Vocnjak& operator+=(Vocka &v){
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                if(vocnjak[i][j]==nullptr){
                    vocnjak[i][j]=new Vocka(v);
                    break;
            } 

            }
        return *this;
    }
    return *this;
};
    void operator++(int){
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(vocnjak[i][j]){
                (vocnjak[i][j])++;
                if(vocnjak[i][j]->getZivot()<=0)
                delete vocnjak[i][j];
                vocnjak[i][j] = nullptr;
    }}}}
    float ukPrihod()const {
        float s=0.0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(vocnjak[i][j])
                s+=vocnjak[i][j]->godPrihod();
    }
    return s;
};}
bool operator>(Vocnjak &v){
    return v.ukPrihod()>ukPrihod();
};
friend ostream& operator<<(ostream& it, Vocnjak &v){
    for(int i = 0; i < v.n; i++){
        for(int j = 0; j< v.m; j++){
            if(v.vocnjak[i][j]==nullptr)
            it<<"Nema";
            else
    it<<v.vocnjak[i][j]->getIme();
    }
    it<<endl;
}
};};
class Plantaza{
    Vocnjak *vocnjak;
    public:
    static int tr;
    Plantaza(){
        vocnjak = new Vocnjak[1];
        tr++;
    }
    void operator+=(Vocnjak &v){
        if(tr==1)
        vocnjak[0]=v;
        else{
            Vocnjak *tmp = new Vocnjak[tr];
            for(int i = 0; i <tr; i++){
                tmp[i] = vocnjak[i];
            }
        delete [] vocnjak;
        tr++;
        vocnjak = new Vocnjak[tr];
        for(int i = 0; i < tr-1; i++){
            vocnjak[i]=tmp[i];
        }
        delete []tmp;
        vocnjak[tr-1]=v;
        }
    }
    void najveciPrihod(int k){
        cout<<"Trenutan ukupan prihod:";
        float max = vocnjak[0].ukPrihod();
        Vocnjak max1;
        for(int i =0; i<tr; i++){
            if(max<vocnjak[i].ukPrihod()){
            max = vocnjak[i].ukPrihod();
            max1 = vocnjak[i];
        }}
        cout<<max<<" id je"<<max1.Id<<endl;
        for(int i=0; i<k; i++){
            vocnjak[i]++;
            max = vocnjak[0].ukPrihod();
            for(int j =0; j<tr; j++){
            if(max<vocnjak[i].ukPrihod()){
            max = vocnjak[i].ukPrihod();
            max1 = vocnjak[i];
        }
        }
        cout<<max<<max1.Id<<endl;

    }
    }
};
int Vocnjak::Id = 0;
int Plantaza :: tr = 0;
int main(){
    Vocka jagoda("jagoda", 2000, 2);
    Vocka jabuka("jabuka", 4000, 8);
    jagoda++;
    cout<<jagoda;
    Vocnjak vocee(3,2);
    vocee+=jagoda;
    vocee+=jabuka;
    cout<<vocee<<endl;
    cout<<vocee.ukPrihod()<<endl;

}