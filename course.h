#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course
{
public:
    string name;
    int priorityNo;
    int popular;
    double creditsAvailableInCourse;
    static int totalCourses;

    Course();
    Course(string courseName);
    void showCourse();
};
#endif