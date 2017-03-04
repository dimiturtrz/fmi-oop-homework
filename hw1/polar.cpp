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

	Rect(){}
	Rect(Polar& polar);

	void print(){
		cout<< "x: "<< x<< ", y: "<< y<< endl;
	}
};

struct Polar {
	double angle;
	double radius;
	Polar(double nAngle, double nRadius) {
		angle = nAngle;
		radius = nRadius;
	}

	Polar() {}
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
	char RorP;	
	cout<< "type 'r' for rectangular, 'p' for polar"<< endl;
	cin>> RorP;
	int x, y;
	Rect rect;
	double angle, radius;
	Polar pol;
	for(int i=0; i<5; i++) {
		switch(RorP) {
			case 'r':
				cin>> x>> y;
				rect = Rect(x,y);
				pol = Polar(rect);
				pol.print();
				break;
			case 'p':
				cin>> angle>> radius;
				Polar pol = Polar(angle, radius);
				rect = Rect(pol);
				rect.print();
		}
		cout<< endl;
	}

	return 0;
}
