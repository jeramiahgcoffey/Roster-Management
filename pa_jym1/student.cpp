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

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

// Implementation of constructor    // Requirement D.2.d
Student::Student(string student_id, string first_name, string last_name, string email_address, int age, int days_remaining_in_each_course[], DegreeProgram degree_program)
    : student_id{student_id}, first_name{first_name}, last_name{last_name}, email_address{email_address}, age{age}, days_remaining_in_each_course{new int[DAYS_ARR_SIZE]}, degree_program{degree_program} {
        for (size_t i = 0; i < DAYS_ARR_SIZE; i++) this->days_remaining_in_each_course[i] = days_remaining_in_each_course[i];
}

// Implementation of default constructor
Student::Student()
: student_id{""}, first_name{""}, last_name{""}, email_address{""}, age{-1}, days_remaining_in_each_course{new int[DAYS_ARR_SIZE]}, degree_program{UNDECIDED} {
    for (size_t i = 0; i < DAYS_ARR_SIZE; i++) days_remaining_in_each_course[i] = 0;
}

// Implementation of destructor
Student::~Student() {
    if (days_remaining_in_each_course != nullptr) {
        delete [] days_remaining_in_each_course;
        days_remaining_in_each_course = nullptr;
    }
}

// Implementation of getters    // Reqirement D.2.a
string Student::get_student_id() const {
    return student_id;
}

string Student::get_first_name() const {
    return first_name;
}

string Student::get_last_name() const {
    return last_name;
}

string Student::get_email_address() const {
    return email_address;
}

int Student::get_age() const {
    return age;
}

int* Student::get_days_remaining() const {
    return days_remaining_in_each_course;
}

DegreeProgram Student::get_degree_program() const {
    return degree_program;
}

//Implementation of setters   // Reqirement D.2.b
void Student::set_student_id(string id_val) {
    student_id = id_val;
}

void Student::set_first_name(string first_name_val) {
    first_name = first_name_val;
}

void Student::set_last_name(string last_name_val) {
    last_name = last_name_val;
}

void Student::set_email_address(string email_val) {
    email_address = email_val;
}

void Student::set_age(int age_val) {
    age = age_val;
}

void Student::set_days_remaining(int days_remaining[DAYS_ARR_SIZE]) {
    for (size_t i = 0; i < DAYS_ARR_SIZE; i++) days_remaining_in_each_course[i] = days_remaining[i];
}

void Student::set_degree_program(DegreeProgram program_val) {
    degree_program = program_val;
}

// Print student data    // Requirement D.2.e
void Student::print() const {
    cout << left << setw(5) << student_id;
    cout << left << setw(10) << first_name;
    cout << left << setw(10) << last_name;
    cout << left << setw(25) << email_address;
    cout << left << setw(10) << age;
    cout << left << setw(5) << days_remaining_in_each_course[0];
    cout << left << setw(5) << days_remaining_in_each_course[1];
    cout << left << setw(5) << days_remaining_in_each_course[2];
    cout << left << setw(10) << DEGREE_PROGRAM_STRINGS[get_degree_program()];
    cout << endl;
}

