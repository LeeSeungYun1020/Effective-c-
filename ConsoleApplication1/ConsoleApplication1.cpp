#include <iostream>
#include <vector>

using namespace std;

class Point {
	int x, y;
public:
	explicit Point(const int x = 0, const int y = 0): x(x), y(y) {}
	Point(const Point& copy) = default;
	~Point() = default;

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	friend ostream& operator<<(ostream& os, const Point& point);
};

ostream& operator<<(ostream& os, const Point& point) {
	os << '(' << point.x << ", " << point.y << ')';
	return os;
}

class Shape {
public:
	explicit Shape() = default;
	Shape(const Shape& shape) = default;
	virtual ~Shape() = default;

	virtual void print() const {
		cout << "Shape" << endl;
	}
};

class Polygon : public Shape {
	Point* point;
	int numberOfPoint;

public:
	explicit Polygon(const int numberOfPoint): numberOfPoint(numberOfPoint) {
		point = new Point[numberOfPoint];
	}

	explicit Polygon(const Polygon& copy): numberOfPoint(copy.numberOfPoint) {
		point = new Point[numberOfPoint];
		for (unsigned int i = 0; i < numberOfPoint; i++)
			point[i] = copy.point[i];
	}

	~Polygon() {
		delete[] point;
	}

	Point* getPoint() const {
		return point;
	}

	int getNumberOfPoint() const {
		return numberOfPoint;
	}

	void print() const override {
		cout << "Polygon: ";
		for (unsigned int i = 0; i < numberOfPoint; i++) {
			cout << getPoint()[i];
		}
		cout << endl;
	}

	virtual float getArea() const {
		float result = 0;
		for (unsigned int i = 0; i < numberOfPoint - 1; i++) {
			result += point[i].getX() * point[i + 1].getY() - point[i + 1].getX() * point[i].getY();
		}
		result /= 2;
		return (result >= 0) ? result : -result;
	}
};

class Rectangle : public Polygon {
public:
	explicit Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : Polygon(4) {
		Point* point = getPoint();
		point[0] = p1;
		point[1] = p2;
		point[2] = p3;
		point[3] = p4;
	}


	Rectangle(const Rectangle& copy) : Polygon(4) {
		for (unsigned int i = 0; i < 4; i++)
			getPoint()[i] = copy.getPoint()[i];
	}

	~Rectangle() = default;

	void print() const override {
		cout << "Rectangle: ";
		for (unsigned int i = 0; i < 4; i++) {
			cout << getPoint()[i];
		}
		cout << endl;
	}

	float getArea() const override {
		return Polygon::getArea();
	}
};

class Triangle : public Polygon {
public:
	explicit Triangle(const Point& p1, const Point& p2, const Point& p3): Polygon(3) {
		Point* point = getPoint();
		point[0] = p1;
		point[1] = p2;
		point[2] = p3;
	}

	Triangle(const Triangle& copy): Polygon(3) {
		for (unsigned int i = 0; i < 3; i++)
			getPoint()[i] = copy.getPoint()[i];
	}

	~Triangle() = default;

	void print() const override {
		cout << "Triangle: ";
		for (unsigned int i = 0; i < 3; i++)
			cout << getPoint()[i];
		cout << endl;
	}

	float getArea() const override {
		return Polygon::getArea();
	}

};

class ShapeList {
	vector<Shape*> shapes;
public:
	ShapeList() = default;
	ShapeList(const ShapeList& copy): shapes(copy.shapes) {}

	~ShapeList() {
		shapes.clear();
	}

	void addShape(Shape* const p) {
		shapes.push_back(p);
	}

	void print() const {
		for (auto shape : shapes) {
			(*shape).print();
		}
	}

	float getTotalArea() const {
		float area = 0;
		for (auto shape : shapes) {
			try {
				area += (*dynamic_cast<Polygon*>(shape)).getArea();
			} catch (exception& e) {
				throw logic_error("Can't calculate area");
			}

		}
		return area;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 30), p4(20, 20);
	Shape* r = new Rectangle(p1, p2, p3, p4);
	Shape* t = new Triangle(p1, p2, p3);
	ShapeList list;
	list.addShape(r);
	list.addShape(t);
	list.print();
	cout << list.getTotalArea() << endl;
	return 0;
}
