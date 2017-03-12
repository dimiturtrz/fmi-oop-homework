#include<iostream>
using namespace std;

int strlen (const char* str) {
	int i;
	for(i = 0; str[i]!= '\0'; i++);
	return i;
}

bool strcpy(char* destination, const char* source) {
	if(strlen(destination) != strlen(source))
		return false;
	for(int i=0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	return true;
}

class Word {
private:
	char* word;
	char* definition;
public:
	Word(): word(NULL), definition(NULL) {}
	Word(const char* word, const char* definition): word(NULL), definition(NULL) {
		setWord(word, definition);
	}

	bool setString(char* destination, const char* source) {
		delete [] destination;
		destination = new(std::nothrow) char[strlen(source) + 1];
		if(destination == NULL) {
			handleMemoryError();
		}
		return strcpy(destination, source);
	}
	
	void setWord(const char* word, const char* definition) {
		setString(this->word, word);
		setString(this->definition, definition);
	}

	~Word(){
		delete [] word;
		delete [] definition;
	}

	void handleMemoryError() {
		cout<< "couldn't allocate memory"<< endl;
	}
};

class Dictionary {
private:
	Word words[500];
public:
	Dictionary() {}
};

int main () {

	return 0;
}
