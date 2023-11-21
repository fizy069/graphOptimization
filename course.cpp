
#include "course.h"
Course::Course()
{
}
int Course::totalCourses = 0;
int Course::totalUGCDCCourses = 0;
int Course::totalUGElectCourses = 0;
int Course::totalHDCDCCourses = 0;
int Course::totalHDElectCourses = 0;
Course::Course(string courseName)
{
    name = courseName;
    creditsAvailableInCourse = 1;
    popular = 0;
    totalCourses++;
}

void Course::showCourse()
{
    cout << "Name: " << name << ", Popularity: " << popular << endl;
}
