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
    int headCount;
    int rosterMaxSize;
    Student** classRosterArray; //Requirement E.1
    
public:
    // Constructor/Destructor
    Roster(const string studentData[] = nullptr, int headCount = -1, int rosterMaxSize = 0);
    ~Roster();
    
    // Public methods    // Requirements E.3.a-f
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    int getHeadCount();
    
    Student** getRosterArray();

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif /* roster_h */
