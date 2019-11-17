#include <iostream>
#include <vector>
#include <cassert>
#include <cctype>

using namespace std;

struct Rectangle {
	int width;
	int height;
};

enum CommandType {
	ADD,
	SORT,
	PRINT,
	CLEAR,
	EXIT
};

// 이상 제약 조건

CommandType getCommandType() {
	string command;
	cin >> command;
	for (char& c: command) {
		c = std::toupper(c);
	}
	if (command == "ADD") {
		return ADD;
	} else if (command == "SORT") {
		return SORT;
	} else if (command == "PRINT") {
		return PRINT;
	} else if (command == "CLEAR") {
		return CLEAR;
	} else if (command == "EXIT") {
		return EXIT;
	} else {
		cout << "Please check command. (add, sort, print, clear, exit)" << endl;
		return getCommandType();
	}
}

Rectangle& getRectangle() {
	auto rectangle = new Rectangle;
	cin >> rectangle->width >> rectangle->height;
	return *rectangle;
}

void print(const vector<Rectangle>& rectangles) {
	cout << "Rectangle Count: " << rectangles.size() << endl;
	for(const Rectangle& r: rectangles) {
		cout << r.width << '\t' << r.height << '\t' << (r.width * r.height) << endl;
	}
}

void sort(vector<Rectangle>& rectangles) {
	for (unsigned int i = 0; i < rectangles.size() - 1; i++) {
		int min = i;
		for (unsigned int j = i + 1; j < rectangles.size(); j++) {
			if (rectangles[min].width * rectangles[min].height > rectangles[j].width* rectangles[j].height)
				min = j;
		}
		if(min != i) {
			const Rectangle tem = rectangles[i];
			rectangles[i] = rectangles[min];
			rectangles[min] = tem;
		}
	}
}

int main() {
	vector<Rectangle> rectangles;
	while (true) {
		const CommandType command = getCommandType();
		switch (command) {
			case ADD: {
				const Rectangle& newRectangle = getRectangle();
				rectangles.push_back(newRectangle);
				break;
			}
			case PRINT: {
				print(rectangles);
				break;
			}
			case SORT: {
				sort(rectangles);
				print(rectangles);
				break;
			}
			case CLEAR: {
				rectangles.clear();
				break;
			}
			case EXIT: {
				break;
			}
			default: {
				assert(false);
				break;
			}
		}
		if(command == EXIT)
			break;
	}
}
