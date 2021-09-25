//
//  student.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#include <stdio.h>
#include <string>

#include "student.h"

using std::string;

// Implementation of constructor
Student::Student(string student_id, string first_name, string last_name, string email_address, int age, int days_remaining_in_each_course[3], DegreeProgram degree_program)
: student_id{student_id}, first_name{first_name}, last_name{last_name}, email_address{email_address}, age{age}, days_remaining_in_each_course{days_remaining_in_each_course[3]}, degree_program{degree_program} {
}

// Implementation of getters
string Student::get_student_id() {
    return student_id;
}

string Student::get_first_name() {
    return first_name;
}

string Student::get_last_name() {
    return last_name;
}

string Student::get_email_address() {
    return email_address;
}

int Student::get_age() {
    return age;
}

int Student::get_days_remaining() {
    return *days_remaining_in_each_course;
}

DegreeProgram Student::get_degree_program() {
    return degree_program;
}

//Implementation of setters
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

//void Student::set_days_remaining(){}
//void Student::set_degree_program(){}
