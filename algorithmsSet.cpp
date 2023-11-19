#include "algorithmsSet.h"

vector<Professor> AlgorithmsSet::orderedProfessors;
vector<Course> AlgorithmsSet::orderedCourses;
vector<Professor> AlgorithmsSet::assignedProfessorsWithCourses;
int AlgorithmsSet::NoOfCoursesAssignedInAlgo1;

void AlgorithmsSet::printProfessors(vector<Professor> professors)
{
    for (int i = 0; i < professors.size(); i++)
    {
        cout << i + 1 << ". " << professors[i].name << "\t" << professors[i].popular << endl;
    }
}

void AlgorithmsSet::printCourses(vector<Course> courses)
{
    for (int i = 0; i < courses.size(); i++)
    {
        courses[i].showCourse();
    }
}

void AlgorithmsSet::initiateAlgorithms(vector<Professor> professors, vector<Course> courses) // may face issues regd vectors
{
    for (int i = 0; i < professors.size(); i++) // calculates the popularity of professors
    {
        for (int j = 0; j < professors[i].optedCourses.size(); j++)
        {
            professors[i].popular += professors[i].allCourse[professors[i].optedCourses[j]].popular; // Professor:: can be used
        }
    }
    sort(professors.begin(), professors.end(), [](const Professor &a, const Professor &b)
         { return a.popular < b.popular; }); // Sorts Professors based on popularity in ascending order
    orderedProfessors = professors;

    sort(courses.begin(), courses.end(), [](const Course &c, const Course &d)
         { return c.popular < d.popular; }); // Sorts Courses based on popularity in ascending order
    orderedCourses = courses;

    printProfessors(orderedProfessors);
    printCourses(orderedCourses);
    algorithm1(orderedProfessors, orderedCourses);
}

void AlgorithmsSet::algorithm1(vector<Professor> professors, vector<Course> courses)
{

    for (int i = 0; i < courses.size(); i++)
    {

        bool assignedFullCourse = false;
        bool assignedHalfCourse = false;
        for (int coursePrefNo = 0; coursePrefNo < Course::totalCourses; coursePrefNo++) // can be optimised,can be done uptil prof with max course
        {

            for (int j = 0; j < professors.size(); j++)
            {

                if (professors[j].optedCourses.size() > coursePrefNo)
                {
                    cout << 1;

                    if (courses[i].name == professors[j].allCourse[professors[j].optedCourses[coursePrefNo]].name) // check if name is equal
                    {
                        cout << 0;
                        professors[j].assignedCourses.push_back(courses[i]);
                        professors[j].creditsAvailable -= 1; // deduct the credits of desired form(0.5/1).re-loop if 0.5
                        courses[i].creditsAvailableInCourse -= 1;
                        assignedHalfCourse = true; // coursePrefNo--

                        if (professors[j].creditsAvailable == 0) // when professors credits r 0 means assignment of prof is complete
                        {
                            cout << 2 << endl;
                            assignedProfessorsWithCourses.push_back(professors[j]);
                            professors.erase(professors.begin() + j);
                            printCourses(courses);
                            j--; // Change made
                                 // remove professor from list (j--)
                        }
                        if (courses[i].creditsAvailableInCourse == 0)
                        {
                            assignedFullCourse = true;
                            courses.erase(courses.begin() + i);
                            professors[j].optedCourses.erase(professors[j].optedCourses.begin() + j);
                            i--;
                            // remove course and course in prof list(i--)                 //Change made
                            break;
                        }
                    }
                }
            }
            if (assignedFullCourse)
            {
                break;
            }
            if (assignedHalfCourse)
            {
                coursePrefNo--;
            }
        }
    }

    for (int i = 0; i < assignedProfessorsWithCourses.size(); i++)
    {
        for (int j = 0; j < assignedProfessorsWithCourses[i].assignedCourses.size(); j++)
        {
            if (assignedProfessorsWithCourses[i].assignedCourses[j].creditsAvailableInCourse != 0)
            {
                assignedProfessorsWithCourses.erase(assignedProfessorsWithCourses.begin() + i);
            }
        }
    }

    for (int i = 0; i < assignedProfessorsWithCourses.size(); i++) // Prints the assigned profs with Courses
    {
        cout << i + 1 << ". " << assignedProfessorsWithCourses[i].name;
        for (int j = 0; j < assignedProfessorsWithCourses[i].assignedCourses.size(); j++)
        {
            cout << "\t" << j + 1 << ". " << assignedProfessorsWithCourses[i].assignedCourses[j].name << endl;
        }
    }
}

// checking to see if courses match of professor, use the allCourses[i]