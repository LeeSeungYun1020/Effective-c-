// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class Person {
	string lastName, firstName;
	int age;
public:
	Person(const string& first, const string& last, int age = 1)
		:lastName(last), firstName(first) {
		this->age = age;
	}
	~Person() {}//소멸자
	void setName(const string& lastName) {
		this->lastName = lastName;
	}
	void setName(const string& firstName, const string& lastName) {
		this->firstName = firstName;
		this->lastName = lastName;
	}
	string getName() const { 
		return lastName + ", " + firstName; 
	}
	virtual void print() const {
		cout << lastName << ", " << firstName << ", age of " << age << endl;
	}
};

class Student : public Person {
	string schoolName;
	int year;
public:
	Student(const string& firstName, const string& lastName,
		const string& schoolName, int year = 1)
		: Person(firstName, lastName, year + 19), schoolName(schoolName) {
		this->year = year;
	}
	int getYear() const { return year; }
	void print() const {
		cout << getName() << " is " << year << " grader in "
			<< schoolName << endl;
	}
};

class Complex {
private:
	double re, im;
public:
	Complex(double re = 0, double im = 0) {
		this->re = re;
		this->im = im;
	}

	Complex operator+ (const Complex& c) const {
		return Complex(re + c.re, im + c.im);
	}

	double getRe() const { return re; }
	double getIm() const { return im; }
};
ostream& operator << (ostream& os, const Complex& c) {
	os << c.getRe() << " + " << c.getIm() << "i";
	return os;
}

template <class T>
T myMax(T int1, T int2) {
	if (int1 > int2) return int1;
	return int2;
}
template <class T>
T findMax(T numbers[], int size) {
	T maxValue = numbers[0];
	for (int i = 1; i < size; i++)
		maxValue = myMax(maxValue, numbers[i]);
	return maxValue;
}

const int SIZE = 200;
template <class T>
class Stack {
	T elems[SIZE];
	int top;
public:
	Stack() { top = 0; }
	void push(const T& elem) { elems[top++] = elem; }
	T pop() { return elems[--top]; }
	bool isEmpty() const { return top == 0; }
};

const char* const E_NON_POSITIVE_LENGTH = "Non positive length";
const char* const E_NON_TRIANGLE = "Not a triangle";

int getTriangleLength(int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0) throw E_NON_POSITIVE_LENGTH;
	if (x + y <= z || x + z <= y || y + z <= x) throw E_NON_TRIANGLE;
	return x + y + z;

}

namespace NS1 {
	int value;
}
namespace NS2 {
	int value;
}

int main() {
	Student hong("kildong", "Hong", "HK", 5);
	cout << hong.getName() << endl;
	hong.print();

	Stack<int> is;
	is.push(100);
	cout << is.pop() << endl;

	Stack<Complex> cos;
	cos.push(Complex(10, 10));
	cos.push(Complex(20, 10));
	cout << cos.pop() << endl;

	int x, y, z;
	cin >> x >> y >> z;
	try {
		int totalLength = getTriangleLength(x, y, z);
		cout << totalLength << endl;
	}
	catch (const char* const e) {
		cout << e << endl;
	}

	NS1::value = 100;
	NS2::value = 200;

}