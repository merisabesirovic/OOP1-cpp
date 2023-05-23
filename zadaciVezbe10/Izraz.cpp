#include <iostream>
using namespace std;

class Izraz1 {
protected:
    char op1;
    int operand1, operand2;

    virtual double Izracunaj(char op, int operand1, int operand2) {
        double res;
        if (op == '+') {
            res = operand1 + operand2;
        }
        else if (op == '-') {
            res = operand1 - operand2;
        }
        else if (op == '*') {
            res = operand1 * operand2;
        }
        else if (op == '/') {
            if (operand2 != 0) {
                res = static_cast<double>(operand1) / operand2;
            }
            else {
                cout << "Error: Division by zero!" << endl;
                res = 0.0;
            }
        }
        return res;
    }

public:
    virtual void ispis() {
        cout << operand1 << op1 << operand2 << endl;
    }

    Izraz1(char op, int operand1, int operand2) {
        this->op1 = op;
        this->operand1 = operand1;
        this->operand2 = operand2;
    }

    Izraz1() {
        op1 = '+';
        operand1 = 2;
        operand2 = 5;
    }

    void setOperand1(int op) {
        operand1 = op;
    }

    void setOperand2(int op) {
        operand2 = op;
    }

    void setOperacija(char op) {
        op1 = op;
    }

    int getOperand1() {
        return operand1;
    }

    int getOperand2() {
        return operand2;
    }
};

class Izraz2 : public Izraz1 {
private:
    char op2;
    int operand3;

public:
    Izraz2(int operand1, int operand2, char op1, int operand3, char op2) : Izraz1(op1, operand1, operand2) {
        this->op2 = op2;
        this->operand3 = operand3;
    }

    void setOperand3(int op3) {
        operand3 = op3;
    }

    void setOperacija(char op) {
        op2 = op;
    }

    int getOperand3() {
        return operand3;
    }

    double Izracunaj() {
        if (op1 == '*' || op1 == '/') {
            double r1 = Izraz1::Izracunaj(op1, operand1, operand2);
            double res;

            if (op2 == '+') {
                res = r1 + operand3;
            }
            else if (op2 == '-') {
                res = r1 - operand3;
            }
            else if (op2 == '*') {
                res = r1 * operand3;
            }
            else if (op2 == '/') {
                if (operand3 != 0) {
                    res = r1 / operand3;
                }
                else {
                    cout << "Error: Division by zero!" << endl;
                    res = 0.0;
                }
            }
            return res;
        }
        else {
            cout << "Error: Invalid operator for the first expression!" << endl;
            return 0.0;
        }
    }

    void ispis() {
        cout << operand1 << op1 << operand2 << op2 << operand3 << endl;
    }
};

int main() {
    Izraz1 iz1('+', 3, 4);
    iz1.ispis();  

    Izraz2 iz2(2, 5, '+', 6, '-');
    iz2.ispis(); 

    double result = iz2.Izracunaj();
    cout << "Result: " << result << endl;  

    return 0;
}
