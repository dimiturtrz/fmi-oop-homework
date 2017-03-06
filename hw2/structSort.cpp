#include<iostream>
using namespace std;

struct S {
	int a; 
	int b; 
	int c;

	S() {}
	S(int a, int b, int c): a(a), b(b), c(c){}

	void print() {
		cout<< a<< " "<< b<< " "<< c<< endl;
	}
};

typedef bool (*compareF)(S, S);

bool greaterA(S s1, S s2) {
	return s1.a > s2.a;
}

bool greaterB(S s1, S s2) {
	return s1.b > s2.b;
}

bool greaterLex(S s1, S s2) {
	if(s1.a == s2.a && s1.b == s2.b)
		return s1.c > s2.c;
	if(s1.a == s2.a)
		return s1.b > s2.b;
	return s1.a > s2.a;
}

void sort(S* array, int n, compareF compare) {
	for(int i=n-1; i>0; i--)
		for(int j=0; j<i; j++)
			if(compare(array[j], array[i])) {
				S temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}

void printSArr(S* arr, int n) {
	for(int i=0; i<n; i++)
		arr[i].print();
	cout<< endl;
}

int main () {
	S sarr[5];
	
	sarr[0] = S(1,1,1);
	sarr[1] = S(2,3,7);
	sarr[2] = S(1,2,3);
	sarr[3] = S(3,2,1);
	sarr[4] = S(2,3,1);


	sort(sarr, 5, greaterA);
	printSArr(sarr, 5);
	
	sort(sarr, 5, greaterB);
	printSArr(sarr, 5);
	
	sort(sarr, 5, greaterLex);
	printSArr(sarr, 5);

	return 0;
}
