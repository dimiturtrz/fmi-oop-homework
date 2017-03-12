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

class Line {
private:
	Point start;
	Point end;
public:
	Line():start(Point()), end(Point()){}
	Line(Point start, Point end): start(start), end(end) {}
	Line(int x1, int y1, int x2, int y2): start(Point(x1, y1)), end(Point(x2, y2)){}

	bool operator||(Line& other) {
		float slope1 = abs(((float)(end.y - start.y))/(end.x-start.x));
		float slope2 = abs(((float)(other.end.y - other.start.y))/(other.end.x-other.start.x));
		cout<< slope1<< " "<< slope2<< endl;
		return (abs(slope1 - slope2) < 0.0001);
	}
};

int main () {
	Line line1 = Line(0, 0, 5, 5);
	Line line2 = Line(5, 5, 10, 17);

	cout<< (line1||line2)<< endl;

	
	return 0;
}
