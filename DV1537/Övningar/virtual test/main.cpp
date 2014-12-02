#include <iostream>

using namespace std;

class Shape {
public:
	virtual int area()=0;
};

class Triangle : public Shape {
private:
	int width, height;
public:
	Triangle(int width, int height){
		this->width = width;
		this->height = height;
	}
	int area(){
		return (width*height)/2;
	}
};

class Rectangle : public Shape {
private:
	int width, height;
public:
	Rectangle(int width, int height){
		this->width = width;
		this->height = height;
	}
	int area(){
		return width*height;
	}
};


int main(){
	Shape* shapes[10];
	shapes[0] = new Triangle(10,10);
	shapes[1] = new Rectangle(10,10);

	cout << "Triangle area: " << shapes[0]->area() << endl;
	cout << "Rectangle area: " << shapes[1]->area() << endl;
}