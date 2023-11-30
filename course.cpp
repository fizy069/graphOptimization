
#include "course.h"
Course::Course()
{
}

int Course::totalUGCDCCourses = 0;
int Course::totalUGElectCourses = 0;
int Course::totalHDCDCCourses = 0;
int Course::totalHDElectCourses = 0;
Course::Course(string courseName, int coursetype)
{
    name = courseName;
    courseType = coursetype;
    creditsAvailableInCourse = 1;
    popular = 0;
}

void Course::showCourse()
{
    cout << "Name: " << name << ", Popularity: " << popular << endl;
    // cout << "Name: " << name << ", Course Type: " << courseType << ",Popularity: " << popular << endl;
}
