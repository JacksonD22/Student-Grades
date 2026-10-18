#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Grades {
	string lastName;
	int studentID;
	double* scores;
	double averages;
	char letterGrade;
};

string getData();
bool openFile();
void getAverages();
void assignLetterGrade();
void displayReport();

int main() {

}