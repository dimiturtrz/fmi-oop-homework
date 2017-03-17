#include<iostream>
using namespace std; 

template<typename T>
T abs(T val) {
	return (val > 0) ? val : -val;
}

struct Point {
	int x;
	int y;

	Point():x(0), y(0){}
	Point(int x, int y): x(x), y(y){}
};

ostream& operator<<(ostream& stream, Point p) {
	stream<< "("<< p.x<< ", "<< p.y<< ")";
}

class Line {
private:
	Point start;
	Point end;
public:
	Line():start(Point()), end(Point()){}
	Line(Point start, Point end): start(start), end(end) {}
	Line(int x1, int y1, int x2, int y2): start(Point(x1, y1)), end(Point(x2, y2)){}

	float slope() const {
		float slope = end.y - start.y;
		slope /= (end.x - start.x);
		return slope;
	}

	float intercept() const {
		return end.y - (end.x*slope());
	}

	bool operator||(Line& other) const {
		float slope1 = slope();
		float slope2 = other.slope();
		return (abs(slope1 - slope2) < 0.0001);
	}

	bool operator||(Point& point) const {
		Line compLine = Line(start, point);
		return *this||compLine;
	}

	Point operator+(Line& other) const {
		if(*this||other)
			return Point(0, 0);

		const float slope1 = slope();
		const float slope2 = other.slope();

		const float intercept1 = intercept();
		const float intercept2 = other.intercept();

		float x = (intercept2 - intercept1)/(slope1 - slope2);
		float y = intercept1 + x*slope1;
		
		return Point(x, y);
	}
};

int main () {
	Line line1 = Line(0, 0, 5, 5);
	Line line2 = Line(5, 5, 10, 17);

	cout<< (line1||line2)<< endl;

	Point p1(1,1);
	cout<< (line1||p1)<< endl;

	Line line3 = Line(0, 0, 1, 1);
	Line line4 = Line(0, 2, 2, 0);
	cout<< (line3+line4)<< endl;
	
	return 0;
}
