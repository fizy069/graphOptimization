
#include "professor.h"

Course Professor::allCourse[MAX_COURSES];
Professor::Professor(string nameStr, vector<int> selectedCourses, double credits)
{
    name = nameStr;
    creditsAvailable = credits;
    popular = 0;
    optedCourses = selectedCourses;
    for (int i = 0; i < optedCourses.size(); i++)
    {

        // allCourse[optedCourses[i]].popular++; // For algo,use below code
        allCourse[optedCourses[i]].popular += (Course::totalCourses - i);
    }
}

void Professor::getDetails()
{
    cout << name << endl;
    for (int i = 0; i < optedCourses.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << Professor::allCourse[optedCourses[i]].name << endl; // Show courses chould be show name as it should show the prof later
    }
}
