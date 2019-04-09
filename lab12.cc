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
#include <cstring>
using namespace std;

ifstream inStream; // in and out variables

struct Employee {
    int ID;
    string firstName;
    string lastName;
    double salary;
};

void print (const vector <Employee> allEmployees);
void lastNameSort (vector <Employee> &allEmployees);
int totalPayroll (const vector <Employee> allEmployees);

int main(int argc, char *argv[]) {
    string inFileText;
    cout << "Enter an input file: ";
    cin >> inFileText;
    inStream.open(inFileText.c_str());
    if (inStream.fail()) { // check for failure
        cout << "Error: The given input file is invalid." << endl;
        exit(1);
    }
    vector <Employee> allEmployees; // vector for all employees
    Employee currentEmployee;
    inStream >> currentEmployee.ID; // take ID
    inStream >> currentEmployee.firstName; // take first name
    inStream >> currentEmployee.lastName; // take last name
    inStream >> currentEmployee.salary; // salary

    while (!inStream.eof()) {
        allEmployees.push_back(currentEmployee);
        inStream >> currentEmployee.ID;
        inStream >> currentEmployee.firstName;
        inStream >> currentEmployee.lastName;
        inStream >> currentEmployee.salary;
        lastNameSort(allEmployees);
    }
    print(allEmployees);

    int total = totalPayroll(allEmployees);
    cout << "Total Payroll: " << "$" << std::setprecision(2) << total << endl;

    inStream.close(); // close the file
}

void print (const vector <Employee> allEmployees) { // print function
    int size = allEmployees.size(); // size to use for vector
    cout << endl << "Sorted by last name." << endl;
    cout << "ID:" << "\t\t" << "Name:" << "\t\t\t" << "Salary:" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << allEmployees[i].ID << "\t\t";
        cout << allEmployees[i].firstName << " ";
        cout << allEmployees[i].lastName;

        size_t spacingFix = allEmployees[i].firstName.length() + allEmployees[i].lastName.length();
        cout << setw(24 - spacingFix);
        cout << std::fixed << std::setprecision(2) << "$" << allEmployees[i].salary << endl;
        cout << endl;
    }
}

void lastNameSort (vector <Employee> &allEmployees) { // sort last name function
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

int totalPayroll (const vector <Employee> allEmployees) {
    int size = allEmployees.size(); // find size to use in loop
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + allEmployees[i].salary;
    }
    return sum;
}


