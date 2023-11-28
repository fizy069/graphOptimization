#include <iostream>
#include "course.h"
#include "professor.h"
#include "algorithmsSet.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

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

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    freopen("output2.txt", "w", stdout);
    ifstream inputFile("prof_input.txt");
    char c;
    string name = "";
    vector<int> UGCDC, UGELEC, HDCDC, HDELEC;
    bool prof = false;
    // double cred;
    int curlyout = 0;
    vector<Professor> professors;

    while (inputFile.get(c))
    {
        if (c == ' ')
        {
            continue;
        }
        if (c == '"')
        {
            while (inputFile.get(c) && c != '"')
            {
                name += c;
            }
            if (c == '"')

                // cout<<name<<endl;
                continue;
        }
        if (c == '{' && curlyout == 0)
        {
            while (inputFile.get(c) && c != '}')
            {
                if (c == ' ')
                    continue;
                // cout<<c<<endl;
                int d = c - '0';
                // int d;
                // cout<<d<<endl;
                UGCDC.push_back(d);
                // return 0;
            }

            if (c == '}')
            {
                curlyout++;
                continue;
            }
        }
        if (c == '{' && curlyout == 1)
        {
            while (inputFile.get(c) && c != '}')
            {
                if (c == ' ')
                    continue;

                int d = c - '0';
                // int d;
                UGELEC.push_back(d);
                // cout<<d<<endl;
            }
            if (c == '}')
            {
                curlyout++;
                continue;
            }
        }
        if (c == '{' && curlyout == 2)
        {

            while (inputFile.get(c) && c != '}')
            {
                if (c == ' ')
                    continue;
                int d = c - '0';
                // int d;
                HDCDC.push_back(d);
                // cout<<d<<endl;
            }
            if (c == '}')
            {
                curlyout++;
                continue;
            }
        }
        if (c == '{' && curlyout == 3)
        {
            while (inputFile.get(c) && c != '}')
            {
                if (c == ' ')
                    continue;

                int d = c - '0';
                // int d;
                HDELEC.push_back(d);
                // cout<<d<<endl;
            }
            if (c == '}')
            {
                curlyout++;
                continue;
            }
        }
        if (curlyout == 4)
        {
            // cout<<"entering c = 4\n";
            // inputFile.get(c);
            if (c == ' ')
                continue;
            else if (c == 'x')
            {
                inputFile.get(c);
                if (c == '1')
                {
                    Professor p(name, UGCDC, UGELEC, HDCDC, HDELEC, 0.5);
                    professors.push_back(p);

                    prof = true;

                    UGCDC.clear();
                    UGELEC.clear();
                    HDCDC.clear();
                    HDELEC.clear();
                    name = "";
                    curlyout = 0;

                    // inputFile.get(c);
                }
                else if (c == '2')
                {
                    Professor p(name, UGCDC, UGELEC, HDCDC, HDELEC, 1);
                    professors.push_back(p);
                    prof = true;

                    UGCDC.clear();
                    UGELEC.clear();
                    HDCDC.clear();
                    HDELEC.clear();
                    name = "";
                    curlyout = 0;

                    // cout << "x2" << endl;
                    // inputFile.get(c);
                }
                else
                {
                    Professor p(name, UGCDC, UGELEC, HDCDC, HDELEC, 1.5);
                    professors.push_back(p);
                    prof = true;

                    // cout << "x3" << endl;

                    UGCDC.clear();
                    UGELEC.clear();
                    HDCDC.clear();
                    HDELEC.clear();
                    name = "";
                    curlyout = 0;

                    // inputFile.get(c);
                }
            }
        }
    }

    inputFile.close();
   

    Course UGCDCcourses[] = {
        Course("CS F11 CP1", 1),
        Course("CS F12 CP2", 1),
        Course("CS F13 CP3", 1),
        Course("CS F214 LCS", 1),
        Course("CS F222 DisCo", 1),
        Course("CS F213 OOP", 1),
        Course("CS F215 DD", 1),
        Course("CS F211 DSA", 1),
        Course("CS F241 MUP", 1),
        Course("CS F212 DBMS", 1),
        Course("CS F301 PoPL", 1),
        Course("CS F342 CompArch", 1),
        Course("CS F351 ToC", 1),
        Course("CS F372 OS", 1),
        Course("CS F303 COMP NETWORKS", 1),
        Course("CS F363 COMPILER CONSTRUCTION", 1),
        Course("CS F364 DAA", 1)};
    Course UGELECTcourses[] = {
        Course("BITS F311 Image Processing", 2),
        Course("BITS F312 NEURAL NET & FUZZY LOGIC", 2),
        Course("BITS F343 FUZZY LOGIC & APPL", 2),
        Course("BITS F364 HUMAN COMP INTERACTION", 2),
        Course("BITS F386 QUANTUM INFO & COMPUTING", 2),
        Course("BITS F452 BLOCKCHAIN TECHNOLOGY", 2),
        Course("BITS F463 CRYPTOGRAPHY", 2),
        Course("BITS F464 MACHINE LEARNING", 2)};
    Course HDCDCcourses[] = {
        Course("CS G513 Network Security", 3),
        Course("CSG524 Advanced Computer Architecture", 3),
        Course("CS G525 Advanced Computer Networks", 3),
        Course("CS G526 Advanced Algorithms and Complexity", 3),
        Course("CS C623 Advanced Operating Systems", 3)};
    Course HDELECTcourses[] = {
        Course("SS G527 Cloud Computing", 4),
        Course("BITS G553 Real-Time Systems", 4),
        Course("CS G553 Reconfigurable Computing", 4),
        Course("CS G568 Network Security Projec", 4),
        Course("SS G513 Network Security", 4),
        Course("CS G523 Software for Embedded Systems", 4),
        Course("SS G554 Distributed Data Systems", 4)};

    assigningUGCDCcourses(UGCDCcourses, sizeof(UGCDCcourses) / sizeof(UGCDCcourses[0]));
    assigningUGELECTcourses(UGELECTcourses, sizeof(UGELECTcourses) / sizeof(UGELECTcourses[0]));
    assigningHDCDCcourses(HDCDCcourses, sizeof(HDCDCcourses) / sizeof(HDCDCcourses[0]));
    assigningHDELECTcourses(HDELECTcourses, sizeof(HDELECTcourses) / sizeof(HDELECTcourses[0]));

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
    // // Professor("A. Baskar", {1, 3, 2, 4}, {1, 3, 0, 5}, {3, 1, 2}, {1, 2, 3, 4}, 1.5)
    // };
    showProfessors(professors);
    showCourses(Professor::UGCDCallCourse, Professor::UGELECTallCourse, Professor::HDCDCallCourse, Professor::HDELECTallCourse);

    AlgorithmsSet::initiateAlgorithms(vector<Professor>(professors),
                                      vector<Course>(Professor::UGCDCallCourse, Professor::UGCDCallCourse + Course::totalUGCDCCourses),
                                      vector<Course>(Professor::UGELECTallCourse, Professor::UGELECTallCourse + Course::totalUGElectCourses),
                                      vector<Course>(Professor::HDCDCallCourse, Professor::HDCDCallCourse + Course::totalHDCDCCourses),
                                      vector<Course>(Professor::HDELECTallCourse, Professor::HDELECTallCourse + Course::totalHDElectCourses));

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
