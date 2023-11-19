#include <iostream>
#include "professor.h"
#include "course.h"
#include <vector>
using namespace std;
// Create Algorithm class with all algorithm designed in it
// In contructor calculates popular of prof
void algorithm1(vector<Professor> professors)
{
    for (int i = 0; i < professors.size(); i++) // calculates the popularity of professors
    {
        for (int j = 0; j < professors[i].optedCourses.size(); j++)
        {

            professors[i].popular += professors[i].Professor::allCourse[professors[i].optedCourses[i]].popular;
        }
    }
}