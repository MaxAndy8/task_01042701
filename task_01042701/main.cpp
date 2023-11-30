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


	// Гетери
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	double getAverageGrade() const { return averageGrade; }

	// Оператор виводу
	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		const int fieldWidth = 15; // Ширина поля

		os << std::setw(fieldWidth) << "Ім'я: " << std::setw(fieldWidth) << student.firstName
			<< std::setw(fieldWidth) << ", Прізвище: " << std::setw(fieldWidth) << student.lastName
			<< std::setw(fieldWidth) << ", Середній бал: " << student.averageGrade;
		return os;
	}



};
// Функція для пошуку студента з найбільшим балом
Student findStudentWithHighestGrade(const std::vector<Student>& students) {
	auto maxStudentIterator = std::max_element(students.begin(), students.end(),
		[](const Student& a, const Student& b) {
			return a.getAverageGrade() < b.getAverageGrade();
		});

	return *maxStudentIterator;
}

int main() {
	system("chcp 1251>nul");

	// Створення вектора студентів
	std::vector<Student> students = {
		{"Іван" , "Іваненко", 85.5},
		{"Петро", "Петрів"  , 85.5},
		{"Марія", "Іванова" , 90.2},
		{"Олег" , "Сидоров" , 88.0},

	};

	std::cout << "Список студентів:" << std::endl;
	for (const auto& student : students) {
		std::cout << student << std::endl;
	}


	// Пошук студента з найбільшим балом
	Student topStudent = findStudentWithHighestGrade(students);

	// Виведення інформації про знайденого студента
	std::cout << "Студент з найвищим балом:\n" << topStudent << std::endl;

	return 0;
}
