#include "algorithmsSet.h"

vector<Professor> AlgorithmsSet::orderedProfessors;
vector<Course> AlgorithmsSet::UGCDCorderedCourses;
vector<Course> AlgorithmsSet::UGELECTorderedCourses;
vector<Course> AlgorithmsSet::HDCDCorderedCourses;
vector<Course> AlgorithmsSet::HDELECTorderedCourses;

vector<Course> AlgorithmsSet::OrderedCDCCourses;
vector<Course> AlgorithmsSet::OrderedElectCourses;
vector<Professor> AlgorithmsSet::assignedProfessorsWithCourses;

void AlgorithmsSet::printProfessors(vector<Professor> professors)
{
    for (int i = 0; i < professors.size(); i++)
    {
        cout << i + 1 << ". " << professors[i].name << "\t" << professors[i].popular << endl;
    }
    cout << "\n\n";
}

void AlgorithmsSet::printCourses()
{
    cout << "Ordered CDC Courses:\n";
    for (int i = 0; i < OrderedCDCCourses.size(); i++)
    {
        OrderedCDCCourses[i].showCourse();
    }
    cout << "\n\n";

    cout << "Ordered Elective Courses:\n";
    for (int i = 0; i < OrderedElectCourses.size(); i++)
    {
        OrderedElectCourses[i].showCourse();
    }
    cout << "\n\n";
}

void AlgorithmsSet::calcPopularityOfProfOnCDCs(vector<Professor> &professors)
{
    for (int i = 0; i < professors.size(); i++)
    {
        for (int j = 0; j < professors[i].UGCDC.size(); j++)
        {
            professors[i].popular += professors[i].UGCDCallCourse[professors[i].UGCDC[j]].popular; // Professor:: can be used
        }

        for (int j = 0; j < professors[i].HDCDC.size(); j++)
        {
            professors[i].popular += professors[i].HDCDCallCourse[professors[i].HDCDC[j]].popular;
        }
    }
}

void AlgorithmsSet::calcPopularityOfProfOnElectives(vector<Professor> &professors)
{
    for (int i = 0; i < professors.size(); i++)
    {
        professors[i].popular = 0;
        for (int j = 0; j < professors[i].UGELECT.size(); j++)
        {
            professors[i].popular += professors[i].UGELECTallCourse[professors[i].UGELECT[j]].popular;
        }

        for (int j = 0; j < professors[i].HDELECT.size(); j++)
        {
            professors[i].popular += professors[i].HDELECTallCourse[professors[i].HDELECT[j]].popular;
        }
    }
}

void AlgorithmsSet::initiateAlgorithms(vector<Professor> professors,
                                       vector<Course> UGCDCCourses, vector<Course> UGELECTCourses, vector<Course> HDCDCCourses,
                                       vector<Course> HDELECTCourses)
{

    calcPopularityOfProfOnCDCs(professors);
    sort(professors.begin(), professors.end(), [](const Professor &a, const Professor &b)
         { return a.popular < b.popular; }); // Sorts Professors based on popularity of CDCs in ascending order
    orderedProfessors = professors;

    vector<Course> CDCcourses;
    for (int i = 0; i < UGCDCCourses.size(); i++)
    {
        CDCcourses.push_back(UGCDCCourses[i]);
    }
    for (int i = 0; i < HDCDCCourses.size(); i++)
    {
        CDCcourses.push_back(HDCDCCourses[i]);
    }

    sort(CDCcourses.begin(), CDCcourses.end(), [](const Course &c, const Course &d)
         { return c.popular < d.popular; });
    OrderedCDCCourses = CDCcourses;

    vector<Course> ELECTcourses;
    for (int i = 0; i < UGELECTCourses.size(); i++)
    {
        ELECTcourses.push_back(UGELECTCourses[i]);
    }
    for (int i = 0; i < HDELECTCourses.size(); i++)
    {
        ELECTcourses.push_back(HDELECTCourses[i]);
    }

    sort(ELECTcourses.begin(), ELECTcourses.end(), [](const Course &c, const Course &d)
         { return c.popular < d.popular; });
    OrderedElectCourses = ELECTcourses;

    // printProfessors(orderedProfessors);
    // printCourses();
    algorithm1(orderedProfessors, OrderedCDCCourses, OrderedElectCourses, 0); //--------------------------

    vector<Professor> orderedProfessorsPermProfessor;
    orderedProfessorsPermProfessor = orderedProfessors;
    int noOfOutputs = 1;
    for (int perm = 0; perm < orderedProfessors.size() - 1; perm++)
    {

        for (int j = perm + 1; j < orderedProfessors.size(); j++)
        {
            if (orderedProfessors[perm].popular == orderedProfessors[j].popular)
            {
                swap(orderedProfessorsPermProfessor[perm], orderedProfessorsPermProfessor[j]);
                algorithm1(orderedProfessorsPermProfessor, OrderedCDCCourses, OrderedElectCourses, noOfOutputs);
                noOfOutputs++;
            }
        }
    }
}

