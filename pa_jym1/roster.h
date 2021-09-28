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
    /*----- CONSTRUCTOR DECLERATION -----*/
    Roster(const string studentData[] = nullptr, int headCount = -1, int rosterMaxSize = 0);
    
    /*----- DESTRUCTOR DECLERATION -----*/
    ~Roster();
    
    /*----- ACCESSOR DECLERATIONS -----*/
    int getHeadCount();
    
    Student** getRosterArray();
    
    /*----- PUBLIC METHOD DECLERATIONS -----*/    // Requirements E.3.a-f
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
private:
    
    /*----- DATA MEMBERS -----*/
    int headCount;
    int rosterMaxSize;
    Student** classRosterArray; //Requirement E.1
    
};

#endif /* roster_h */
