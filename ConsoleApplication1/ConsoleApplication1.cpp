#include <iostream>
#include <random>
#include <set>
#include <cctype>

using namespace std;

class Score {
private:
	int* list;
	int size;
	int pos;
public:
	Score(int size): size(size), pos(0) {
		list = new int[size];
	}

	~Score() {
		delete[] list;
	}

	bool add(const int value) {
		if (pos > size - 1) {
			return false;
		} else {
			list[pos] = value;
			pos++;
			return true;
		}
	}

	int sum() {
		int result = 0;
		for (int i = 0; i < pos; ++i) {
			result += list[i];
		}
		return result;
	}

	double average() {
		return static_cast<double>(sum()) / pos;
	}

	void print(const string& command) {
		if (command == "add") {
			cout << "Enter Score: ";
			int value;
			cin >> value;
			if (value < 0) {
				cout << "System: " << value << "can't be score" << endl;
			} else if (add(value)) {
				cout << "System: " << value << " added." << endl;
			} else {
				cout << "System: Too many score" << endl;
			}
		} else if (command == "sum") {
			cout << "System: Sum: " << sum() << endl;
		} else if (command == "average") {
			if (pos == 0)
				cout << "1개 이상의 점수가 입력되어야 합니다." << endl;
			else
				cout << "System: Avg: " << average() << endl;
		}
	}
};

int main() {
	cout << "Enter the score count: ";
	int maxSize;
	cin >> maxSize;
	Score score(maxSize);
	string command;
	while (command != "quit") {
		cout << "Enter Command: (add, sum, average, quit) ";
		cin >> command;
		for (char& i : command) {
			i = std::tolower(i);
		}
		score.print(command);
	}
}
