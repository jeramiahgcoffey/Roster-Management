//
//  student.h
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#ifndef student_h
#define student_h

#include <string>
#include "degree.h"

using std::string;

class Student {
    
private: // Data Members   // Requirement D.1 & D.2.c
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int* days_remaining_in_each_course;
    DegreeProgram degree_program;
    
public:
    
    static const int DAYS_ARR_SIZE {3};
    
    // Contructor declaration   // Requirement D.2.d
    Student(string student_id = "", string first_name = "", string last_name = "", string email_address = "", int age = -1, int days_remaining_in_each_course[] = new int[]{0,0,0}, DegreeProgram degree_program = UNDECIDED);
    
    // Destructor declaration
    ~Student();
    // Copy Contructor
    Student(const Student& object_to_copy);
    // Copy Assignment Operator
    Student& operator=(const Student& object_to_copy);
    
    // Getter declarations  // Reqirement D.2.a
    string get_student_id() const;
    string get_first_name() const;
    string get_last_name() const;
    string get_email_address() const;
    int get_age() const;
    int* get_days_remaining() const ;
    DegreeProgram get_degree_program() const;
    
    // Setter declarations  // Reqirement D.2.b
    void set_student_id(string);
    void set_first_name(string);
    void set_last_name(string);
    void set_email_address(string);
    void set_age(int);
    void set_days_remaining(int[]);
    void set_degree_program(DegreeProgram);
    
    // Print specific student data    // Requirement D.2.e
    void print() const;
    
};

#endif /* student_h */
