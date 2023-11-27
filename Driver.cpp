#include <iostream>
#include "course.h"
#include "professor.h"
#include "algorithmsSet.h"
#include <vector>
using namespace std;

void showCourses(Course UGCDCcourses[], Course UGELECTcourses[], Course HDCDCcourses[], Course HDELECTcourses[])
{
    // cout << 1;
    cout << "First Degree CDC's:" << endl;
    for (int i = 0; i < Course::totalUGCDCCourses; i++)
    {
        UGCDCcourses[i].showCourse();
    }
    cout << "First Degree Electives:" << endl;
    for (int i = 0; i < Course::totalUGElectCourses; i++)
    {
        UGELECTcourses[i].showCourse();
    }
    cout << "Higher Degree CDC's:" << endl;
    for (int i = 0; i < Course::totalHDCDCCourses; i++)
    {
        HDCDCcourses[i].showCourse();
    }
    cout << "Higher Degree Electives:" << endl;
    for (int i = 0; i < Course::totalHDElectCourses; i++)
    {
        HDELECTcourses[i].showCourse();
    }
}

// void showProfessors(Professor professors[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         professors[i].getDetails();
//     }
// }
void showProfessors(vector<Professor> professors)
{
    for (int i = 0; i < professors.size(); i++)
    {
        professors[i].getDetails();
    }
}

void assigningUGCDCcourses(Course courses[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Professor::UGCDCallCourse[i] = courses[i];
        Course::totalUGCDCCourses++;
    }
}
void assigningUGELECTcourses(Course courses[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Professor::UGELECTallCourse[i] = courses[i];
        Course::totalUGElectCourses++;
    }
}
void assigningHDCDCcourses(Course courses[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Professor::HDCDCallCourse[i] = courses[i];
        Course::totalHDCDCCourses++;
    }
}
void assigningHDELECTcourses(Course courses[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Professor::HDELECTallCourse[i] = courses[i];
        Course::totalHDElectCourses++;
    }
}

int main()
{

      Course UGCDCcourses[] = {Course("UGCDC1", 1), Course("UGCDC2", 1), Course("UGCDC3", 1), Course("UGCDC4", 1)};
    Course UGELECTcourses[] = {Course("UGELECT1", 2), Course("UGELECT2", 2), Course("UGELECT3", 2), Course("UGELECT4", 2)};
    Course HDCDCcourses[] = {Course("HDCDC1", 3), Course("HDCDC2", 3), Course("HDCDC3", 3), Course("HDCDC4", 3)};
    Course HDELECTcourses[] = {Course("HDELECT1", 4), Course("HDELECT2", 4), Course("HDELECT3", 4), Course("HDELECT4", 4)};

    assigningUGCDCcourses(UGCDCcourses, sizeof(UGCDCcourses) / sizeof(UGCDCcourses[0]));
    assigningUGELECTcourses(UGELECTcourses, sizeof(UGELECTcourses) / sizeof(UGELECTcourses[0]));
    assigningHDCDCcourses(HDCDCcourses, sizeof(HDCDCcourses) / sizeof(HDCDCcourses[0]));
    assigningHDELECTcourses(HDELECTcourses, sizeof(HDELECTcourses) / sizeof(HDELECTcourses[0]));

    // Professor professors[] = {
    //     Professor("Prof1", {3, 1, 2}, {2, 0, 1}, {2, 3, 0}, {3, 1, 2}, 1.5),
    //     Professor("Prof2", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 0.5),
    //     Professor("Prof3", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    //     Professor("Prof4", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    //     Professor("Prof5", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1}, 0.5),
    //     Professor("Prof6", {0, 1, 2}, {2, 3, 1}, {3, 1, 2}, {1, 2, 3}, 1.5),
    //     Professor("Prof7", {1, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1.5),
    //     Professor("Prof8", {0, 1, 3}, {2, 3, 0}, {2, 3, 0}, {1, 2, 3}, 1),
    //     Professor("Prof9", {1, 2, 3}, {1, 2, 3}, {3, 2, 0}, {3, 0, 1}, 1)};
    vector<Professor> professors{
        Professor("Prof1", {3, 1, 2}, {2, 0, 1}, {2, 3, 0}, {3, 1, 2}, 1.5),
        Professor("Prof2", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 0.5),
        Professor("Prof3", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
        Professor("Prof4", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
        Professor("Prof5", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1}, 0.5),
        Professor("Prof6", {0, 1, 2}, {2, 3, 1}, {3, 1, 2}, {1, 2, 3}, 1.5),
        Professor("Prof7", {1, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1.5),
        Professor("Prof8", {0, 1, 3}, {2, 3, 0}, {2, 3, 0}, {1, 2, 3}, 1),
        Professor("Prof9", {1, 2, 3}, {1, 2, 3}, {3, 2, 0}, {3, 0, 1}, 1)};

    // showProfessors(professors, sizeof(professors) / sizeof(professors[0]));
    showProfessors(professors);
    showCourses(Professor::UGCDCallCourse, Professor::UGELECTallCourse, Professor::HDCDCallCourse, Professor::HDELECTallCourse);

    // AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors, professors + sizeof(professors) / sizeof(professors[0])),
    //                                   vector<Course>(Professor::UGCDCallCourse, Professor::UGCDCallCourse + Course::totalUGCDCCourses),
    //                                   vector<Course>(Professor::UGELECTallCourse, Professor::UGELECTallCourse + Course::totalUGElectCourses),
    //                                   vector<Course>(Professor::HDCDCallCourse, Professor::HDCDCallCourse + Course::totalHDCDCCourses),
    //                                   vector<Course>(Professor::HDELECTallCourse, Professor::HDELECTallCourse + Course::totalHDElectCourses));
    AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors),
                                      vector<Course>(Professor::UGCDCallCourse, Professor::UGCDCallCourse + Course::totalUGCDCCourses),
                                      vector<Course>(Professor::UGELECTallCourse, Professor::UGELECTallCourse + Course::totalUGElectCourses),
                                      vector<Course>(Professor::HDCDCallCourse, Professor::HDCDCallCourse + Course::totalHDCDCCourses),
                                      vector<Course>(Professor::HDELECTallCourse, Professor::HDELECTallCourse + Course::totalHDElectCourses));
    return 0;
}

// Pass vector by reference,create difference course for each category