#include <iostream>
using namespace std;
class Izraz1{
    protected:
    char op1;
    int operand1, operand2;
        virtual double Izracunaj(char op1, int operand1, int operand2){
        double res;
        if(op1 == '+'){
            res = operand1 + operand2;
        }
        else if(op1 == '-'){
            res = operand1 - operand2;
        }
        else if(op1 == '*'){
            res = operand1 * operand2;
        }
        else if(op1 == '/'){
            res = operand1 / operand2;
        }
        return res;
    }
    public:
     virtual void ispis(){
        cout<<operand1<<op1<<operand2<<endl;
    }
    Izraz1(char op1, int operand1, int operand2){
        this->op1 = op1;
        this->operand1 = operand1;
        this->operand2 = operand2;
    }
    Izraz1(){
        op1 = '+';
        operand1 = 2; 
        operand2 = 5;
    }
    void setOperand1(int op1){
        operand1 = op1;
    }
    void setOperand2(int op2){
        operand2 = op2; 
    }
    void setOperacija(char op){
        op1 = op;
    }
    int getOperand1(){
        return operand1;
    }
    int getOperand2(){
        return operand2;
    }

};
 class Izraz2 : public Izraz1{
    private:
    char op2;
    int operand3;
    public:
Izraz2(int op2, char operand3) : Izraz1(operand1, operand2, op1){
 this->op2 = op2;
 this->operand3 = operand3;
}
    void setOperand2(int op3){
        operand3 = op3; 
    }
    void setOperacija(char op){
        op2 = op;
    }
    int getOperand3(){
        return operand3;
    }
    double Izracunaj(){
        if(op1 == '*'|| op1 == '/'){
            double r1 = Izracunaj(op1,operand1, operand2);

        }
    }

};
int main(){

}