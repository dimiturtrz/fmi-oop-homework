#include<iostream>
using namespace std;

/*template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}*/

class Rat{
private:
	int num;
	int denom;

	int gcd(int a, int b) {
		if(b > a)
			swap(a, b);
		while (b != 0) {
			a %= b;
			swap(a, b);
		}

		return a;
	}
public:

	Rat(int num = 0, int denom = 0): num(num), denom(denom) {}

	int getNum() {
		return num;
	}

	int getDenom() {
		return denom;
	}

	Rat operator+(Rat& other) {
		const int newDenom = (denom*other.denom)/gcd(denom, other.denom);
		const int num1 = num*(newDenom/denom);
		const int num2 = other.num*(newDenom/other.denom);

		return Rat(num1 + num2, newDenom);
	}

	Rat operator*(Rat& other) {
		Rat result(num, denom);
		result.num *= other.num;
		result.denom *= other.denom;
		return result;
	}
};

ostream& operator<<(ostream& stream, Rat rat) {
	stream<< "("<< rat.getNum()<< "/"<< rat.getDenom()<< ")";
}

int main () {
	Rat rat1(1,12), rat2(3,8);
	cout<< (rat1+rat2)<< endl;
	return 0;
}