void AlgorithmsSet::algorithm1(vector<Professor> OrderedProfessors, vector<Course> CDCCourses, vector<Course> ElectCourses, int noOfOutputs)
{

    for (int combination = 0; combination < 16; combination++)
    {
        vector<Professor> professors;
        professors = OrderedProfessors;
        vector<Course> OrderedCDCCourses;
        OrderedCDCCourses = CDCCourses;
        vector<Course> OrderedElectCourses;
        OrderedElectCourses = ElectCourses;
        assignedProfessorsWithCourses.clear();

        for (int i = 0; i < OrderedCDCCourses.size(); i++)
        {

            bool assignedFullCourse = false;
            int maxCoursePreferenceNo, courseType;
            if (OrderedCDCCourses[i].courseType == 1)
            {
                maxCoursePreferenceNo = Course::totalUGCDCCourses;
                courseType = 1;
            }
            else if (OrderedCDCCourses[i].courseType == 3)
            {
                maxCoursePreferenceNo = Course::totalHDCDCCourses;
                courseType = 3;
            }

            for (int coursePrefNo = 0; coursePrefNo < maxCoursePreferenceNo; coursePrefNo++)
            {

                bool reLoop = false;
                for (int j = 0; j < professors.size(); j++)
                {
                    bool profAssignedFullCredits = false;
                    if (courseType == 1)
                    {
                        if (professors[j].UGCDC.size() > coursePrefNo)
                        {

                            if (OrderedCDCCourses[i].name == Professor::UGCDCallCourse[professors[j].UGCDC[coursePrefNo]].name) // check if name is equal
                            {
                                double creditsRemoved;
                                if (combination % 2 != 0 && (professors[j].creditsAvailable != 0.5 && OrderedCDCCourses[i].creditsAvailableInCourse != 0.5))
                                {
                                    creditsRemoved = 1;
                                }
                                else
                                {
                                    creditsRemoved = 0.5;
                                }
                                professors[j].assignedCourses.push_back(OrderedCDCCourses[i]);
                                professors[j].creditsAvailable -= creditsRemoved; // deduct the credits of desired form(0.5/1).re-loop if 0.5
                                OrderedCDCCourses[i].creditsAvailableInCourse -= creditsRemoved;

                                assignedProfessorsWithCourses.push_back(professors[j]);
                                if (professors[j].creditsAvailable == 0) // when professors credits r 0 means assignment of prof is complete
                                {

                                    profAssignedFullCredits = true;
                                }
                                if (OrderedCDCCourses[i].creditsAvailableInCourse == 0)
                                {
                                    assignedFullCourse = true;
                                }

                                if (!assignedFullCourse && !profAssignedFullCredits)
                                {
                                    reLoop = true;
                                }
                                else if (profAssignedFullCredits)
                                {
                                    professors.erase(professors.begin() + j);
                                    j--;
                                }
                                if (assignedFullCourse)
                                {
                                    OrderedCDCCourses.erase(OrderedCDCCourses.begin() + i);
                                    i--;
                                    break;
                                }
                            }
                        }
                    }
                    else if (courseType == 3)
                    {
                        if (professors[j].HDCDC.size() > coursePrefNo)
                        {

                            if (OrderedCDCCourses[i].name == Professor::HDCDCallCourse[professors[j].HDCDC[coursePrefNo]].name) // check if name is equal
                            {

                                professors[j].assignedCourses.push_back(OrderedCDCCourses[i]);
                                double creditsRemoved;
                                if (combination % 4 >= 2 && (professors[j].creditsAvailable != 0.5 && OrderedCDCCourses[i].creditsAvailableInCourse != 0.5))
                                {
                                    creditsRemoved = 1;
                                }
                                else
                                {
                                    creditsRemoved = 0.5;
                                }
                                professors[j].creditsAvailable -= creditsRemoved; // deduct the credits of desired form(0.5/1).re-loop if 0.5
                                OrderedCDCCourses[i].creditsAvailableInCourse -= creditsRemoved;

                                assignedProfessorsWithCourses.push_back(professors[j]);
                                if (professors[j].creditsAvailable == 0) // when professors credits r 0 means assignment of prof is complete
                                {

                                    profAssignedFullCredits = true;
                                }
                                if (OrderedCDCCourses[i].creditsAvailableInCourse == 0)
                                {
                                    assignedFullCourse = true;
                                }

                                if (!assignedFullCourse && !profAssignedFullCredits)
                                {
                                    reLoop = true;
                                }
                                else if (profAssignedFullCredits)
                                {
                                    professors.erase(professors.begin() + j);
                                    j--;
                                }
                                if (assignedFullCourse)
                                {
                                    OrderedCDCCourses.erase(OrderedCDCCourses.begin() + i);
                                    i--;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (reLoop)
                {
                    coursePrefNo--;
                }
                if (assignedFullCourse)
                {
                    break;
                }
            }
        }

        calcPopularityOfProfOnElectives(professors);
        //  cout << "Professors to be alloted Electives:\n";
        // printProfessors(professors);

        for (int i = 0; i < OrderedElectCourses.size(); i++)
        {

            bool assignedFullCourse = false;
            int maxCoursePreferenceNo, courseType;
            if (OrderedElectCourses[i].courseType == 2)
            {
                maxCoursePreferenceNo = Course::totalUGElectCourses;
                courseType = 2;
            }
            else if (OrderedElectCourses[i].courseType == 4)
            {
                maxCoursePreferenceNo = Course::totalHDElectCourses;
                courseType = 4;
            }

            for (int coursePrefNo = 0; coursePrefNo < maxCoursePreferenceNo; coursePrefNo++)
            {

                bool reLoop = false;
                for (int j = 0; j < professors.size(); j++)
                {
                    bool profAssignedFullCredits = false;
                    if (courseType == 2)
                    {
                        if (professors[j].UGELECT.size() > coursePrefNo)
                        {

                            if (OrderedElectCourses[i].name == Professor::UGELECTallCourse[professors[j].UGELECT[coursePrefNo]].name) // check if name is equal
                            {

                                professors[j].assignedCourses.push_back(OrderedElectCourses[i]);
                                double creditsRemoved;
                                if (combination % 8 >= 4 && (professors[j].creditsAvailable != 0.5 && OrderedCDCCourses[i].creditsAvailableInCourse != 0.5))
                                {
                                    creditsRemoved = 1;
                                }
                                else
                                {
                                    creditsRemoved = 0.5;
                                }
                                professors[j].creditsAvailable -= creditsRemoved; // deduct the credits of desired form(0.5/1).re-loop if 0.5
                                OrderedElectCourses[i].creditsAvailableInCourse -= creditsRemoved;

                                assignedProfessorsWithCourses.push_back(professors[j]);
                                if (professors[j].creditsAvailable == 0) // when professors credits r 0 means assignment of prof is complete
                                {

                                    profAssignedFullCredits = true;
                                }
                                if (OrderedElectCourses[i].creditsAvailableInCourse == 0)
                                {
                                    assignedFullCourse = true;
                                }

                                if (!assignedFullCourse && !profAssignedFullCredits)
                                {
                                    reLoop = true;
                                }
                                else if (profAssignedFullCredits)
                                {
                                    professors.erase(professors.begin() + j);
                                    j--;
                                }
                                if (assignedFullCourse)
                                {
                                    OrderedElectCourses.erase(OrderedElectCourses.begin() + i);
                                    i--;
                                    break;
                                }
                            }
                        }
                    }
                    else if (courseType == 4)
                    {
                        if (professors[j].HDELECT.size() > coursePrefNo)
                        {

                            if (OrderedElectCourses[i].name == Professor::HDELECTallCourse[professors[j].HDELECT[coursePrefNo]].name) // check if name is equal
                            {

                                professors[j].assignedCourses.push_back(OrderedElectCourses[i]);
                                double creditsRemoved;
                                if (combination % 16 >= 8 && (professors[j].creditsAvailable != 0.5 && OrderedCDCCourses[i].creditsAvailableInCourse != 0.5))
                                {
                                    creditsRemoved = 1;
                                }
                                else
                                {
                                    creditsRemoved = 0.5;
                                }
                                professors[j].creditsAvailable -= creditsRemoved; // deduct the credits of desired form(0.5/1).re-loop if 0.5
                                OrderedElectCourses[i].creditsAvailableInCourse -= creditsRemoved;

                                assignedProfessorsWithCourses.push_back(professors[j]);
                                if (professors[j].creditsAvailable == 0) // when professors credits r 0 means assignment of prof is complete
                                {

                                    profAssignedFullCredits = true;
                                }
                                if (OrderedElectCourses[i].creditsAvailableInCourse == 0)
                                {
                                    assignedFullCourse = true;
                                }

                                if (!assignedFullCourse && !profAssignedFullCredits)
                                {
                                    reLoop = true;
                                }
                                else if (profAssignedFullCredits)
                                {
                                    professors.erase(professors.begin() + j);
                                    j--;
                                }
                                if (assignedFullCourse)
                                {
                                    OrderedElectCourses.erase(OrderedElectCourses.begin() + i);
                                    i--;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (reLoop)
                {
                    coursePrefNo--;
                }
                if (assignedFullCourse)
                {
                    break;
                }
            }
        }

        for (int i = assignedProfessorsWithCourses.size() - 1; i > 0; i--) // Removes duplicates and keeps the latest values
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (assignedProfessorsWithCourses[i].name == assignedProfessorsWithCourses[j].name)
                {
                    assignedProfessorsWithCourses.erase(assignedProfessorsWithCourses.begin() + j);
                    i--;
                }
            }
        }

        for (int i = 0; i < assignedProfessorsWithCourses.size(); i++)
        {
            for (int j = 0; j < assignedProfessorsWithCourses[i].assignedCourses.size() - 1; j++)
            {
                for (int k = j + 1; k < assignedProfessorsWithCourses[i].assignedCourses.size(); k++)
                {
                    if (assignedProfessorsWithCourses[i].assignedCourses[j].name == assignedProfessorsWithCourses[i].assignedCourses[k].name)
                    {
                        assignedProfessorsWithCourses[i].assignedCourses.erase(assignedProfessorsWithCourses[i].assignedCourses.begin() + k);
                        k--;
                    }
                }
            }
        }

        cout << "\n\n\nOutput: " << 16 * noOfOutputs + combination + 1 << "\n\n";
        for (int i = 0; i < assignedProfessorsWithCourses.size(); i++) // Prints the assigned profs with Courses
        {
            cout << i + 1 << ". " << assignedProfessorsWithCourses[i].name << endl;
            for (int j = 0; j < assignedProfessorsWithCourses[i].assignedCourses.size(); j++)
            {
                cout << "\t" << j + 1 << ". " << assignedProfessorsWithCourses[i].assignedCourses[j].name << endl;
            }
        }
        cout << "\nTotal Number of Courses Assigned is: " << Course::totalUGCDCCourses + Course::totalHDCDCCourses + Course::totalUGElectCourses + Course::totalHDElectCourses - OrderedCDCCourses.size() - OrderedElectCourses.size() << endl;
    }
}
