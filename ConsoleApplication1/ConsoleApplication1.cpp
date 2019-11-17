#include <iostream>
#include <utility>
#include <vector>

using namespace std;

enum class MajorType { CE, EE, ME, UD };

class Major {
private:
	MajorType majorType;
public:
	explicit Major(const MajorType& major = MajorType::UD): majorType(major) {}

	const MajorType& getMajorType() const {
		return majorType;
	}

	void setMajorType(const MajorType& majorType) {
		this->majorType = majorType;
	}

	string toString() const {
		switch (majorType) {
			case MajorType::CE:
				return "Computer Eng.";
				break;
			case MajorType::EE:
				return "Electrical Eng.";
				break;
			case MajorType::ME:
				return "Mechanical Eng.";
				break;
			case MajorType::UD:
			default:
				return "Undefined";
				break;
		}

	}
};

class Student {
private:
	string name;
	float gpa;
	Major major;
public:
	explicit Student(string name, const float gpa, const MajorType& major)
		: name(std::move(name)), gpa(gpa), major(Major(major)) {
		print();
	}

	const string& getName() const {
		return name;
	}

	float getGPA() const {
		return gpa;
	}

	const MajorType& getMajor() const {
		return major.getMajorType();
	}

	void setName(const string& name) {
		this->name = name;
	}

	void setGPA(const float gpa) {
		this->gpa = gpa;
	}

	void setMajor(const MajorType& majorType) {
		this->major.setMajorType(majorType);
	}

	void print() const {
		cout << "Name: " << name << " GPA: " << gpa << " Major: " << major.toString() << endl;
	}
};

class School {
private:
	string schoolName;
	vector<Student> students;
public:
	explicit School(string schoolName): schoolName(std::move(schoolName)) {}

	~School() {
		students.clear();
	}

	void setSchoolName(const string& schoolName) {
		this->schoolName = schoolName;
	}

	const string& getSchoolName() const {
		return schoolName;
	}

	Student* addStudent(const string& studentName, const float gpa = 0.0F, const MajorType major = MajorType::UD) {
		students.emplace_back(studentName, gpa, major);
		return &students.back();
	}

	Student* addStudent(const string& studentName, const MajorType major = MajorType::UD) {
		return addStudent(studentName, 0.0F, major);
	}

	void print() const {
		cout << "School Name: " << schoolName << ", Count: " << students.size() << endl;
		for (const Student& student : students)
			student.print();
	}

	void sort() {
		for (unsigned int i = 0; i < students.size() - 1; i++) {
			int max = i;
			for (unsigned int j = i + 1; j < students.size(); j++) {
				if (students[max].getGPA() < students[j].getGPA())
					max = j;
				else if (students[max].getGPA() == students[j].getGPA() && 
						 students[max].getName().compare(students[j].getName()) > 0
				)
					max = j;
			}
			if (max != i)
				swap(students[max], students[i]);
		}
	}
};

int main() {
	School pnu("PNU");
	Student* kim = pnu.addStudent("Kim", MajorType::EE);
	kim->setGPA(3.5F);
	Student* hong = pnu.addStudent("Hong", MajorType::CE);
	hong->setGPA(4.3F);
	Student* lee = pnu.addStudent("Lee", 4.0F);
	lee->setMajor(MajorType::CE);
	Student* joo = pnu.addStudent("Joo", 1.5F);
	joo->setMajor(MajorType::ME);
	pnu.print();
	pnu.sort(); // descending
	pnu.print();
}
