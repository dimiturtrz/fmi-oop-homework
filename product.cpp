#include<iostream>
#include<fstream>

using namespace std;

void strcpy(char* dest, const char* source);
int strlen(const char* str);
bool strcmp(const char* str1, const char* str2);

struct Product {
	char description[32];
	//описание на изделие
	int partNum;
	//номер на изделие
	double cost;
	//цена на изделие

	Product(){}

	Product(const char* desc, int pn, double c) {
		strcpy(description, desc);
		partNum = pn;
		cost = c;
	}

	Product(const Product &prod) {
		strcpy(description, prod.description);
		partNum = prod.partNum;
		cost = prod.cost;
	}

	bool operator==(const Product other) const {
		return (strcmp(description, other.description) &&
				partNum == other.partNum &&
				cost == other.cost);
	}

	bool operator!=(const Product other) const {
		return !(*this == other);
	}

	void print() const {
		writeToFile(cout);
	}

	void writeToFile(ostream& stream) const {
		stream<< description<< "| ";
		stream<< partNum<< " ";
		stream<< cost;
		stream<< endl;
	}

	void readFromFile(fstream& stream) {
		char ch;
		stream.get(ch);
		int i;
		for(i = 0; ch!='|'; stream.get(ch))
			description[i++] = ch;
		description[i] = '\0';
		stream >> partNum>> cost;
		stream.get(ch);
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

bool strcmp(const char* str1, const char* str2) {
	if(strlen(str1) != strlen(str2))
		return false;
	for(int i = 0; str1[i] != '\0'; ++i)
		if(str1[i] != str2[i])
			return false;
	return true;
}

int main () {
	//а
	Product screwdriver = Product("screw driver", 456, 5.50);
	Product hammer = Product("hammer", 324, 8.20); 

	//б
	screwdriver.print();
	hammer.print();

	//в
	Product products[5];

	//г
	for(int i=0; i<5; i++)
		products[i] = Product("", 0, 0);	

	cout<< endl;

	//д
	products[0] = screwdriver;
	products[1] = hammer;
	products[2] = Product("socket", 777, 6.80);
	products[3] = Product("plier", 123, 10.80);
	products[4] = Product("hand-saw", 555, 12.80);

	//е
	for(int i=0; i<5; i++)
		products[i].print();

	cout<< endl;

	//ж
	fstream prodFile;
	prodFile.open("products.txt", ios::out | ios::trunc);
	for(int i=0; i<5; i++)
		products[i].writeToFile(prodFile);
	prodFile.close();

	//з
	Product products2[5];

	prodFile.open("products.txt", ios::in);
	for(int i=0; i<5; ++i){
		products2[i].readFromFile(prodFile);
	}
	prodFile.close();

	//и
	for(int i=0; i<5; i++){
		products2[i].print();
		if(products[i] != products[i])
			cout<< "objects not equal!!!\n";
	}

	cout<< endl;

	return 0;
}
