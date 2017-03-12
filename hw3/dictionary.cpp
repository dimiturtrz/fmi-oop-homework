#include<iostream>
using namespace std;

void handleMemoryError() {
	cout<< "couldn't allocate memory"<< endl;
}

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

char* strcat(const char* str1, const char* str2) {
	char* resStr = new(std::nothrow) char[strlen(str1)+strlen(str2)+1];
	if(resStr == NULL) {
		handleMemoryError();
		return NULL;
	}
	int i=0;
	for(; str1[i]!='\0'; i++)
		resStr[i] = str1[i];
	for(int l=0; str2[l]!='\0'; l++)
		resStr[l+(i++)] = str2[l];
	resStr[i] = '\0';
	return resStr; 
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
		if(word == NULL || definition == NULL)
			return;
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
		word = NULL;
		definition = NULL;
		setWord(other.word, other.definition);
		// if its still uninitialized theres no need to delete []
	}

	Word& operator=(const Word& other){
		if(this != &other)
			setWord(other.word, other.definition);
		return *this;
	}

	~Word(){
		delete [] word;
		word = NULL;
		delete [] definition;
		definition = NULL;
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

	void addWord(const Word& word) {
		addWord(word.getWord(), word.getDefinition());
	}

	void removeWord(const char* word) {
		int index = findWord(word);
		if(index == -1)
			return;
		words[index] = words[currWords-1];
		currWords--;
	}

	void sort() {
		for(int i=currWords-1; i>0; i--) {
			for(int j=0; j<i; j++) {
				if(words[j] > words[i]) {
					Word temp; // nowhere to null
					temp = words[j];
					words[j] = words[i];
					words[i] = temp;
				}
			}
		}
	}

	void printWords() {
		sort();
		for(int i=0; i<currWords; i++)
			cout<< words[i];
	}

	Dictionary operator+(Dictionary& other) const  {
		Dictionary resDict;
		for(int i=0; i<currWords && resDict.currWords < 500; i++)
			resDict.addWord(words[i]);
		for(int i=0; i<other.currWords && resDict.currWords < 500; i++){
			int index = resDict.findWord(words[i].getWord());
			if(index != -1) {
				resDict.addWord(other.words[i].getWord(), strcat(resDict.words[index].getDefinition(), other.words[i].getDefinition()));
			}
			resDict.addWord(other.words[i]);
		}

		return resDict;
	}
};

int main () {
	Dictionary dict;
	dict.addWord("gosho", "pi4");
	cout<< dict.findDefinition("gosho")<< endl;
	dict.removeWord("gosho");

	dict.addWord("aword", "kasj");
	dict.addWord("bword", "tesdf");
	dict.addWord("zjkdm", "testz");
	dict.addWord("gosho", "sadfasdfa");
	dict.addWord("bword2", "test32");
	dict.printWords();

	Dictionary dict2;
	dict2.addWord("sdaf", "kaasdfsj");
	dict2.addWord("bwasdford", "dtesdf");
	dict2.addWord("zasdfjkdm", "tessdatz");
	dict2.addWord("asdfgosho", "sadsdfdfasdfa");
	dict2.addWord("gfgdbword2", "tedfsdst32");

	cout<< endl<< endl;
	dict = dict + dict2;
	dict.printWords();

	return 0;
}
