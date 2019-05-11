#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        ushort MAX = 10;
        ushort top = 0;
        char *array;
    public:
        Stack(ushort max) {
            array = new char[max];
            MAX = max;
        }
        Stack() {
            array = new char[MAX];
        }
        void push(char x) {
            if (top < MAX) {
                array[top++] = x;
            } else {
                cout << "Error: variable top = MAX stack" << endl;
            }
        }
        char pop() {
            if (top > 0) {
                return array[--top];
            } else {
                cout << "Error: variable top = 0 stack" << endl;
                return -1;
            }
        }
};

int main(void) {
    Stack x(3);

    x.push('A'); x.push('B'); x.push('C');
    cout << x.pop() << x.pop() << x.pop() << endl;

    return 0;
}
