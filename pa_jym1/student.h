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
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* daysRemainingInEachCourse;
    DegreeProgram degreeProgram;
    
public:
    
    static const int DAYS_ARR_SIZE {3};
    
    // Contructor declaration   // Requirement D.2.d
    Student(string studentID = "", string firstName = "", string lastName = "", string emailAddress = "", int age = -1, int daysRemainingInEachCourse[] = new int[]{0,0,0}, DegreeProgram degreeProgram = UNDECIDED);
    
    // Destructor declaration
    ~Student();
    // Copy Contructor
    Student(const Student& objectToCopy) {
        std::cout << "Student Copy Constructor Called.." << std::endl;
    };
    // Copy Assignment Operator
//    Student& operator=(const Student& objectToCopy) {
//        std::cout << "Student Copy Assignment Operator Called.." << std::endl;
//    };
    
    // Getter declarations  // Reqirement D.2.a
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getDaysRemaining() const ;
    DegreeProgram getDegreeProgram() const;
    
    // Setter declarations  // Reqirement D.2.b
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setDaysRemaining(int[]);
    void setDegreeProgram(DegreeProgram);
    
    // Print specific student data    // Requirement D.2.e
    void print() const;
    
};

#endif /* student_h */
