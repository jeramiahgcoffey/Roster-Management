//
//  roster.h
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#ifndef roster_h
#define roster_h

#include "student.h"

class Roster {
private:
    // Data Members
    int head_count;
    int roster_max_size;
    Student** class_roster_array; //Requirement E.1
    
public:
    // Constructor/Destructor
    Roster(const string studentData[] = nullptr, int head_count = -1, int roster_max_size = 0);
    ~Roster();
    
    // Public methods    // Requirements E.3.a-f
    void add(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course_1, int days_in_course_2, int days_in_course_3, DegreeProgram degree_program);

    void remove(string student_id);

    void printAll();

    void printAverageDaysInCourse(string);  //that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

    void printInvalidEmails(); //that verifies student email addresses and displays all invalid email addresses to the user.
        //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    
    void printByDegreeProgram(DegreeProgram); //that prints out student information for a degree program specified by an enumerated type.
};

#endif /* roster_h */
