#include<iostream>
#include<fstream>

using namespace std;

void strcpy(char* dest, const char* source);

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

	void print() {
		writeToFile(cout);
	}

	void writeToFile(ostream& stream) {
		stream<< "description: "<< description<< ", ";
		stream<< "parts: "<< partNum<< ", ";
		stream<< "cost: "<< cost;
		stream<< endl;
	}
};

void strcpy(char* dest, const char* source) {
	int i=0;
	do
		dest[i] = source[i];
	while(source[i++] != '\0');
	dest[i] = '\0';
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

	//d
	for(int i=0; i<5; i++)
		products[i] = Product("", 0, 0);	

	//г
	products[0] = screwdriver;
	products[1] = hammer;
	products[2] = Product("socket", 777, 6.80);
	products[3] = Product("plier", 123, 10.80);
	products[4] = Product("hand-saw", 555, 12.80);

	//д
	cout<< endl;
	for(int i=0; i<5; i++)
		products[i].print();

	//е
	ofstream prodFile;
	prodFile.open("products.txt", ios::out | ios::trunc);
	for(int i=0; i<5; i++)
		products[i].writeToFile(prodFile);
	prodFile.close();

	return 0;
}
