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

void showProfessors(Professor professors[], int n)
{
    for (int i = 0; i < n; i++)
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

    // Course courses[] = {Course("UGCDC1"), Course("UGCDC2"), Course("UGCDC3"),
    //                     Course("UGCDC4"), Course("UGELECT1"), Course("UGELECT2"), Course("UGELECT3"),
    //                     Course("UGELECT4"), Course("HDCDC1"), Course("HDCDC2"), Course("HDCDC3"),
    //                     Course("HDCDC4"), Course("HDELECT1"), Course("HDELECT2"), Course("HDELECT3"),
    //                     Course("HDELECT4")};
    Course UGCDCcourses[] = {Course("UGCDC1"), Course("UGCDC2"), Course("UGCDC3"), Course("UGCDC4")};
    Course UGELECTcourses[] = {Course("UGELECT1"), Course("UGELECT2"), Course("UGELECT3"), Course("UGELECT4")};
    Course HDCDCcourses[] = {Course("HDCDC1"), Course("HDCDC2"), Course("HDCDC3"), Course("HDCDC4")};
    Course HDELECTcourses[] = {Course("HDELECT1"), Course("HDELECT2"), Course("HDELECT3"), Course("HDELECT4")};

    assigningUGCDCcourses(UGCDCcourses, sizeof(UGCDCcourses) / sizeof(UGCDCcourses[0]));
    assigningUGELECTcourses(UGELECTcourses, sizeof(UGELECTcourses) / sizeof(UGELECTcourses[0]));
    assigningHDCDCcourses(HDCDCcourses, sizeof(HDCDCcourses) / sizeof(HDCDCcourses[0]));
    assigningHDELECTcourses(HDELECTcourses, sizeof(HDELECTcourses) / sizeof(HDELECTcourses[0]));

    Professor professors[] = {
        Professor("Michael", {3, 1, 2}, {2, 0, 1}, {2, 3, 0}, {3, 1, 2}, 1),
        Professor("Mahir", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1),
        Professor("Jainam", {2, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1)};

    showProfessors(professors, sizeof(professors) / sizeof(professors[0]));
    showCourses(Professor::UGCDCallCourse, Professor::UGELECTallCourse, Professor::HDCDCallCourse, Professor::HDELECTallCourse);

    AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors, professors + sizeof(professors) / sizeof(professors[0])),
                                      vector<Course>(UGCDCcourses, UGCDCcourses + sizeof(UGCDCcourses) / sizeof(UGCDCcourses[0])),
                                      vector<Course>(UGELECTcourses, UGELECTcourses + sizeof(UGELECTcourses) / sizeof(UGELECTcourses[0])),
                                      vector<Course>(HDCDCcourses, HDCDCcourses + sizeof(HDCDCcourses) / sizeof(HDCDCcourses[0])),
                                      vector<Course>(HDELECTcourses, HDELECTcourses + sizeof(HDELECTcourses) / sizeof(HDELECTcourses[0])));
    return 0;
}

// Pass vector by reference,create difference course for each category