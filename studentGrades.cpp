#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Student {
	string lastName;
	int studentID;
	double* scores;
	double averages;
	char letterGrade;
};

string getData();
bool openFile(ifstream& file, string filename);
bool readData(ifstream& file, Student*& students, int& numStudents, int& numGrades);
void getAverages(Student* students, int numStudents, int numGrades);
void assignLetterGrade(Student* students, int numStudents, int numGrades);
void displayReport(const Student* students, int numStudents);
void releaseMemory(Student*& students, int numStudents);

int main() {
	Student* students = nullptr;
	int numStudents = 0;
	int numGrades = 0;
	ifstream file;

	string filename = getData();
	if (!openFile(file, filename)) {
		return 1;
	}
	return 0;
	
	readData(file, students, numStudents, numGrades);
	getAverages(students, numStudents, numGrades);
	assignLetterGrade(students, numStudents, numGrades);
	displayReport(students, numStudents);
	releaseMemory(students, numStudents);
}

string getData(){
	string filename;
	cout << "Enter the name of the file" << endl;
	cin >> filename;
	return filename;
}

bool openFile(ifstream& file, string filename) {
	file.open(filename);

	if (!file) {
		cout << "Error, couldnt access file.\n";
		return false;
	}
	return true;
}

bool readData(ifstream& file, Student*& students, int& numStudents, int& numGrades) {
	students = new Student[numStudents];
	for (int i = 0; i < numStudents; i++) {
		students[i].scores = nullptr;
		students[i].averages = 0;
		students[i].letterGrade = ' ';
	}

	for (int i = 0; i < numStudents; i++) {
		students[i].scores = new double[numGrades];
	}

return true;
}

void getAverages(Student* students, int numStudents, int numGrades) {
	for (int i = 0; i < numStudents; i++) {
		double total = 0;
		for (int j = 0; j < numGrades; j++) {
			total += students[i].scores[j];
		}
		students[i].averages = total / numGrades;
	}
}

void assignLetterGrade(Student* students, int numStudents, int numGrades) {
	for (int i = 0; i < numStudents; i++) {
		double average = students[i].averages;
		if (average >= 90)
			students[i].letterGrade = 'A';
		else if (average < 90 && average >= 80)
			students[i].letterGrade = 'B';
		else if (average < 80 && average >= 70)
			students[i].letterGrade = 'C';
		else if (average < 70 && average >= 60)
			students[i].letterGrade = 'D';
		else
			students[i].letterGrade = 'F';
	}
}

