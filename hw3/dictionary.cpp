#include<iostream>
using namespace std;

int strlen (const char* str) {
	int i;
	for(i = 0; str[i]!= '\0'; i++);
	return i;
}

void strcpy(char* destination, const char* source) {
	for(int i=0; source[i] != '\0'; i++)
		destination[i] = source[i];
}

int strcmp(const char* str1, const char* str2) {
	for(int i=0; str1[i]!= '\0'; i++){
		if(str1[i] != str2[i])
			return (str1[i] > str2[i]) ? 1 : -1;
}
			// if str2[i] = '\0' that's 0 so str1 is constdered greater
	return (strlen(str1) == strlen(str2)) ? 0 : 1;
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

	void setString(char*& destination, const char* source) {
		delete [] destination;
		destination = new(std::nothrow) char[strlen(source) + 1];
		if(destination == NULL) {
			handleMemoryError();
			return;
		}
		strcpy(destination, source);
	}
	
	void setWord(const char* word, const char* definition) {
		setString(this->word, word);
		setString(this->definition, definition);
	}

	const char* getWord() const {
		return word;
	}

	const char* getDefinition() const {
		return definition;
	}

	bool operator>(const Word& other) const {
		return strcmp(this->word, other.word) == 1;
	}

	bool operator<(const Word& other) const {
		return strcmp(this->word, other.word) == -1;
	}

	bool operator==(const Word& other) const {
		return strcmp(this->word, other.word) == 0;
	}

	bool operator==(const char* word) const {
		return strcmp(this->word, word) == 0;
	}

	Word(const Word& other) {
		freeWord();
		this->word = other.word;
		this->definition = other.definition;
		// they're somewhere in the heap so the stack memory of the words array should be fine
		*this = other;
	}

	Word& operator=(const Word& other){
		if(this != &other)
			Word(other);
		return *this;
	}

	void freeWord() {
		delete [] word;
		word = NULL;
		delete [] definition;
		definition = NULL;
	}

	~Word(){
		freeWord();
	}

	void handleMemoryError() {
		cout<< "couldn't allocate memory"<< endl;
	}
};

ostream& operator<<(ostream& stream, const Word& word) {
	stream<< word.getWord()<< " - "<< word.getDefinition()<< endl;
	return stream;
}

class Dictionary {
private:
	Word words[500];
	int currWords;
public:
	Dictionary(): currWords(0) {
		for(int i=0; i<500; i++)
			words[i] = Word();
	}

	int findWord(const char* word) const {
		for(int i=0; i<currWords; i++)
			if(words[i] == word)
				return i;
		return -1;
	}

	const char* findDefinition(const char* word) const {
		int index = findWord(word);
		return (index != -1) ? words[index].getDefinition() : NULL;
	}
	
	void addWord(const char* word, const char* definition) {
		words[currWords++].setWord(word, definition);
	}

	void removeWord(const char* word) {
		int index = findWord(word);
		if(index == -1)
			return;
		words[index] = words[currWords-1];
		currWords--;
	}

	void printWords() {
		for(int i=0; i<currWords; i++)
			cout<< words[i];
	}
};

int main () {
	Dictionary dict;
	dict.addWord("gosho", "pi4");
	cout<< dict.findDefinition("gosho")<< endl;
	dict.removeWord("gosho");
	dict.printWords();

	return 0;
}
