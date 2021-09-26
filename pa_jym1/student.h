//
//  student.h
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#ifndef student_h
#define student_h
#include "degree.h"

#include <string>


using std::string;

class Student {
    
private: // Requirement D.1 & D.2.c
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int days_remaining_in_each_course[3];
    DegreeProgram degree_program;
    
public:
    
    // Contructor declaration   // Requirement D.2.d
    Student(string student_id, string first_name, string last_name, string email_address, int age, int days_remaining_in_each_course[], DegreeProgram degree_program);
    
    // Default Contructor declaration
    Student();
    
    
    // Getter declarations  // Reqirement D.2.a
    string get_student_id();
    string get_first_name();
    string get_last_name();
    string get_email_address();
    int get_age();
    int* get_days_remaining();
    DegreeProgram get_degree_program();
    
    // Setter declarations  // Reqirement D.2.b
    void set_student_id(string id_val);
    void set_first_name(string first_name_val);
    void set_last_name(string last_name_val);
    void set_email_address(string email_val);
    void set_age(int age_val);
//    void set_days_remaining();
//    void set_degree_program();
    
};

#endif /* student_h */