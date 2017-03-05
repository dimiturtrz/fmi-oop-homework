#include<iostream>
using namespace std;

typedef double (*dFunction)(double);

// example funcs
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
// \example funcs

double fmax(dFunction f, dFunction g, double x) {
	return f(x) > g(x) ? f(x) : g(x);
}
// \with func from last problem

double maxarray (dFunction* array, int n, double x) {
	int maxIndex = 0;
	for(int i=1; i<n; i++)
		maxIndex = (array[i](x) > array[maxIndex](x) ? i : maxIndex);
		//maxIndex = array[maxIndex] > (fmax(array[maxIndex], array[i], x)) ? maxIndex, i;
	return array[maxIndex](x);
}

int main () {
	double x = 0.5;

	dFunction functions[5];
	functions[0] = square;
	functions[1] = cube;
	functions[2] = half;
	functions[3] = triple;
	functions[4] = reciprocal;

	cout<< maxarray(functions, 5, x)<< endl;
	
	return 0;	
}
