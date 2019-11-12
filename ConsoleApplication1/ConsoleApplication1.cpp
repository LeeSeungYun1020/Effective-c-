// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A {
public:
	A();
};

class B {
public:
	int x;
	bool b;
	explicit B(int x = 0, bool b = false) {
		this->x = x;
		this->b = b;
	}
};

class C {
public:
	explicit C(int x);
};

void doSomething(B bObject) {
	std::cout << "x = " << bObject.x << ", b = " << bObject.b << std::endl;
	// 결과를 표시해 확인하기 위해 책과 달리 출력문을 별도로 만듬.
}

int main()
{
    //std::cout << "Hello World!\n";
	
	B bObj1;
	doSomething(bObj1);
	B bObj2(28);
	doSomething(28); // 생성자에서 explicit 키워드를 사용하여 예상치 못한 타입 자동 변환을 막음.
	doSomething(B(28));
}