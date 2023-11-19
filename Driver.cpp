#include <iostream>
#include "course.h"
#include "professor.h"
#include "algorithmsSet.h"
#include <vector>
using namespace std;

// vector<Course> addCourses(Course courseList[], int n)
// {
//     vector<Course> courses;
//     for (int i = 0; i < n; i++)
//     {
//         courses.push_back(courseList[i]);
//     }
//     return courses;
// }

void showCourses(Course courses[], int n)
{
    // cout << 1;
    for (int i = 0; i < n; i++)
    {
        courses[i].showCourse();
    }
}

void showProfessors(Professor professors[], int n)
{
    for (int i = 0; i < n; i++)
    {
        professors[i].getDetails();
    }
}

void assigningCourses(Course courses[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Professor::allCourse[i] = courses[i];
    }
}

int main()
{
    // cout << 1;
    // Professor::allCourse.assign(begin(courses), end(courses));

    Course courses[] = {Course("Math"), Course("Science"), Course("history"), Course("Geo")};

    assigningCourses(courses, sizeof(courses) / sizeof(courses[0]));

    Professor professors[] = {
        Professor("Michael", {3, 1, 2}, 1),
        Professor("Savio", {2, 0, 1}, 1),
        Professor("Lewis", {2, 3, 0}, 1)};

    // showCourses(courses, sizeof(courses) / sizeof(courses[0]));
    showCourses(Professor::allCourse, sizeof(courses) / sizeof(courses[0]));
    showProfessors(professors, sizeof(professors) / sizeof(professors[0]));
    showCourses(Professor::allCourse, sizeof(courses) / sizeof(courses[0]));
    // showCourses(courses, sizeof(courses) / sizeof(courses[0]));

    AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors, professors + sizeof(professors) / sizeof(professors[0])),
                                      vector<Course>(Professor::allCourse, Professor::allCourse + Course::totalCourses));
    return 0;
}

// Pass vector by reference,create difference course for each category