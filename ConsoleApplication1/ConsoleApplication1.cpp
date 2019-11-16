#include <iostream>
#include <vector>

using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
	string name;
	int scores[SUBJECT_NO];
	int sum;
	float average;
};
// 이상 제약사항

int main() {
	cout << " >> " << endl;
	signed int person;
	cin >> person;
	vector<StudentInfo> students(person);
	for (StudentInfo& student: students) {
		cin >> student.name;
		student.sum = 0;
		for (int& i: student.scores) {
			cin >> i;
			student.sum += i;
		}
		student.average = static_cast<float>(student.sum) / SUBJECT_NO;
	}
	
	//for (StudentInfo& student : students) {
	//	cout << student.name << '\t';
	//	for (int& i : student.scores)
	//		cout << i << '\t';
	//	cout << student.sum << '\t' << student.average << endl;
	//}
	for (vector<StudentInfo>::iterator/*auto*/ it = students.begin(); it != students.end(); it++) {
		cout << it->name << '\t';
		for (int& i : it->scores)
			cout << i << '\t';
		cout << it->sum << '\t' << it->average << endl;
	}
}
