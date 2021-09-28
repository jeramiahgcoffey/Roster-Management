//
//  roster.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

#include "roster.h"
#include "student.h"
#include "degree.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::stoi;

// Implementation of Constructor
// Requirement E.1
Roster::Roster(const string studentData[], int headCount, int rosterMaxSize) : classRosterArray{new Student * [rosterMaxSize]}, headCount{headCount} {
    for (size_t i = 0; i < headCount; i++) { // Loops through every student in studentData array
        // Requirement E.2.a
        // Add each attribute of a specific student to a vector
        std::vector <string> currentStudentData;
        string attributeToAdd;
        std::istringstream inSS(studentData[i]);
        while(std::getline(inSS, attributeToAdd, ',')) { // Loop ends at new line char, which is the end of a specific students data
            currentStudentData.push_back(attributeToAdd);
        }
        
        // Convert string to intergers where appropriate
        int age {stoi(currentStudentData[4])};
        int courseDaysRemaining[3] {stoi(currentStudentData[5]), stoi(currentStudentData[6]), stoi(currentStudentData[7])};
        
        // Convert Degree Plan to defined enum type
        DegreeProgram degreeProgram;
        if (currentStudentData[8] == "SECURITY") degreeProgram = SECURITY;
        else if (currentStudentData[8] == "NETWORK") degreeProgram = NETWORK;
        else if (currentStudentData[8] == "SOFTWARE") degreeProgram = SOFTWARE;
        else degreeProgram = UNDECIDED;
                
        // Create other attribute variables
        string id {currentStudentData[0]};
        string firstName {currentStudentData[1]};
        string lastName {currentStudentData[2]};
        string email {currentStudentData[3]};
        
        // Requirement E.2.b
        // Create Student obj from each student in studentData arr and add to classRosterArray
        classRosterArray[i] = new Student(id, firstName, lastName, email, age, courseDaysRemaining, degreeProgram);
        
    }
    cout << "\nRoster Constructor Called.." << endl;
}

// Implementation of destructor
Roster::~Roster(){
    for (size_t i = 0; i < headCount; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    delete[] classRosterArray;
    classRosterArray = nullptr;
    cout << "\nRoster Destructor Called.." << endl;
}

// Implementation of public methods

int Roster::getHeadCount() {
    return headCount;
}

Student** Roster::getRosterArray() {
    return classRosterArray;
}

// Requirement E.3.a
// sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // sets the instance variables from part D1 and updates the roster.
    int daysInCourse[] {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[headCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    headCount++;
    cout << firstName << " " << lastName << " was added to the roster." << endl;
}

// Requirement E.3.b
// removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {
    bool studentFound {false};
    size_t i {0};
    while (i < headCount && !studentFound) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            studentFound = true;
            size_t j {i};
            while (j < headCount){
                classRosterArray[j] = classRosterArray[j + 1];
                j++;
            }
        }
        i++;
    }
    if (studentFound) {
        headCount--;
        cout << "\nStudent " << studentID << " was successfully removed." << endl;
    } else {
        cout << "\nError: Student " << studentID << " was not found." << endl;
    }
}

// Requirement E.3.c
// prints a complete tab-separated list of student data in the provided format
void Roster::printAll() {
    cout << "\nPrinting roster...\n" << endl;
    cout << left << setw(5) << "ID";
    cout << left << setw(13) << "First";
    cout << left << setw(13) << "Last";
    cout << left << setw(25) << "Email Address";
    cout << left << setw(10) << "Age";
    cout << left << setw(24) << "Course Days Remaining";
    cout << left << setw(15) << "Degree Program" << endl;
    cout << setfill('-') << setw(105) << "-" << endl << setfill(' ');
    for (size_t i = 0; i < headCount; i++) {
        classRosterArray[i]->print();
    }
    cout << endl;

}

// Requirement E.3.d
// prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
    for (size_t i = 0; i < headCount; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* courseDaysRemaining = classRosterArray[i]->getDaysRemaining();
            double average {static_cast<double>((courseDaysRemaining[0] + courseDaysRemaining[1] + courseDaysRemaining[2]) / 3)};
            cout << studentID << ": " << classRosterArray[i]->getFirstName() << endl;
            cout << "Average course days remaining: " << average << endl;
            cout << endl;
        }
    }
}

// Requirement 5.3.e
// verifies student email addresses and displays all invalid email addresses to the user.
    //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
    cout << left << setw(13) << "Student ID";
    cout << left << setw(25) << "Email Address" << endl;
    cout << setfill('-') << setw(40) << "-" << endl << setfill(' ');
    for (size_t i = 0; i < headCount; i++) {
        string email {classRosterArray[i]->getEmailAddress()};
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << classRosterArray[i]->getStudentID() << left << setw(13) << ": " << email << endl;
        }
    }
    cout << endl;
}

// Requirement 5.3.f
// prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "\nPrinting all " << DEGREE_PROGRAM_STRINGS[degreeProgram] << " student information...\n" << endl;
    cout << left << setw(5) << "ID";
    cout << left << setw(13) << "First";
    cout << left << setw(13) << "Last";
    cout << left << setw(25) << "Email Address";
    cout << left << setw(10) << "Age";
    cout << left << setw(24) << "Course Days Remaining";
    cout << left << setw(15) << "Degree Program" << endl;
    cout << setfill('-') << setw(105) << "-" << endl << setfill(' ');
    for (size_t i = 0; i < headCount; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
