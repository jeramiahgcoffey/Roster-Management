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
public:
    // Data Members
    int head_count;
    Student **classRosterArray; //Requirement E.1
    
    // Constructors/Destructor
    Roster();
    Roster(int head_count);
    ~Roster();
    
    // Public methods    // Requirements E.3.a-f
    void add(string, string, string, string, int, int, int, int, DegreeProgram);  //that sets the instance variables from part D1 and updates the roster.

    void remove(string);  //that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

    void printAll(); //that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

    void printAverageDaysInCourse(string);  //that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

    void printInvalidEmails(); //that verifies student email addresses and displays all invalid email addresses to the user.
        //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    
    void printByDegreeProgram(DegreeProgram); //that prints out student information for a degree program specified by an enumerated type.
};

#endif /* roster_h */
