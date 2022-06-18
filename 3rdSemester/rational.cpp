#include <iostream>
using namespace std;

class Rational
{
    public:
        Rational(){};
        Rational(int numer, int denom){

        this->numerator = numer;
        this->denominator = denom;

        };

    int getNumerator() const;
    int getDenominator() const;

    friend void display(ostream& out, const Rational& value);
    friend bool operator < (const Rational& left, const Rational& right);

    friend ostream& operator << (ostream& out, const Rational& obj){        
        float temp;
        temp = (obj.numerator) / (obj.denominator);
        out << obj.numerator << endl;
        out << obj.denominator << endl;
        out << temp;

        //return out;
    };
    friend Rational operator + (const Rational& left, int right){
            Rational temp;
            temp.numerator =  left.numerator + (right * left.denominator);
            temp.denominator = left.denominator;
            return temp;
        }
    friend bool operator < (int left, const Rational& right){
        if (left < (right.numerator / right.denominator) ) {
            return true;
        }; 
        return false;
    };
    private:
    float numerator;
    float denominator; 
};

int main(){
    Rational r1(5,6);
    int x;
    x = 4;
    cout << r1 + x << endl;
    if ( x < r1){}
    return 0;
    
}


