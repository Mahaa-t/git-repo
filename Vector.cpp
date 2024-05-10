#include <iostream>
#include <string>
using namespace std;

class IntVector {
    int items[3];
public:
    IntVector() {

    }
    int getItem(int index) const {
        return this->items[index];
    }
    void push_back(int item) {
        static int index = 0;
        //IntVector* itemsPtr = new IntVector;
        items[index++] = item;
    }

    friend ostream& operator<<(ostream& out, const IntVector& operand2) {
        out << "Vector elements are :" << endl;
        for (int i = 0; i <= sizeof(operand2) / sizeof(operand2.items[0]); i++)
        {
            out << operand2.getItem(i) << endl;
        }
        return out;
    }

    int& operator[](int operand2) {
        return items[operand2];
    }
};

int main() {
    IntVector v;
    //cout << sizeof(v.items) << endl;
    v.push_back(10);
    //cout << v.getItem(0) << endl;
    v.push_back(20);
    //cout << v.getItem(1) << endl;
    v.push_back(30);
    //cout << v.getItem(2) << endl;
    v.push_back(40);
    //cout << v.getItem(3) << endl;

    int item = v[3];

    cout << item << endl;
    cout << v << endl;

    return 0;
}
