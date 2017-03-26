#include<iostream>
using namespace std;

enum Month {
	January = 1, February, March, April,
	May, June, Jule, August,
	September, October, November, December
};

int strlen(const char* str) {
	int len = 0;
	for(; str[len] != '\0'; len++)
	return len;
}

void strcpy(char* destination, const char* source) {
	int index = 0;
	for(; source[index] != '\0'; index++) {
		destination[index] = source[index];
	}
	destination[index] = '\0';
}

struct BrowserEntry {
	Month month;
	char* url;

	const char* getUrl() const {
		return url;
	}

	Month getMonth() const {
		return month;
	}

	void setUrl(const char* newUrl) {
		delete url;
		url = new(nothrow) char[strlen(newUrl)];
		if(url == NULL) {
			cout<< "cannot allocate memory\n";
			delete url;
		}
		strcpy(url, newUrl);
	}

	BrowserEntry(): month(January), url(NULL){}
	BrowserEntry(Month month, char* _url): month(month) {
		url = NULL;
		setUrl(_url);
	}

	BrowserEntry(const BrowserEntry& other) {
		month = other.month;
		setUrl(other.url);
	}

	BrowserEntry& operator=(const BrowserEntry& other) {
		if(this == &other) {
			return *this;
		}

		month = other.month;
		setUrl(other.url);

		return *this;
	}

	~BrowserEntry() {
		delete url;
	}
};

ostream& operator<<(ostream& stream, const BrowserEntry& entry) {
	stream<< entry.getUrl()<< " "<< entry.getMonth();
	return stream;
}

class BrowserHistory {
	int N;
	BrowserEntry* entries;

	void setEntries(BrowserEntry* newEntries) {
		delete [] entries;
		entries = new(nothrow) BrowserEntry[N];
	
		if(entries == NULL) {
			cout<< "couldn't allocate memory\n";
			return;
		}
	
		for(int index = 0; index < N; index++) {
			entries[index] = newEntries[index];
		}
	}

	BrowserHistory(int N): N(N), entries(NULL) {}
	BrowserHistory(BrowserHistory& other) {
		N = other.N;
		setEntries(other.entries);
	}
	
	BrowserHistory& operator=(BrowserHistory& other) {
		if(this == &other) {
			return *this;
		}

		N = other.N;
		setEntries(other.entries);

		return *this;
	}

	~BrowserHistory() {
		delete [] entries;
	}

	void addEntry(const BrowserEntry& newEntry) {
		BrowserEntry* newEntries = new(nothrow) BrowserEntry[N+1];
		
		if(newEntries == NULL) {
			cout<< "couldn't allocate memory\n";
			return;
		}

		for(int i=0; i<N; i++) {
			newEntries[i] = entries[i];
		}
		newEntries[N] = newEntry;

		delete [] entries;
		entries = newEntries;
	}

	
};

int main () {
	return 0;
}
