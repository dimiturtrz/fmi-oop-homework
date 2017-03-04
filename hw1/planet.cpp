#include<iostream>
#include<fstream>
using namespace std;

struct Planet {
	char name[25]; // never again dynamic
	float dts, diameter, mass;

	//а
	void input() {
		cin>> name;
		cin>> dts>> diameter>> mass;
	}

	//б
	void print() {
		cout<< name<< ", ";
		cout<< dts<< " "<< diameter<< " "<< mass<< endl;
	}

	//в
	float secondsToLight() {
		float sol = 299792;
		return dts/sol;
	}
};

//г
Planet* readFromFile(ifstream& stream, Planet* planets) {
	planets = new Planet[4];
	for(int i = 0; i< 4; i++){
		char ch;
		stream.get(ch);
		int j;
		for(j = 0; ch!=','; stream.get(ch))
			planets[i].name[j++] = ch;
		planets[i].name[j] = '\0';
		stream >> planets[i].dts>> planets[i].diameter>> planets[i].mass;
		stream.get(ch);
	}
	return planets;
}

void printPlanets(Planet* planets) {
	for(int i=0; i<4; i++)
		planets[i].print();
}

void printBiggest(Planet* planets) {
	int maxIndex = 0;
	for(int i=0; i<4; i++) 
		if(planets[i].diameter > planets[maxIndex].diameter)
			maxIndex = i;
	planets[maxIndex].print();
}

int main() {
	ifstream planetsFile;
	planetsFile.open("planets.txt", ios::in);
	Planet* planets = readFromFile(planetsFile, planets);
	planetsFile.close();
	//д
	printPlanets(planets);
	cout<< endl;
	//е
	printBiggest(planets);
	cout<< endl;
	delete [] planets;
	return 0;
}
