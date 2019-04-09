/*
*
*   Name: Chris Gallagher
*   Lab 12
*  
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

ifstream inStream; // in and out variables

struct Employee {
    int ID;
    string firstName;
    string lastName;
    double salary;
};

void printStudent (const vector <Employee> allEmployees);
void lastNameSort (vector <Employee> &allEmployees);

int main(int argc, char *argv[]) {
    string inFileText;
    cout << "Enter an input file: ";
    cin >> inFileText;
    inStream.open(inFileText.c_str());
    if (inStream.fail()) {
        cout << "Error: The given input file is invalid." << endl;
        exit(1);
    }
    vector <Employee> allEmployees;
    Employee currentEmployee;
    inStream >> currentEmployee.ID;
    inStream >> currentEmployee.firstName;
    inStream >> currentEmployee.lastName;
    inStream >> currentEmployee.salary;

    while (!inStream.eof()) {
        allEmployees.push_back(currentEmployee);
        inStream >> currentEmployee.ID;
        inStream >> currentEmployee.firstName;
        inStream >> currentEmployee.lastName;
        inStream >> currentEmployee.salary;
        lastNameSort(allEmployees);
    }
    printStudent(allEmployees);
    



    inStream.close();
}

void printStudent (const vector <Employee> allEmployees) {
    int size = allEmployees.size();
    cout << "Sorted by last name." << endl;
    cout << endl;
    cout << "ID" << setw(20) << "Name" << setw(30) << "Salary" << endl;
    for (int i = 0; i < size; i++) {
        cout << allEmployees[i].ID << setw(15);
        cout << allEmployees[i].firstName << " ";
        cout << allEmployees[i].lastName << setw(20);
        cout << allEmployees[i].salary << endl;
        cout << endl;
    }
}

void lastNameSort (vector <Employee> &allEmployees) {
    int size = allEmployees.size();
    for (int i = 0; i < size; i++) {
        char currentChar = allEmployees[i].lastName[0];
        for (int j = i+1; j < size; j++) {
            if (currentChar > allEmployees[j].lastName[0]) {
                swap (allEmployees[i], allEmployees[j]);
            }
        }
    }
}


