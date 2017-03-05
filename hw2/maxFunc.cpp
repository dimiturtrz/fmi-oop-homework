#include<iostream>
using namespace std;

typedef double (*dFunction)(double);

double triple(double x) {
	return 3*x;
}

double square(double x) {
	return x*x;
}

double fmax(dFunction f, dFunction g, double x) {
	return f(x) > g(x) ? f(x) : g(x);
}

int main () {
	double x = 4;
	cout<< fmax(triple, square, x)<< endl;

	return 0;
}
