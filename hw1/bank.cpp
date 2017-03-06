#include<iostream>
#include<fstream>
using namespace std;

void strcpy(char* dest, const char* source);
int strlen(const char* str);

struct Person {
protected:
	char* firstName;
	char* lastName;
public:
	char* getFirstName() const {
		return firstName;
	}

	char* getLastName() const {
		return firstName;
	}

	void setFirstName(const char* newFirstName) {
		delete [] firstName;
		firstName = new char[strlen(newFirstName)];
		strcpy(firstName, newFirstName);
	}

	void setLastName(const char* newLastName) {
		delete [] lastName;
		lastName = new char[strlen(newLastName)];
		strcpy(lastName, newLastName);
	}

	Person(): firstName(NULL), lastName(NULL){}
	Person(const char* newFirstName, const char* newLastName) {
		firstName = NULL;
		setFirstName(newFirstName);
		lastName = NULL;
		setLastName(newLastName);
	}

	Person(const Person& other) {
		setFirstName(other.firstName);
		setLastName(other.lastName);
	}

	Person& operator=(const Person& other) {
		setFirstName(other.firstName);
		setLastName(other.lastName);
	}

	~Person() {
		delete [] firstName;
		firstName = NULL;
		delete [] lastName;
		lastName = NULL;
	}
};

struct Client: Person {
private:
	float balance;

public:
	float getBalance() const {
		return balance;
	}

	void setBalance(float newBalance) {
		balance = newBalance;
	}

	Client() {}
	Client(const char* newFirstName, const char* newLastName, float newBalance) : Person(newFirstName, newLastName) {
		balance = newBalance;
	}

	void print(){
		writeToFile(cout);
	}

	void writeToFile(ostream& stream) {
		stream<< firstName<< ", "<< lastName<< ", "<< balance<< endl;
	}

	void readName(ifstream& stream, bool first) {
		char name[100];
		char ch;
		stream.get(ch);
		int i;
		for(i = 0; ch!=','; stream.get(ch))
			name[i++] = ch;
		name[i] = '\0';
		stream.get(ch);
		first? setFirstName(name) : setLastName(name);
	}

	void readFromFile(ifstream& stream) {
		readName(stream, true);
		readName(stream, false);
		stream>> balance;
		stream.ignore(5, '\n');
	}
};

void strcpy(char* dest, const char* source) {
	int i=0;
	do
		dest[i] = source[i];
	while(source[i++] != '\0');
	dest[i] = '\0';
}

int strlen(const char* str) {
	int len = 0;
	while(str[len++] != '\0');
	return len;
}

// to be sure of no errors in format
void generateFile() {
	Client clients[5];
	clients[0] = Client("Ivan", "Ivanov", 5.0);
	clients[1] = Client("Pesho", "Toshev", 15.0);
	clients[2] = Client("Asdf", "Petrov", 12.0);
	clients[3] = Client("Thomas", "Anderson", 0.0);
	clients[4] = Client("Test1", "Test2", 5.0);
	ofstream clientsFile;
	clientsFile.open("clients.txt", ios::out | ios::trunc);
	for(int i=0; i<5; i++)
		clients[i].writeToFile(clientsFile);
	clientsFile.close();
}

int main () {
	generateFile();
	//а
	Client clients[5];
	ifstream clientsFile;
	clientsFile.open("clients.txt", ios::in);
	for(int i=0; i<5; i++) 
		clients[i].readFromFile(clientsFile);
	clientsFile.close();
	//б
	for(int i=0; i<5; i++)
		clients[i].print();
	//в
	float sum = 0;
	for(int i=0; i<5; i++)
		sum += clients[i].getBalance();
	cout<< sum<< endl;

	return 0;
}
