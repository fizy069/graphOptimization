
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <vector>
#include "course.h"

#define MAX_COURSES 100
using namespace std;

class Professor
{

public:
    string name;
    double creditsAvailable;
    vector<int> optedCourses;
    int popular;
    static Course allCourse[MAX_COURSES];
    vector<Course> assignedCourses;
    // static vector<Course> allCourse;

    void getDetails();
    Professor(string nameStr, vector<int> selectedCourses, double credits);
    // void setCourses(vector<int> selectedCourses);
};

#endif