#include "NegativeFinder.h"

using namespace std;

void NegativeFinder :: operator()(int i) {
	if (i < 0)
		negatives.append(to_string(i) + ",");
}

NegativeFinder :: operator string() {
	if (negatives.length() > 0)
		negatives.pop_back();

	return negatives;
}
