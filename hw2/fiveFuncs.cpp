#include<iostream>
using namespace std;

typedef double (*dFunction)(double);

double square(double x) {
	return x*x;
}

double cube(double x) {
	return x*x*x;
}

double half(double x) {
	return x/2;
}

double triple(double x) {
	return x*3;
}

double reciprocal(double x) {
	return 1/x;
}

int main () {
	double x = 0.5;

	dFunction functions[5];
	functions[0] = square;
	functions[1] = cube;
	functions[2] = half;
	functions[3] = triple;
	functions[4] = reciprocal;

	int maxIndex = 0;
	for(int i=0; i<5; i++)
		if(functions[maxIndex](x) < functions[i](x))
			maxIndex = i;
			
	cout<< maxIndex<< endl;

	return 0;
}
