#include<iostream>
#include<cmath>
using namespace std;

struct Rect;
struct Polar;

const double PI = 3.14159265;

double toRadians(double deg){
	return deg*PI/180;
}
double toDegrees(double rad){
	return rad*180/PI;
}

struct Rect {
	int x;
	int y;
	Rect(int nX, int nY) {
		x = nX;
		y = nY;
	}

	Rect(Polar& polar);

	void print(){
		cout<< "x: "<< x<< ", y: "<< y<< endl;
	}
};

struct Polar {
	double angle;
	float radius;
	Polar(double nAngle, float nRadius) {
		angle = nAngle;
		radius = nRadius;
	}

	Polar(Rect& rect);

	void print(){
		cout<< "angle: "<< angle<< ", radius: "<< radius<< endl;
	}
};

Rect::Rect(Polar& polar) {
	x = round(cos(toRadians(polar.angle))*polar.radius);
	y = round(sin(toRadians(polar.angle))*polar.radius);
}

Polar::Polar(Rect& rect) {
	radius = sqrt(rect.x*rect.x + rect.y*rect.y);
	angle = toDegrees(atan(double(rect.y)/rect.x));
}

int main () {
	

	return 0;
}
