// CoursePlanner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//CS 300 Project Two: Advising Assistance Program
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Convert a string to uppercase
string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

vector<Course> courseList;

// Function to load the course data
void loadDataStructure() {
    string filename;
    cout << "Enter the name of the input file (press Enter to use default): ";
    getline(cin, filename); // prompt for filename
    if (filename.empty()) {
        filename = "CS 300 ABCU_Advising_Program_Input.csv"; // use default if empty
    }

    ifstream file(filename); // open file with name filename
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) { // for each line in file
        Course course;
        stringstream ss(line);
        string field;
        int count = 0;

        while (getline(ss, field, ',')) { // split line by commas
            if (count == 0)
                course.courseNumber = field; // courseNumber = parts[0]
            else if (count == 1)
                course.courseTitle = field; // courseTitle = parts[1]
            else
                course.prerequisites.push_back(field); // add to prerequisites list
            count++;
        }

        courseList.push_back(course); // insert course into courseList
    }

    file.close();
    cout << "Course data loaded successfully.\n";
}

// Function to print all courses in alphanumeric order
void printCourseList() {
    // sort courseList by courseNumber
    sort(courseList.begin(), courseList.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
        });

    cout << "Here is a sample schedule:\n";
    // for each course, print courseNumber and courseTitle
    for (const Course& course : courseList) {
        cout << course.courseNumber << ", " << course.courseTitle << endl;
    }
}

// Function to print a single course by course number
void printCourse() {
    string searchNumber;
    cout << "What course do you want to know about? "; // prompt user
    cin >> searchNumber;
    cin.ignore();

    searchNumber = toUpperCase(searchNumber);

    // for each course, if courseNumber matches, print details
    for (const Course& course : courseList) {
        if (toUpperCase(course.courseNumber) == searchNumber) {
            cout << course.courseNumber << ", " << course.courseTitle << endl;
            cout << "Prerequisites: ";
            if (course.prerequisites.empty()) {
                cout << "None" << endl; // if no prerequisites
            }
            else {
                for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                    cout << course.prerequisites[i];
                    if (i < course.prerequisites.size() - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            return;
        }
    }

    cout << "Course not found.\n"; // handle course not found
}

int main() {
    int choice = 0;

    while (choice != 9) {
        cout << "\n1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit.\n";
        cout << "What would you like to do? ";
        cin >> choice;
        cin.ignore(); // To handle leftover newline

        switch (choice) {
        case 1:
            loadDataStructure();
            break;
        case 2:
            printCourseList();
            break;
        case 3:
            printCourse();
            break;
        case 9:
            cout << "Thank you for using the course planner!\n";
            break;
        default:
            cout << choice << " is not a valid option.\n";
        }
    }

    return 0;
}