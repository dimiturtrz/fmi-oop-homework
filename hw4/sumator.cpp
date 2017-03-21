#include<iostream>
using namespace std;

class NumbersSummator {
private:
	int initSum;
	int cSum;
	int changes;
public:
	NumbersSummator(int cSum = 0):
		cSum(cSum),
		initSum(cSum),
		changes(0) {}

	int sum() const {
		return cSum;
	}

	void add(const int number) {
		cSum += number;
		changes++;
	}

	void sub(const int number) {
		cSum -= number;
		changes++;
	}

	int num() const {
		return changes;
	}

	float average() const {
		return (cSum-initSum)/changes;
	}
};

int main () {
	NumbersSummator seq1(10);
	seq1.add(10);
	seq1.add(5);
	seq1.sub(15);
	cout<< seq1.sum()<< endl;
	cout<< seq1.average()<< endl;

	return 0;
}
