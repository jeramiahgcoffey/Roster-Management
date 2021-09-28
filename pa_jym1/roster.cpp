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

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::stoi;

// Implementation of Constructor
// Requirement E.1
Roster::Roster(const string student_data[], int head_count, int roster_max_size) : class_roster_array{new Student * [roster_max_size]}, head_count{head_count} {
    for (size_t i = 0; i < head_count; i++) { // Loops through every student in student_data array
        // Requirement E.2.a
        // Add each attribute of a specific student to a vector
        std::vector <string> current_student_data;
        string attribute_to_add;
        std::istringstream in_ss(student_data[i]);
        while(std::getline(in_ss, attribute_to_add, ',')) { // Loop ends at new line char, which is the end of a specific students data
            current_student_data.push_back(attribute_to_add);
        }
        
        // Convert string to intergers where appropriate
        int age {stoi(current_student_data[4])};
        int course_days_remaining[3] {stoi(current_student_data[5]), stoi(current_student_data[6]), stoi(current_student_data[7])};
        
        // Convert Degree Plan to defined enum type
        DegreeProgram degree_program;
        if (current_student_data[8] == "SECURITY") degree_program = SECURITY;
        else if (current_student_data[8] == "NETWORK") degree_program = NETWORK;
        else if (current_student_data[8] == "SOFTWARE") degree_program = SOFTWARE;
        else degree_program = UNDECIDED;
                
        // Create other attribute variables
        string id {current_student_data[0]};
        string first_name {current_student_data[1]};
        string last_name {current_student_data[2]};
        string email {current_student_data[3]};
        
        // Requirement E.2.b
        // Create Student obj from each student in student_data arr and add to classRosterArray
        class_roster_array[i] = new Student(id, first_name, last_name, email, age, course_days_remaining, degree_program);
        
    }
}

// Implementation of destructor
Roster::~Roster(){
    delete[] class_roster_array;
    class_roster_array = nullptr;
}

// Implementation of public methods

// Requirement E.3.a
// sets the instance variables from part D1 and updates the roster.
void Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course_1, int days_in_course_2, int days_in_course_3, DegreeProgram degree_program) {
    // sets the instance variables from part D1 and updates the roster.
    int days_in_course[] {days_in_course_1, days_in_course_2, days_in_course_3};
    class_roster_array[head_count] = new Student(student_id, first_name, last_name, email_address, age, days_in_course, degree_program);
    head_count++;
    cout << first_name << " " << last_name << " was added to the roster." << endl;
}

// Requirement E.3.b
// removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string student_id) {
    bool student_found {false};
    size_t i {0};
    while (i < head_count && !student_found) {
        if (class_roster_array[i]->get_student_id() == student_id) {
            student_found = true;
            size_t j {i};
            while (j < head_count){
                class_roster_array[j] = class_roster_array[j + 1];
                j++;
            }
        }
        i++;
    }
    if (student_found) {
        head_count--; // Damn bug took forever to find
        cout << "Student " << student_id << " was successfully removed." << endl;
    } else {
        cout << "Error: Student " << student_id << " was not found." << endl;
    }
}

// Requirement E.3.c
// prints a complete tab-separated list of student data in the provided format
void Roster::printAll() {
    cout << "\nPrinting roster...\n" << endl;
    cout << setfill('-') << setw(105) << "-" << endl << setfill(' ');
    cout << left << setw(5) << "ID";
    cout << left << setw(13) << "First";
    cout << left << setw(13) << "Last";
    cout << left << setw(25) << "Email Address";
    cout << left << setw(10) << "Age";
    cout << left << setw(24) << "Course Days Remaining";
    cout << left << setw(15) << "Degree Program" << endl;
    for (size_t i = 0; i < head_count; i++) {
        class_roster_array[i]->print();
    }
    cout << setfill('-') << setw(105) << "-" << endl << setfill(' ');
}

// Requirement E.3.d
// prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string student_id) {
    for (size_t i = 0; i < head_count; i++) {
        if (class_roster_array[i]->get_student_id() == student_id) {
            int* course_days_remaining = class_roster_array[i]->get_days_remaining();
            double average {static_cast<double>((course_days_remaining[0] + course_days_remaining[1] + course_days_remaining[2]) / 3)};
            cout << "\n" << student_id << ": " << class_roster_array[i]->get_first_name() << endl;
            cout << "Average course days remaining: " << average << endl;
        }
    }
}

