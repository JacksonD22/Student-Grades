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

	return 0;
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