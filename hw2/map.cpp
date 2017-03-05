#include<iostream>
using namespace std;

typedef double (*dFunction)(double);

double inc (double x) {return x+1;}

void map (double array[], int n, dFunction f) {
	for(int i=0; i<n; i++)
		array[i] = f(array[i]);
}

int main () {
	double a[] = {1,2,3};

	map(a,3,inc);
	
	for(int i=0; i<3; i++)
		cout<< a[i]<<" ";
	cout<< endl;

	return 0;
}
