#include <bits/stdc++.h>
#include "professor.h"
#include "course.h"

bool isValidAssignment(const Professor &professor, const string &course) {
    return (find(professor.optedCourses.begin(), professor.optedCourses.end(), course) != professor.optedCourses.end());
}

//backtracking function
bool assignCoursesBacktrack(vector<Professor> &professors, vector<string> &courses, int courseIndex) {
    if (courseIndex == courses.size()) {
        return true;
    }

    for (auto &professor : professors) {
        if (professor.creditsAvailable >= 0.5 && isValidAssignment(professor, courses[courseIndex])) {
            professor.creditsAvailable -= 0.5;

            // recursive assignemnt to next profs
            if (assignCoursesBacktrack(professors, courses, courseIndex + 1)) {
                return true;  
            }

            professor.creditsAvailable += 0.5;
        }
    }

    return false;
}