#include<iostream>
using namespace std;

void strcpy(char* destination, const char* source) {
	int i;
	for(i = 0; source[i]!='\0'; i++)
		destination[i] = source[i];
	destination[i] = '\0';
}

class BankAccount {
private:
	char clientName[50];
	char accountNumber[20];
	float balance;

	void setName(const char* name) {
		strcpy(clientName, name);
	}

	void setNumber(const char* number) {
		strcpy(accountNumber, number);
	}
public:
	BankAccount(const char* clientName, const char* accountNumber, float balance): balance(balance) {
		setName(clientName);
		setNumber(accountNumber);
	}

	void print() {
		cout<< "name: "<< clientName<< ", number: "<< accountNumber<< ", balance: "<< balance<< endl;
	}

	void deposit(float amount) {
		balance += amount;
	}

	bool withdraw(float amount) {
		if(amount > balance)
			return false;
		balance -= amount;
		return true;
	}

	bool operator==(BankAccount& other) {
		return balance == other.balance;
	}

	bool operator!=(BankAccount& other) {
		return !(*this == other);
	}

	bool operator<(BankAccount& other) {
		return balance < other.balance;
	}

	bool operator>(BankAccount& other) {
		return balance > other.balance;
	}
};

int main () {
	BankAccount b1("pesho", "1234", 5.0);
	BankAccount b2("gosho", "4321", 15.0);

	b1.print();
	b2.print();

	b1.deposit(5.0);
	b2.withdraw(5.0);

	//b1.print();
	//b2.print();

	return 0;
}
