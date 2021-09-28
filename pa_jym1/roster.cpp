//
//  roster.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "roster.h"
#include "student.h"

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
    // IMPLEMENT LATER //
}

// Implementation of public methods

// Requirement E.3.a
// sets the instance variables from part D1 and updates the roster.
void Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course_1, int days_in_course_2, int days_in_course_3, DegreeProgram degree_program) {
    // sets the instance variables from part D1 and updates the roster.
    int days_in_course[] {days_in_course_1, days_in_course_2, days_in_course_3};
    class_roster_array[head_count] = new Student(student_id, first_name, last_name, email_address, age, days_in_course, degree_program);
    head_count++;
    std::cout << first_name << " " << last_name << " was added to the roster." << std::endl;
}
