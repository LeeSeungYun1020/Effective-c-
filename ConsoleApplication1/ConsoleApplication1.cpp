#include <iostream>

using namespace std;

class MyString {
private:
	char* str;
	int size;
public:
	explicit MyString(const char* str) {
		size = std::strlen(str);
		this->str = new char[size];
		for (unsigned int i = 0; i < size; i++)
			this->str[i] = str[i];
	}

	explicit MyString(const MyString& copy) : size(copy.size) {
		str = new char[size];
		for (unsigned int i = 0; i < size; i++)
			str[i] = copy.str[i];
	}

	~MyString() {
		delete[] str;
	}

	bool set(const unsigned int position, const char ch) const {
		if (position >= size)
			return false;
		str[position] = ch;
		return true;
	}

	void print() const {
		for (unsigned int i = 0; i < size; i++)
			cout << str[i];
		cout << endl;
	}

	int length() const {
		return size;
	}

	char at(const unsigned int position) const {
		if (position >= size)
			throw length_error(&"Can't access "[position]);
		return str[position];
	}
};

int main() {
	MyString str1("ABC");
	str1.print();
	{
		MyString str2(str1);
		str2.set(0, 'D');
		str2.print();
	}
	str1.print();

	for (int i = 0; i < str1.length(); i++)
		cout << str1.at(i);
}
