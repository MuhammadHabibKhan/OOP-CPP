#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class Vector {
    // class by default private, attributes private
        float i;
        float j;
        float k;
        float magnitude;
        float alpha;
        float beta;
        float gamma;

    public:
        void setalpha(float a){
            cout << "Setter invoked" << endl;
            alpha = a;
        }
        float getalpha(){
            cout << "Getter invoked" << endl;
            return alpha;
        }

        // overloading << 
        friend ostream& operator << (ostream& out, Vector& vec){
        out << "(" << vec.i << "i) + " << "(" << vec.j << "j) + " << "(" << vec.k << "k)" << endl;
        }
        // null constructor
        Vector(){
            cout << "Null Constructor Invoked" << endl;
        }
        // parametrized constructor
        Vector(float x, float y, float z){
            i = x;
            j = y;
            k = z;
            cout << "Parametrized Constructor Invoked" << endl;
        }
        // copy constructor
        Vector(const Vector& vec){
            i = vec.i;
            j = vec.j;
            k = vec.k;
            cout << "Copy Constructor invoked" << endl;
        }
        void Show(){
           cout << *this << endl; 
        }
        // overloading +
        Vector operator + (const Vector& vec){
            this->i = this->i + vec.i;
            this->j = this->j + vec.j;
            this->k = this->k + vec.k;
            // temp.i = i + vec.i;
            // temp.j = j + vec.j;
            // temp.k = k + vec.k;
            return *this;
        }
        // Vector Addition Method
        Vector vecAddition(Vector& vec2){
            Vector addresult;
            addresult = *this + vec2;
            return addresult;
        }
        // - operator overloading
        Vector operator - (const Vector& vec){
            this->i = this->i - vec.i;
            this->j = this->j - vec.j;
            this->k = this->k - vec.k;

            return *this;
        }
        // Vector Substraction
        Vector vecSubstraction(Vector& vec2){
            Vector subresult;
            subresult = *this - vec2;
            return subresult;
        }
        // * operator overloading
        Vector operator * (const Vector& vec){
            this->i = this->i * vec.i;
            this->j = this->j * vec.j;
            this->k = this->k * vec.k;

            return *this;
        }
        // Vector Multiplication
        Vector vecMultiplication(Vector& vec2){
            Vector mulresult;
            mulresult = *this * vec2;
            return mulresult;
        }
        // Vector Magnitude
        float vecMagnitude(){
            this->magnitude = fabs(sqrt(pow(this->i,2) + pow(this->j,2) + pow(this->k,2)));
            return this->magnitude;
        }
        // show method overloading for magnitude
        void Show(Vector &vec){
           cout << vec.magnitude << endl ;
        }
        Vector vecDirection(){
            this->alpha = acos(this->i /this->magnitude) * 180 / 3.141592; // angle(direction) in degrees
            //cout << this->alpha << endl;
            this->beta = acos(this->j /this->magnitude)  * 180 / 3.141592;
            this->gamma = acos(this->k /this->magnitude) * 180 / 3.141592;
            
            return *this;
        }
        void ShowDirection(){
            // had to create a seperate show method as overloading would result in a messy arguments passed 
            // as all of the i j and k are present as attributes, we can also directly print through getter & setter
            // tried conditioning with typeid but not exactly working that fine. 
            cout << this->alpha << endl;
            cout << this->beta << endl;
            cout << this->gamma << endl;
        }

    };


int main() {
    Vector addvec, subvec, mulvec;
    float magvec;
    Vector dirvec[3];

    Vector vec1(+2,-6,+8);
    vec1.Show();

    Vector vec2(+7,-1,+9);
    vec2.Show();

    addvec = vec1.vecAddition(vec2);
    addvec.Show();

    subvec = vec1.vecSubstraction(vec2);
    subvec.Show();

    mulvec = vec1.vecMultiplication(vec2);
    mulvec.Show();

    magvec = vec2.vecMagnitude();
    vec2.Show(vec2);
    
    vec2.vecDirection();
    vec2.ShowDirection();

    cout << vec2.getalpha() << endl;

    Vector vec3 = vec1;
    vec3.Show();
    

    return 0;
}
