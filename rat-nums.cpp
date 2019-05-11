#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

class Rat {
    private:
        int numer, denom;
    public:
        Rat(int x, int y) { numer = x; denom = y; }
        Rat(int x) { numer = x; denom = 0; }
        Rat() { numer = denom = 0; }

        int Numer() { return numer; }
        int Denom() { return denom; }
        string String() {
            return to_string(numer) + "/" + to_string(denom);
        }

        friend ostream& operator<<(ostream &out, Rat x) {
            cout << x.numer << "/" << x.denom;
            return out;
        }

        friend Rat operator+(Rat x, Rat y) {
            int num = x.numer * y.denom + y.numer * x.denom;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return Rat(num / gcd_value, den / gcd_value);
        }
        friend Rat operator+=(Rat &x, Rat y) { return x = x + y; }

        friend Rat operator-(Rat x, Rat y) {
            int num = x.numer * y.denom - y.numer * x.denom;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return Rat(num / gcd_value, den / gcd_value);
        }
        friend Rat operator-=(Rat &x, Rat y) { return x = x - y; }

        friend Rat operator*(Rat x, Rat y) {
            int num = x.numer * y.numer;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return Rat(num / gcd_value, den / gcd_value);
        }
        friend Rat operator*=(Rat &x, Rat y) { return x = x * y; }

        friend Rat operator/(Rat x, Rat y) {
            int num = x.numer * y.denom;
            int den = x.denom * y.numer;
            int gcd_value = gcd(num, den);
            return Rat(num / gcd_value, den / gcd_value);
        }
        friend Rat operator/=(Rat &x, Rat y) { return x = x / y; }
};

int main(void) {
    Rat x{4, 5}, y{2, 4};
    cout << x << " + " << y << " = " << x + y << endl;
    return 0;
}
