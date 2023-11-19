
#include "course.h"
Course::Course()
{
}
int Course::totalCourses = 0;
Course::Course(string courseName)
{
    name = courseName;
    priorityNo = 0; // Could be used for some algorithm
    creditsAvailableInCourse = 1;
    popular = 0;
    totalCourses++;
}

void Course::showCourse()
{
    cout << "Name: " << name << ", Popularity: " << popular << endl;
}
