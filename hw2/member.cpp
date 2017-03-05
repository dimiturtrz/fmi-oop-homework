#include<iostream>
using namespace std;

template <typename T>
bool member (T* array, int n, T x) {
	for(int i=0; i<n; i++)
		if(array[i] == x)
			return true;
	return false;
}

// wouldnt work for other arrays(as pointers most likely) because theyre "passed by reference" and wont be compared element by element. The other primitive types should work (except floating-point variables sometimes because equation comparision is imperfect)

int main () {
	bool arr1[] = {true, true, true, false, true};
	cout<< boolalpha<< member<bool>(arr1, 5, false)<< endl;
	float arr2[] = {1.25, 1.26, 8.37, 12, 78.1};
	cout<< boolalpha<< member<float>(arr2, 5, 1.267)<< endl;

	return 0;
}
