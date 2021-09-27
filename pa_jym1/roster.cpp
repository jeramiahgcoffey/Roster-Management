//
//  roster.cpp
//  pa_jym1
//
//  Created by Jeramiah Coffey on 9/8/21.
//

#include "roster.h"
#include "student.h"

// Implementation of Constructors
Roster::Roster() : head_count{0}, classRosterArray{nullptr} {
}

Roster::Roster(int head_count) : head_count{head_count}, classRosterArray{new Student * [head_count]} {
}

// Implementation of destructor
Roster::~Roster(){
    // IMPLEMENT LATER //
}
