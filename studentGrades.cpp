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