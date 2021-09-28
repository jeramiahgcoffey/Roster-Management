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
    
    const string student_data[] { // Requirement A
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jeramiah,Coffey,jerrygcoffey@gmail.com,24,15,20,25,SOFTWARE" };
    
    Roster* classRoster = new Roster(student_data, 5, 20);
    
    classRoster->printAll();
    
    classRoster->printInvalidEmails();
    
    cout << "Printing Average Course Days Remaining:" << endl;
    cout << "----------------------------------------------------" << endl;
    for (size_t i = 0; i < classRoster->get_head_count(); i++) {
        string student_id {classRoster->get_roster_array()[i]->get_student_id()};
        classRoster->printAverageDaysInCourse(student_id);
    }
    
    classRoster->printByDegreeProgram(SOFTWARE);
    
    classRoster->remove("A3");
    
    classRoster->printAll();
    
    classRoster->remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    delete classRoster;
    
//    Tests
    
//    string jId {"123"};
//    string jFirst {"jeramiah"};
//    string jLast {"coffey"};
//    string jEmail {"jerrygcoffey@gmail.com"};
//    int jAge {24};
//    int jDays_remaining[] {1, 2, 3};
//    int new_remaining[] {4, 5, 6};
//    DegreeProgram jDegree {SOFTWARE};
//
//    Student jeramiahCoffey = Student(jId, jFirst, jLast, jEmail, jAge, jDays_remaining, jDegree);
//    std::cout << *jeramiahCoffey.get_days_remaining() << std::endl;
//    jeramiahCoffey.print();
//    jeramiahCoffey.set_days_remaining(new_remaining);
//    jeramiahCoffey.print();
//    Student test;
//    test.print();
//    Roster my_roster(student_data, 5, 10);
//    my_roster.add("test", "jeramiah", "coffey", "gmail", 24, 1, 2, 3, UNDECIDED);
//    my_roster.printAll();
//    my_roster.remove("A3");
//    my_roster.printAll();
//    my_roster.add("test", "", "", "", 0, 0,0,0, UNDECIDED);
//    my_roster.printAll();
//    my_roster.add("test", "", "", "", 0, 0,0,0, UNDECIDED);
//    my_roster.printAll();
//    my_roster.add("test", "", "", "", 0, 0,0,0, UNDECIDED);
//    my_roster.printAll();
//    my_roster.add("test", "", "", "", 0, 0,0,0, UNDECIDED);
//    my_roster.printAll();
//    my_roster.remove("A5");
//    my_roster.printAll();
//    my_roster.remove("A3");
//    my_roster.printAverageDaysInCourse("A5");
//    my_roster.printInvalidEmails();
//    my_roster.printByDegreeProgram(SOFTWARE);

    return 0;
}
