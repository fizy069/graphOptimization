#include <iostream>
#include "course.h"
#include "professor.h"
#include "algorithmsSet.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

using namespace std;

bool isInteger(const std::string &s)
{
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int convertToInteger(const std::string &s)
{
    if (s == "x1")
        return 0.5;
    if (s == "x2")
        return 1;
    if (s == "x3")
        return 1.5;
    return std::stoi(s);
}

void showCourses(Course UGCDCcourses[], Course UGELECTcourses[], Course HDCDCcourses[], Course HDELECTcourses[])
{
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
void printVector(const vector<int> vec)
{
    for (const auto &element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

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

void readFile(vector<Professor> &professors)
{
    std::ifstream file("prof_input.csv");

    if (!file.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        string name = "";
        vector<int> UGCDC = {}, UGELECT = {}, HDCDC = {}, HDELECT = {};
        double creds = 0;
        int ctr = 0;

        stringstream ss(line);

        getline(ss, name, ',');

        string subjectToken;
        int subjectIndex = 0;
        while (getline(ss, subjectToken, ','))
        {

            if (subjectToken.empty())
                break;
            stringstream subjectStream(subjectToken);

            string grade;
            while (getline(subjectStream, grade, ' '))
            {
                if (isInteger(grade) || (grade == "x1" || grade == "x2" || grade == "x3"))
                {

                    if (grade == "x1")
                    {
                        creds = 0.5;
                    }
                    else if (grade == "x2")
                    {
                        creds = 1;
                    }
                    else if (grade == "x3")
                    {
                        creds = 1.5;
                    }
                    else
                    {
                        int gradeValue = convertToInteger(grade);

                        switch (subjectIndex)
                        {
                        case 0:
                            UGCDC.push_back(gradeValue);
                            break;
                        case 1:
                            UGELECT.push_back(gradeValue);
                            break;
                        case 2:
                            HDCDC.push_back(gradeValue);
                            break;
                        case 3:
                            HDELECT.push_back(gradeValue);
                            break;
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    std::cerr << "error - " << grade << std::endl;
                }
            }
            subjectIndex++;
        }
        Professor p(name, UGCDC, UGELECT, HDCDC, HDELECT, creds);
        professors.emplace_back(p);
    }
    file.close();
}

int main()
{
    Course UGCDCcourses[] = {
        Course("CS F11 CP1", 1),                    // index 0
        Course("CS F12 CP2", 1),                    // index 1
        Course("CS F13 CP3", 1),                    // index 2
        Course("CS F214 LCS", 1),                   // index 3
        Course("CS F222 DisCo", 1),                 // index 4
        Course("CS F213 OOP", 1),                   // index 5
        Course("CS F215 DD", 1),                    // index 6
        Course("CS F211 DSA", 1),                   // index 7
        Course("CS F241 MUP", 1),                   // index 8
        Course("CS F212 DBMS", 1),                  // index 9
        Course("CS F301 PoPL", 1),                  // index 10
        Course("CS F342 CompArch", 1),              // index 11
        Course("CS F351 ToC", 1),                   // index 12
        Course("CS F372 OS", 1),                    // index 13
        Course("CS F303 COMP NETWORKS", 1),         // index 14
        Course("CS F363 COMPILER CONSTRUCTION", 1), // index 15
        Course("CS F364 DAA", 1)};                  // index 16

    Course UGELECTcourses[] = {
        Course("BITS F311 Image Processing", 2),         // index 0
        Course("BITS F312 NEURAL NET & FUZZY LOGIC", 2), // index 1
        Course("BITS F343 FUZZY LOGIC & APPL", 2),       // index 2
        Course("BITS F364 HUMAN COMP INTERACTION", 2),   // index 3
        Course("BITS F386 QUANTUM INFO & COMPUTING", 2), // index 4
        Course("BITS F452 BLOCKCHAIN TECHNOLOGY", 2),    // index 5
        Course("BITS F463 CRYPTOGRAPHY", 2),             // index 6
        Course("BITS F464 MACHINE LEARNING", 2)};        // index 7

    Course HDCDCcourses[] = {
        Course("CS G513 Network Security", 3),                   // index 0
        Course("CSG524 Advanced Computer Architecture", 3),      // index 1
        Course("CS G525 Advanced Computer Networks", 3),         // index 2
        Course("CS G526 Advanced Algorithms and Complexity", 3), // index 3
        Course("CS C623 Advanced Operating Systems", 3)};        // index 4

    Course HDELECTcourses[] = {
        Course("SS G527 Cloud Computing", 4),               // index 0
        Course("BITS G553 Real-Time Systems", 4),           // index 1
        Course("CS G553 Reconfigurable Computing", 4),      // index 2
        Course("CS G568 Network Security Projec", 4),       // index 3
        Course("SS G513 Network Security", 4),              // index 4
        Course("CS G523 Software for Embedded Systems", 4), // index 5
        Course("SS G554 Distributed Data Systems", 4)};     // index 6

    assigningUGCDCcourses(UGCDCcourses, sizeof(UGCDCcourses) / sizeof(UGCDCcourses[0]));
    assigningUGELECTcourses(UGELECTcourses, sizeof(UGELECTcourses) / sizeof(UGELECTcourses[0]));
    assigningHDCDCcourses(HDCDCcourses, sizeof(HDCDCcourses) / sizeof(HDCDCcourses[0]));
    assigningHDELECTcourses(HDELECTcourses, sizeof(HDELECTcourses) / sizeof(HDELECTcourses[0]));

<<<<<<< HEAD
    // vector<Professor> professors{

    //     Professor("Prof1", {3, 1, 2}, {2, 0, 1}, {2, 3, 0}, {3, 1, 2}, 1.5),
    //     Professor("Prof2", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 0.5),
    //     Professor("Prof3", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    //     Professor("Prof4", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    //     Professor("Prof5", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1}, 0.5),
    //     Professor("Prof6", {0, 1, 2}, {2, 3, 1}, {3, 1, 2}, {1, 2, 3}, 1.5),
    //     Professor("Prof7", {1, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1.5),
    //     Professor("Prof8", {0, 1, 3}, {2, 3, 0}, {2, 3, 0}, {1, 2, 3}, 1),
    //     Professor("Prof9", {1, 2, 3}, {1, 2, 3}, {3, 2, 0}, {3, 0, 1}, 1)};

    // vector<Professor> professors{

    // Professor("Snehanshu Saha", {4, 5, 3}, {2, 0, 1, 6}, {2, 3, 0}, {3, 1, 2, 4}, 1.5),
    // Professor("Ramprasad S. Joshi", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 0.5),
    // Professor("Harikrishnan N. B.", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    // Professor("A. Baskar", {1, 3, 2, 4}, {1, 3, 0, 5}, {3, 1, 2}, {1, 2, 3, 4}, 1.5),
    // Professor("Aditya Challa", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1, 4}, 0.5),
    // Professor("Arnab Kumar Paul", {0, 1, 2}, {2, 3, 1}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Ashwin Srinivasan", {1, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1.5),
    // Professor("Biju K. Raveendran Nair", {0, 1, 3}, {2, 3, 0}, {2, 3, 0}, {1, 2, 3}, 1),
    // Professor("Devashish Gosain", {1, 2, 3}, {1, 2, 3}, {3, 2, 0}, {3, 0, 1}, 1),
    // Professor("Sougata Sen", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    // Professor("Hemant Rathore", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Basabdatta Bhattacharya", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1}, 0.5),
    // Professor("Bharat Madhusudan Deshpande", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Diptendu Chatterjee", {1, 3, 0}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1.5),
    // Professor("Kanchan Manna", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Kunal Kishore Korgaonkar", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    // Professor("Neena Goveas", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Rajesh Kumar", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Santonu Sarkar", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    // Professor("Vinayak Naik", {1, 2, 3}, {1, 2, 3}, {3, 2, 0}, {3, 0, 1}, 1),
    // Professor("Sujith Thomas", {0, 1, 2}, {2, 3, 0}, {3, 1, 2}, {1, 2, 3}, 0.5),
    // Professor("Swaroop Joshi", {2, 3, 0}, {3, 1, 2}, {2, 3, 0}, {2, 0, 1, 4}, 0.5),
    // Professor("Swati Agarwal", {1, 3, 2}, {1, 3, 0}, {3, 1, 2}, {1, 2, 3}, 1.5),
    // Professor("Tanmay Tulsidas Verlekar", {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 0, 1}, 1),
    // };
    // cout<<"SHOWING PROF\n";
=======
    vector<Professor> professors;
    readFile(professors);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < Course::totalUGCDCCourses; i++)
    {
        if (Professor::UGCDCallCourse[i].popular == 0)
        {
            cout << "\n\nCRASH TEST: NO PROFESSOR HAS TAKEN COURSE " << Professor::UGCDCallCourse[i].name << endl;
            return -1;
        }
    }
    for (int i = 0; i < Course::totalHDCDCCourses; i++)
    {
        if (Professor::HDCDCallCourse[i].popular == 0)
        {
            cout << "\n\nCRASH TEST: NO PROFESSOR HAS TAKEN COURSE " << Professor::HDCDCallCourse[i].name << endl;
            return -1;
        }
    }

>>>>>>> 84f5b535ccbda96d05453c8b4a08365bf0f78c6c
    showProfessors(professors);
    showCourses(Professor::UGCDCallCourse, Professor::UGELECTallCourse, Professor::HDCDCallCourse, Professor::HDELECTallCourse);

    AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors),
                                      vector<Course>(Professor::UGCDCallCourse, Professor::UGCDCallCourse + Course::totalUGCDCCourses),
                                      vector<Course>(Professor::UGELECTallCourse, Professor::UGELECTallCourse + Course::totalUGElectCourses),
                                      vector<Course>(Professor::HDCDCallCourse, Professor::HDCDCallCourse + Course::totalHDCDCCourses),
                                      vector<Course>(Professor::HDELECTallCourse, Professor::HDELECTallCourse + Course::totalHDElectCourses));

    return 0;
}
