#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Professor {
    string name;
    double capacity;
    vector<string> preferences;
};

struct Assignment {
    string course;
    string professor;
};

// dp
double calculateMaxFitness(const vector<Professor>& professors, const vector<string>& courses,
                            int courseIndex, double remainingCapacity,
                            unordered_map<string, double>& memo, vector<Assignment>& optimalAssignments) {
    
    if (courseIndex == courses.size() || remainingCapacity <= 0) {
        cout << "No further possible assignments\n";
        return 0.0;
    }

    // check if result is precomputedd
    string key = to_string(courseIndex) + "-" + to_string(remainingCapacity);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    double maxFitness = 0.0;

    // Try assigning the current course to each professor
    for (const Professor& professor : professors) {
        if (find(professor.preferences.begin(), professor.preferences.end(), courses[courseIndex]) !=
            professor.preferences.end() && remainingCapacity >= professor.capacity) {
            
            double assignmentCapacity = min(professor.capacity, remainingCapacity);
            
            
            double fitness = assignmentCapacity + calculateMaxFitness(
                professors, courses, courseIndex + 1, remainingCapacity - assignmentCapacity, memo, optimalAssignments);

            
            if (fitness > maxFitness) {
                maxFitness = fitness;

                
                optimalAssignments[courseIndex] = {courses[courseIndex], professor.name};
            }
        }
    }

    // Memoize the result
    memo[key] = maxFitness;

    return maxFitness;
}

int main() {
    // Sample data as before
    vector<Professor> professors = {
        {"x1", 0.5, {"Math", "English", "Physics"}},
        {"x2", 1, {"English", "History", "Chemistry"}},
        {"x3", 1.5, {"Physics", "Math", "Biology"}}
    };

    vector<string> courses = {"Math", "English", "Physics", "History", "Chemistry", "Biology"};

    //temp map to store precomputed results
    unordered_map<string, double> memo;

    // initialize
    vector<Assignment> optimalAssignments(courses.size());

    double maxFitness = calculateMaxFitness(professors, courses, 0, 999.0, memo, optimalAssignments);

    cout << "Maximum total fitness: " << maxFitness << endl;


    for (const Assignment& assignment : optimalAssignments) {
        cout << "Course: " << assignment.course << " assigned to Professor: " << assignment.professor << endl;
    }

    return 0;
}
