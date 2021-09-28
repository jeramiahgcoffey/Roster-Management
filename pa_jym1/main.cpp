//
//  main.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//
#include <iostream>

#include "degree.h"
#include "roster.h"
#include "student.h"

using std::cout;
using std::endl;

int main() { // Requirement F
    cout << "----------------------------------------------------" << endl;
    cout << "\n Course Title: Scripting and Programming Applications" << endl;
    cout << "\n Language: C++" << endl;
    cout << "\n WGU ID: 006868510" << endl;
    cout << "\n Created By: Jeramiah Coffey" << endl;
    cout << "\n----------------------------------------------------" << endl;
    
    const string studentData[] { // Requirement A
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jeramiah,Coffey,jerrygcoffey@gmail.com,24,15,20,25,SOFTWARE" };
    
    Roster* classRoster = new Roster(studentData, 5, 20);
    
    classRoster->printAll();
    
    classRoster->printInvalidEmails();
    
    cout << "Printing Average Course Days Remaining..." << endl;
    cout << "----------------------------------------------------" << endl;
    for (size_t i = 0; i < classRoster->getHeadCount(); i++) {
        string studentID {classRoster->getRosterArray()[i]->getStudentID()};
        classRoster->printAverageDaysInCourse(studentID);
    }
    
    classRoster->printByDegreeProgram(SOFTWARE);
    
    classRoster->remove("A3");
    
    classRoster->printAll();
    
    classRoster->remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    delete classRoster;
    
    cout << endl;

    return 0;
}
