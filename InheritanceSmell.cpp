
#include <string>
using namespace std;

class Laptop {
protected:
	Laptop() {
	}
private:
	string modelName;
	string serialNum;
	string color;
	float weight;
	string hostOsType;
	int storageCapa;
};

// Compile time relationship or static relationship
class HpLaptop:public Laptop {
private:
};

class ZeLaptop {

};

class LeLaptop {

};