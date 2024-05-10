#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    string name;
    friend ostream& operator<<(ostream& out, const Device& operand2) {
        out << operand2.name;
        return out;
    }
};

template <typename T>
class Vector {
    T items[2];
public:
    Vector() {

    }
    T getItem(int index) const {
        return this->items[index];
    }
    void push_back(T item) {
        static int index = 0;
        //IntVector* itemsPtr = new IntVector;
        items[index] = item;
        //cout << index << endl;
        //cout << items[index] << endl;
        index++;
    }

    friend ostream& operator<<(ostream& out, const Vector& operand2) {
        out << "Vector elements are :" << endl;
        for (int i = 0; i < sizeof(operand2) / sizeof(operand2.items[0]); i++)
        {
            cout << "Entering for loop" << endl;
            out << operand2.getItem(i) << endl;
        }
        return out;
    }

    T& operator[](T operand2) {
        return items[operand2];
    }
};

int main() {
    Vector<int> vi;
    vi.push_back(10);
    vi.push_back(20);

    Vector<string> vs;
    vs.push_back("A");
    vs.push_back("B");

    Vector<Device> vd;
    Device obj1;
    obj1.name = "D1";
    Device obj2;
    obj2.name = "D2";
    vd.push_back(obj1);
    vd.push_back(obj2);

    cout << vi;
    cout << vs;
    cout << vd;
}