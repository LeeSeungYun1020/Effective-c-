#include <iostream>
#include <utility>
#include <vector>

using namespace std;

enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장 };

class Employee {
	string name;
	EmployeeLevel level;
public:
	explicit Employee(string name, const EmployeeLevel& level) : name(move(name)), level(level) {}
	explicit Employee(const Employee& copy) : name(copy.name), level(copy.level) {}
	~Employee() = default;

	const string& getName() const {
		return name;
	}

	const EmployeeLevel& getEmployeeLevel() const {
		return level;
	}

	void setName(const string& name) {
		this->name = name;
	}

	void setLevel(const EmployeeLevel& level) {
		this->level = level;
	}

	friend ostream& operator<<(ostream& os, const Employee& employee);
};

class Manager : public Employee {
	vector<Employee*> group;
public:
	explicit Manager(string name, const EmployeeLevel& level) : Employee(move(name), level) {}
	explicit Manager(const Manager& copy) = default;

	~Manager() {
		for (auto employee : group)
			delete employee;
		group.clear();
	}

	void addEmployee(const Employee* employee) {
		group.push_back(new Employee(*employee));
	}

	friend ostream& operator<<(ostream& os, const Manager& manager);
};

ostream& operator<<(ostream& os, const Employee& employee) {
	os << employee.level << ' ' << employee.name << endl;
	return os;
}

ostream& operator<<(ostream& os, const Manager& manager) {
	os << manager.getEmployeeLevel() << ' ' << manager.getName() << endl
		<< "List of employees managed by me" << endl;
	for (auto employee : manager.group)
		os << *employee;
	return os;
}

int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
	cout << e1 << e2 << e3;
	Manager m1("Tom", 차장);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
}
