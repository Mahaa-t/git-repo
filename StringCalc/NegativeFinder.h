#include <string>
using namespace std;


class NegativeFinder {
private:
	string negatives;

public:
	void operator()(int i);
	operator string();
};