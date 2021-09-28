//
//  student.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#include <string>
#include <iostream>
#include <iomanip>

#include "student.h"
#include "degree.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;

/*----- CONSTRUCTOR IMPLEMENTATION -----*/    // Requirement D.2.d
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemainingInEachCourse[], DegreeProgram degreeProgram)
    : studentID{studentID}, firstName{firstName}, lastName{lastName}, emailAddress{emailAddress}, age{age}, daysRemainingInEachCourse{new int[DAYS_ARR_SIZE]}, degreeProgram{degreeProgram}
{
        for (size_t i = 0; i < DAYS_ARR_SIZE; i++) this->daysRemainingInEachCourse[i] = daysRemainingInEachCourse[i];
        //cout << "\nStudent Constructor Called.." << endl;
}

/*----- DESTRUCTOR IMPLEMENTATION -----*/
Student::~Student() {
    if (daysRemainingInEachCourse != nullptr) {
        delete[] daysRemainingInEachCourse;
        daysRemainingInEachCourse = nullptr;
    }
    //cout << "\nStudent Destructor Called.." << endl;
}

/*----- ACCESSOR IMPLEMENTATIONS -----*/    // Reqirement D.2.a
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysRemaining() const {
    return daysRemainingInEachCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

/*----- MUTATOR IMPLEMENTATIONS -----*/   // Reqirement D.2.b
void Student::setStudentID(string idVal) {
    studentID = idVal;
}

void Student::setFirstName(string firstNameVal) {
    firstName = firstNameVal;
}

void Student::setLastName(string lastNameVal) {
    lastName = lastNameVal;
}

void Student::setEmailAddress(string emailVal) {
    emailAddress = emailVal;
}

void Student::setAge(int ageVal) {
    age = ageVal;
}

void Student::setDaysRemaining(int daysRemaining[DAYS_ARR_SIZE]) {
    for (size_t i = 0; i < DAYS_ARR_SIZE; i++) daysRemainingInEachCourse[i] = daysRemaining[i];
}

void Student::setDegreeProgram(DegreeProgram programVal) {
    degreeProgram = programVal;
}

/*----- PUBLIC METHOD IMPLEMENTATIONS -----*/
// Print student data    // Requirement D.2.e
void Student::print() const {
    cout << left << setw(5) << studentID;
    cout << left << setw(13) << firstName;
    cout << left << setw(13) << lastName;
    cout << left << setw(25) << emailAddress;
    cout << left << setw(10) << age;
    cout << left << setw(8) << daysRemainingInEachCourse[0];
    cout << left << setw(8) << daysRemainingInEachCourse[1];
    cout << left << setw(8) << daysRemainingInEachCourse[2];
    cout << left << setw(10) << DEGREE_PROGRAM_STRINGS[getDegreeProgram()] << endl;
}

