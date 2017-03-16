#include<iostream>
using namespace std;

class Rat{
private:
	int num;
	int denom;
public:
	Rat(int num = 0, int denom = 0): num(num), denom(denom) {}

	// TODO addition

	Rat operator*(Rat& other) {
		Rat result(num, denom);
		result.num *= other.num;
		result.denom *= other.denom;
		return result;
	}

	

};

int main () {

	return 0;
}
