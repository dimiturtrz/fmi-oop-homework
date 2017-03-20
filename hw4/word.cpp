#include<iostream>
using namespace std;

void strcpy(char* destination, const char* source) {
	int i=0;
	for(; source[i] != '\0'; ++i) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

int strlen(const char* str) {
	int i=0;
	for(; str[i]!='\0';++i);
	return i;
}

int strcmp(const char* str1, const char* str2) {
	for(int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
		if(str1[i] != str2[i])
			return (str1[i] > str2[i] ? 1 : -1);
	return 0;
}

class Word {
private:
	char buff[20];
	int size;
public:
	Word(const char* _buff) { 
		strcpy(buff, _buff);
		size = strlen(buff);
	}
	Word(const Word& other) {
		strcpy(buff, other.buff);
		size = other.size;
	}

	const char* const getBuff() const {
		return buff;
	}

	char operator[](int i) const {
		return buff[i];
	}

	Word operator+(const char ch) {
		Word newWord(buff);
		if(size <= 20){
			newWord.buff[size] = ch;
			newWord.buff[++size] = '\0';		
		}
		
		return newWord;
	}

	Word& operator+=(const char ch) {
		if(size <= 20){
			buff[size] = ch;
			buff[++size] = '\0';		
		}
		
		return *this;
	}

	bool operator==(Word& other) {
		return strcmp(buff, other.buff) == 0;
	}

	bool operator!=(Word& other) {
		return strcmp(buff, other.buff) != 0;
	}

	bool operator>(Word& other) {
		return strcmp(buff, other.buff) == 1;
	}

	bool operator<(Word& other) {
		return strcmp(buff, other.buff) == -1;
	}
};

ostream& operator<<(ostream& stream, const Word& word) {
	stream<< word.getBuff();
}

int main () {
	Word w1("pesho"), w2("pesh");
	cout<< boolalpha<< (w1 == w2)<< endl;
	cout<< boolalpha<< (w1 > w2)<< endl<< endl; // because 'o' > '\0'

	w2 += 'o';
	//cout<< w1<< " "<< w2<< endl;

	cout<< boolalpha<< (w1 == w2)<< endl;
	cout<< boolalpha<< (w1 > w2)<< endl;

	return 0;
}
