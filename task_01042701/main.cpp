#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Student {
private:
	std::string firstName;
	std::string lastName;
	double averageGrade;

public:


	Student(const std::string& fName, const std::string& lName, double avgGrade)
		: firstName(fName), lastName(lName), averageGrade(avgGrade) {}


	// ������
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	double getAverageGrade() const { return averageGrade; }

	// �������� ������
	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		const int fieldWidth = 15; // ������ ����

		os << std::setw(fieldWidth) << "��'�: " << std::setw(fieldWidth) << student.firstName
			<< std::setw(fieldWidth) << ", �������: " << std::setw(fieldWidth) << student.lastName
			<< std::setw(fieldWidth) << ", ������� ���: " << student.averageGrade;
		return os;
	}



};
// ������� ��� ������ �������� � ��������� �����
Student findStudentWithHighestGrade(const std::vector<Student>& students) {
	auto maxStudentIterator = std::max_element(students.begin(), students.end(),
		[](const Student& a, const Student& b) {
			return a.getAverageGrade() < b.getAverageGrade();
		});

	return *maxStudentIterator;
}

int main() {
	system("chcp 1251>nul");

	// ��������� ������� ��������
	std::vector<Student> students = {
		{"����" , "��������", 85.5},
		{"�����", "�����"  , 85.5},
		{"����", "�������" , 90.2},
		{"����" , "�������" , 88.0},

	};

	std::cout << "������ ��������:" << std::endl;
	for (const auto& student : students) {
		std::cout << student << std::endl;
	}


	// ����� �������� � ��������� �����
	Student topStudent = findStudentWithHighestGrade(students);

	// ��������� ���������� ��� ���������� ��������
	std::cout << "������� � �������� �����:\n" << topStudent << std::endl;

	return 0;
}
