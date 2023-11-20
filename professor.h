
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <vector>
#include "course.h"

#define MAX_UGCDC_CCOURSES 100
#define MAX_UGELECT_CCOURSES 100
#define MAX_HDCDC_CCOURSES 100
#define MAX_HDELECT_CCOURSES 100
using namespace std;

class Professor
{

public:
    string name;
    double creditsAvailable;
    vector<int> UGCDC;
    vector<int> UGELECT;
    vector<int> HDCDC;
    vector<int> HDELECT;

    int popular;
    // static Course allCourse[MAX_COURSES];
    static Course UGCDCallCourse[MAX_UGCDC_CCOURSES];
    static Course UGELECTallCourse[MAX_UGELECT_CCOURSES];
    static Course HDCDCallCourse[MAX_HDCDC_CCOURSES];
    static Course HDELECTallCourse[MAX_HDELECT_CCOURSES];
    vector<Course> assignedCourses;
    // static vector<Course> allCourse;

    void getDetails();
    Professor(string nameStr, vector<int> selectUGCDC, vector<int> selectUGELECT, vector<int> selectHDCDC, vector<int> selectHDELECT, double credits);
    // void setCourses(vector<int> selectedCourses);
};

#endif