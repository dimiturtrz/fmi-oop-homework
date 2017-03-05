#include<iostream>
using namespace std;

template <typename T>
void input (T* array, int n) {
	for(int i=0; i<n; i++)
		cin>> array[i];
}

// void because it doesnt need to return anything - it deals with the memory where the array points to directly
// void and the pointer types would be problematic but the other primitives should be fine 

int main () {
	int iarr[3];
	input<int>(iarr, 3);
	char carr[5];
	input<char>(carr, 5);
	return 0;
}
