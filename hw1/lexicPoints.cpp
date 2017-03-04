#include<iostream>
using namespace std;

struct Point {
	int x;
	int y;

	Point() {}
	Point(int nX, int nY){
		x = nX;
		y = nY;
	}

	void print() {
		cout<< "x: "<< x<< " y: "<< y<< endl;
	}
};

void sortPoints(Point* points, int total) {
	for(int i = total; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(points[j].x>points[i].x || (points[i].x == points[j].x && points[j].y > points[i].y)){
				Point temp = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
}

int main () {
	Point points[5];
	points[0] = Point(5,7);
	points[1] = Point(5,6);
	points[2] = Point(3,11);
	points[3] = Point(2,1);
	points[4] = Point(8,3);

	sortPoints(points, 5);
	
	for(int i=0; i<5; i++) {
		points[i].print();
	}

	return 0;
}
