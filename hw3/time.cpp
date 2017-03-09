#include<iostream>
using namespace std;

const int minutesInAnHour = 60;
const int hoursInADay = 24;

class Time {
private:
	int hour;
	int minute;

	void normalize() {
		hour += minute/minutesInAnHour;
		minute %= minutesInAnHour;
		hour %= hoursInADay;
	}

public:
	Time(int hour, int minute): hour(hour), minute(minute) {}
	
	int getHour() const {
		return hour;
	}

	int getMinute() const {
		return minute;
	}

	bool setHour(int hour) {
		if(hour > hoursInADay-1)
			return false;
		this->hour = hour;
		return true;
	}
	bool setMinute(int minute) {
		if(minute > minutesInAnHour-1)
			return false;
		this->minute = minute;
		return true;
	}

	void addMinutes(int minutes) {
		minute += minutes;
		normalize();
	}

	int todayMinutes() const {
		return hour*minutesInAnHour + minute;
	}

	bool operator==(const Time& other) const {
		return hour==other.hour && minute==other.minute;
	}

	bool operator!=(const Time& other) const {
		return !(*this == other);
	}

	bool operator<(const Time& other) const {
		return todayMinutes() < other.todayMinutes();
	}

	bool operator>(const Time& other) const {
		return todayMinutes() > other.todayMinutes();
	}

	Time& operator+(const Time& other) {
		minute += other.todayMinutes();
		normalize();
		return *this;
	}

	Time& operator-(const Time& other) {
		minute -= other.todayMinutes();
		normalize();
		return *this;
	}

	Time& operator*(int scalar) {
		hour *= scalar;
		minute *= scalar;
		normalize();
		return *this;
	}

	void print() const {
		cout<< hour<< ":"<< minute<< endl;
	}
};

Time& operator*(int scalar, Time& time) {
	return time*scalar;
}

int main () {
	Time t1(17, 30), t2(22, 58);

	cout<< boolalpha<< (t1 < t2)<< endl;

	t1 = (t1 + Time(0, 30));
	t1.print();

	t1 = t1*2;
	t1.print();
	t1 = 2*t1;
	t1.print();
	
	return 0;
}
