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

        int numers() { return numer; }
        int denoms() { return denom; }
        friend ostream& operator<<(ostream &out, rat x) {
            cout << to_string(x.numer) + "/" + to_string(x.denom);
            return out;
        }

        friend bool operator==(rat x, rat y) {
            int gcd_value_x = gcd(x.numer, x.denom);
            int gcd_value_y = gcd(y.numer, y.denom);
            return  (x.numer / gcd_value_x) == (y.numer / gcd_value_y) &&
                    (x.denom / gcd_value_x) == (y.denom / gcd_value_y);
        }

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

int main(void) {
    rat x{4, 5};
    rat y{2, 4};

    cout << x << " + " << y << " = " << x + y << endl;

    x = {2, 5};
    y = {4, 10};
    cout << (x == y) << endl;
    return 0;
}
