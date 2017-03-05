#include<iostream>
using namespace std;

template <typename T>
bool ordered (T* array, int n) {
	for(int i=0; i<n-1; i++)
		if(array[i] > array[i+1])
			return false;
	return true;
}

// should work for all integrable(chars included) and floating-point types except maybe sometimes wrong for floating-point elements which have the same value because their equality comparison is imperfect

int main () {
	float arr1[] = {1,2,4,4,5.12,5.125,8,16};
	int arr2[] = {8,12,4,3,8,12};
	
	cout<< boolalpha<< ordered<float>(arr1, 8)<< endl;
	cout<< boolalpha<< ordered<int>(arr2, 6)<< endl;
	
	return 0;
}
