#include <iostream>
#include "professor.h"
#include "course.h"
#include <vector>
#include <algorithm>
using namespace std;

class AlgorithmsSet
{
public:
    static vector<Professor> orderedProfessors;
    static vector<Course> orderedCourses;
    static int NoOfCoursesAssignedInAlgo1;
    static vector<Professor> assignedProfessorsWithCourses;

    static void initiateAlgorithms(vector<Professor> professors, vector<Course> courses);
    static void algorithm1(vector<Professor> professors, vector<Course> courses);
    static void printProfessors(vector<Professor> professors);
    static void printCourses(vector<Course> courses);
};
