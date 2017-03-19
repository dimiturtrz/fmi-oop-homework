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

	int gcd(int a, int b) const {
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
	Rat(const Rat& other): num(other.num), denom(other.denom) {}

	int getNum() const {
		return num;
	}

	int getDenom() const {
		return denom;
	}

	Rat operator+(const Rat& other) const {
		const int newDenom = (denom*other.denom)/gcd(denom, other.denom);
		const int num1 = num*(newDenom/denom);
		const int num2 = other.num*(newDenom/other.denom);

		Rat result(num1 + num2, newDenom);
		return result;
	}

	Rat& operator+=(const Rat& other) {
		*this = (*this)+other;
		return *this;
	}

	Rat operator*(const Rat& other) const {
		Rat result(num, denom);
		result.num *= other.num;
		result.denom *= other.denom;
		return result;
	}

	Rat& operator*=(const Rat& other) {
		*this = (*this)*other;
		return *this;
	}

	Rat operator*(int scalar) const {
		return Rat(num*scalar, denom);
	}


	Rat& operator*=(int scalar) {
		num *= scalar;
		return *this;
	}
};

ostream& operator<<(ostream& stream, Rat rat) {
	stream<< "("<< rat.getNum()<< "/"<< rat.getDenom()<< ")";
}


Rat power(Rat a, int power) {
	Rat result(1,1);
	for(int i = 0; i < power; i++)
		result *= a;

	return result;
}

Rat poly (Rat coef[], int n, Rat x) {
	Rat result(coef[n]);
	for(int i=0; i<n; i++) 
		result += (coef[i]*power(x, i));

	return result;
}
int main () {
	Rat rat1(1,12), rat2(3,8);
	cout<< (rat1+rat2)<< endl;

	Rat coef[] = {Rat(1, 2), Rat(1, 1), Rat(12, 2), Rat(1,1)};
	cout<< poly(coef, 3, Rat(2, 1))<< endl;	

	return 0;
}
