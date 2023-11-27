// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// struct Professor {
//     string name;
//     double maxCourses;  // Maximum number of courses a professor can take
//     vector<string> preferences;
// };

// struct Assignment {
//     string course;
//     string professor;
// };

// double calculateMaxFitness( vector<Professor>& professors, const vector<string>& courses,
//                             int courseIndex, unordered_map<string, double>& memo,
//                             vector<Assignment>& optimalAssignments) {
    
//     if (courseIndex == courses.size()) {
//         cout << "No further possible assignments\n";
//         return 0.0;
//     }

//     // check if result is precomputed
//     string key = to_string(courseIndex);
//     if (memo.find(key) != memo.end()) {
//         return memo[key];
//     }

//     double maxFitness = 0.0;

// // Try assigning the current course to each professor
// for (Professor& professor : professors) {
//     if (find(professor.preferences.begin(), professor.preferences.end(), courses[courseIndex]) !=
//         professor.preferences.end() && professor.maxCourses > 0) {

//         // Calculate the fitness based on the fractional nature of shared courses
//         double assignmentCapacity = min(1.0, professor.maxCourses);

//         // Check if shared courses are allowed and update assignmentCapacity accordingly
//         if (assignmentCapacity == 1.0 && professor.maxCourses > 1.0) {
//             assignmentCapacity = 0.5;  // Allow for shared courses
//         }

//         double fitness = assignmentCapacity + calculateMaxFitness(
//             professors, courses, courseIndex + 1, memo, optimalAssignments);

//         if (fitness > maxFitness) {
//             maxFitness = fitness;

//             optimalAssignments[courseIndex] = {courses[courseIndex], professor.name};

//             // Update the professor's remaining courses considering shared courses
//             professor.maxCourses -= assignmentCapacity;
//         }
//     }
// }



//     // Memoize the result
//     memo[key] = maxFitness;

//     return maxFitness;
// }

// int main() {
//     // Sample data as before
//     vector<Professor> professors = {
//         {"x1", 1.0, {"Math", "English", "Physics"}},
//         {"x2", 1.5, {"English", "History", "Chemistry"}},
//         {"x3", 0.5, {"Physics", "Math", "Biology"}}
//     };

//     vector<string> courses = {"Math", "English", "Physics", "History", "Chemistry", "Biology"};

//     // temp map to store precomputed results

//     unordered_map<string, double> memo;

//     // initialize
//     vector<Assignment> optimalAssignments(courses.size());

//     double maxFitness = calculateMaxFitness(professors, courses, 0, memo, optimalAssignments);

//     cout << "Maximum total fitness: " << maxFitness << endl;

//     for (const Assignment& assignment : optimalAssignments) {
//         cout << "Course: " << assignment.course << " assigned to Professor: " << assignment.professor << endl;
//     }

//     return 0;
// }
