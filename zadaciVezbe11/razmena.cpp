#include <iostream>
using namespace std;
template <class T>
void razmena(T &a, T &b){
    T pom;
    pom=b;
    b=a;
    a=pom;
}
int main()

{   char a,b;
    cout<<"Unesite vrednosti a i b"<<endl;
    cin>>a,b;
    // cout<<"Nakon zamene vrednosti"<<razmena(a,b);
}
