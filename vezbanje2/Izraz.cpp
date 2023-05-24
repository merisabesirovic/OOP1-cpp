#include <iostream>
#include <cmath>
using namespace std;

class Izraz1 {
protected:
    char operacija1;
    int operand1;
    int operand2;

public:
    Izraz1() {
        operacija1 = '+';
        operand1 = 2;
        operand2 = 5;
    }

    Izraz1(char operacija1, int o1, int o2) {
        this->operacija1 = operacija1;
        operand1 = o1;
        operand2 = o2;
    }

    void setOperands(int o1, int o2) {
        operand1 = o1;
        operand2 = o2;
    }

    void setOperacija1(char operacija1) {
        this->operacija1 = operacija1;
    }

    char getOperacija1() { return this->operacija1; }

    int getOperand1() { return operand1; }

    int getOperand2() { return operand2; }

    virtual float Izracunaj() {
        float res;
        switch (operacija1) {
            case '+':
                res = operand1 + operand2;
                break;
            case '-':
                res = operand1 - operand2;
                break;
            case '*':
                res = operand1 * operand2;
                break;
            case '/':
                (operand2 != 0) ? res = operand1 / operand2 : res = 0;
                break;
            default:
                cout << "Nema deljenja sa nulom" << endl;
        }
        return res;
    }
};

class Izraz2 : public Izraz1 {
    char operacija3;
    int operand3;

public:
    Izraz2() : Izraz1() {
        operacija3 = '*';
        operand3 = 3;
    }

    Izraz2(char operacija1, int operand1, int operand2, int operand3, char operacija3)
        : Izraz1(operacija1, operand1, operand2) {
        this->operacija3 = operacija3;
        this->operand3 = operand3;
    }

    float Izracunaj() {
        float res;
        if (operacija1 == '*' || operacija1 == '/') {
            res = Izraz1::Izracunaj();
            if (operacija3 == '+')
                res += operand3;
            else if (operacija3 == '-')
                res -= operand3;
            else if (operacija3 == '*')
                res *= operand3;
            else if (operacija3 == '/' && operand3 != 0)
                res /= operand3;
        } else {
            if (operacija3 == '*') {
                res = operand2 * operand3;
            } else if (operacija3 == '/' && operand3 != 0) {
                res = operand2 / operand3;
            } else if (operacija3 == '+') {
                res = Izraz1::Izracunaj() + operand3;
            } else if (operacija3 == '-') {
                res = Izraz1::Izracunaj() - operand3;
            }
            if (operacija1 == '+') {
                res += operand1;
            } else if (operacija1 == '-') {
                res -= operand1;
            }
        }
        return res;
    }
};

int main() {
    Izraz1 i1;
    Izraz2 i2('+', 2, 4, 9, '*');
    cout << i2.Izracunaj() << endl;

    return 0;
}
