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
    static vector<Course> UGCDCorderedCourses;
    static vector<Course> UGELECTorderedCourses;
    static vector<Course> HDCDCorderedCourses;
    static vector<Course> HDELECTorderedCourses;
    static vector<Course> OrderedCDCCourses;
    static vector<Course> OrderedElectCourses;
    static int NoOfCoursesAssignedInAlgo1;
    static vector<Professor> assignedProfessorsWithCourses;

    static void initiateAlgorithms(vector<Professor> professors, vector<Course> UGCDCCourses, vector<Course> UGELECTCourses, vector<Course> HDCDCCourses, vector<Course> HDELECTCourses);
    static void algorithm1(vector<Professor> OrderedProfessors, vector<Course> CDCCourses, vector<Course> ElectCourses, int noOfOutputs);

    static void printProfessors(vector<Professor> professors);
    static void calcPopularityOfProfOnCDCs(vector<Professor> &professors);
    static void calcPopularityOfProfOnElectives(vector<Professor> &professors);
    static void printCourses();
};
