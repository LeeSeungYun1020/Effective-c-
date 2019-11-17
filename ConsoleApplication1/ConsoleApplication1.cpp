#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	float gpa;
public:
	Student(const string& name, const float gpa) :name(name), gpa(gpa) {}
	~Student() = default;

	void setName(const string& name) {
		this->name = name;
	}
	void setGPA(const float gpa) {
		this->gpa = gpa;
	}
	const string& getName() const {
		return name;
	}
	float getGPA() const {
		return gpa;
	}
};

void print(const vector<Student>& students) {
	cout << "Student Count: " << students.size() << endl;
	for(Student student: students) {
		cout << "\tName: " << student.getName() << " GPA: " << student.getGPA() << endl;
	}
}

void sort(vector<Student>& students) {
	for(unsigned int i = 0; i < students.size() - 1; i++) {
		unsigned int max = i;
		for(unsigned int j = i + 1; j < students.size(); j++) {
			if (students[i].getGPA() < students[j].getGPA()) {
				max = j;
			} else if (students[i].getGPA() == students[j].getGPA() && students[i].getName().compare(students[j].getName()) > 0) {
				max = j;
			}
			
		}
		if(max != i) {
			swap(students[i], students[max]);
		}
	}
}

int main() {
	vector<Student> students;
	Student s1("Kim", 3.5F);
	students.push_back(s1);
	Student s2("Park", 3.5F);
	students.push_back(s2);
	Student s3("Lee", 3.5F);
	students.push_back(s3);
	print(students);
	sort(students); // descending
	print(students);
	Student& topStudent = students[0];
	topStudent.setGPA(3.3F);
	topStudent.setName("Yoon");
	Student s4("Hong", 4.3F);
	students.push_back(s4);
	print(students);
	sort(students);
	print(students);
	cout << "The Top Student: Name " << students[0].getName() << " GPA: " << students[0].getGPA() << endl;
}