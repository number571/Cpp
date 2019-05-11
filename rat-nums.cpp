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

class rat {
    private:
        int numer, denom;
    public:
        rat(int x, int y) { numer = x; denom = y; }
        rat(int x) { numer = x; denom = 0; }
        rat() { numer = denom = 0; }

        friend string get(rat x);
        friend int numer(rat x) { return x.numer; }
        friend int denom(rat x) { return x.denom; }

        friend rat operator+(rat x, rat y) {
            int num = x.numer * y.denom + y.numer * x.denom;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return rat(num / gcd_value, den / gcd_value);
        }
        friend rat operator+=(rat &x, rat y) { return x = x + y; }

        friend rat operator-(rat x, rat y) {
            int num = x.numer * y.denom - y.numer * x.denom;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return rat(num / gcd_value, den / gcd_value);
        }
        friend rat operator-=(rat &x, rat y) { return x = x - y; }

        friend rat operator*(rat x, rat y) {
            int num = x.numer * y.numer;
            int den = x.denom * y.denom;
            int gcd_value = gcd(num, den);
            return rat(num / gcd_value, den / gcd_value);
        }
        friend rat operator*=(rat &x, rat y) { return x = x * y; }

        friend rat operator/(rat x, rat y) {
            int num = x.numer * y.denom;
            int den = x.denom * y.numer;
            int gcd_value = gcd(num, den);
            return rat(num / gcd_value, den / gcd_value);
        }
        friend rat operator/=(rat &x, rat y) { return x = x / y; }
};

string get(rat x) {
    return to_string(x.numer) + "/" + to_string(x.denom);
}

int main(void) {
    rat x{4, 5};
    rat y{2, 4};

    cout << get(x) + " + " + get(y) + " = " + get(x + y) << endl;
    return 0;
}
