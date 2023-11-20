
#include "professor.h"

// Course Professor::allCourse[MAX_COURSES];
Course Professor::UGCDCallCourse[MAX_UGCDC_CCOURSES];
Course Professor::UGELECTallCourse[MAX_UGELECT_CCOURSES];
Course Professor::HDCDCallCourse[MAX_HDCDC_CCOURSES];
Course Professor::HDELECTallCourse[MAX_HDELECT_CCOURSES];
Professor::Professor(string nameStr, vector<int> selectUGCDC, vector<int> selectUGELECT, vector<int> selectHDCDC, vector<int> selectHDELECT, double credits)
{
    name = nameStr;
    creditsAvailable = credits;
    popular = 0;
    UGCDC = selectUGCDC;
    UGELECT = selectUGELECT;
    HDCDC = selectHDCDC;
    HDELECT = selectHDELECT;

    for (int i = 0; i < UGCDC.size(); i++)
    {

        UGCDCallCourse[UGCDC[i]].popular += (Course::totalUGCDCCourses - i);
    }
    for (int i = 0; i < UGELECT.size(); i++)
    {

        UGELECTallCourse[UGELECT[i]].popular += (Course::totalUGElectCourses - i);
    }
    for (int i = 0; i < HDCDC.size(); i++)
    {

        HDCDCallCourse[HDCDC[i]].popular += (Course::totalHDCDCCourses - i);
    }
    for (int i = 0; i < HDELECT.size(); i++)
    {

        HDELECTallCourse[HDELECT[i]].popular += (Course::totalHDElectCourses - i);
    }
}

void Professor::getDetails()
{
    cout << name << endl;
    cout << "\tFirst Degree CDC's" << endl;
    for (int i = 0; i < UGCDC.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << UGCDCallCourse[UGCDC[i]].name << endl; // Show courses chould be show name as it should show the prof later
    }
    cout << "\tFirst Degree Electives's" << endl;
    for (int i = 0; i < UGELECT.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << UGELECTallCourse[UGELECT[i]].name << endl; // Show courses chould be show name as it should show the prof later
    }
    cout << "\tHigher Degree CDC's" << endl;
    for (int i = 0; i < HDCDC.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << HDCDCallCourse[HDCDC[i]].name << endl; // Show courses chould be show name as it should show the prof later
    }
    cout << "\tHigher Degree Electives's" << endl;
    for (int i = 0; i < HDELECT.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << HDELECTallCourse[HDELECT[i]].name << endl; // Show courses chould be show name as it should show the prof later
    }
}
