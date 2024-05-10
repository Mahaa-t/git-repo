#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename K, typename V>
class Dictionary {
private:
    struct KeyValuePair {
        K key;
        V value;
    };

    vector<KeyValuePair> items;

public:
    KeyValuePair newPair;
    // Function to add or update a key-value pair
    void add(K key, V value) {
        newPair.key = key;
        newPair.value = value;
        items.push_back(newPair);
    }

    V& operator[](K key) {

        return pair<K,V>.value;
    }
};

int main() {
    Dictionary<string, string> stringMap;
    stringMap.add("BLR", "BENGALURU");
    stringMap.add("CHN", "CHENNAI");
    string value = stringMap["BLR"];
    cout << value << endl;

    Dictionary<string, int> stringMap1;
    stringMap1.add("One", 1);
    stringMap1.add("Two", 2);
    int num = stringMap1["One"];
    cout << num << endl;

    return 0;
}