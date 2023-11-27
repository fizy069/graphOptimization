#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course
{
public:
    string name;
    int courseType;
    int popular;
    double creditsAvailableInCourse;
    static int totalCourses;
    static int totalUGCDCCourses;
    static int totalUGElectCourses;
    static int totalHDCDCCourses;
    static int totalHDElectCourses;

    Course();
    Course(string courseName, int coursetype);
    void showCourse();
};
#endif