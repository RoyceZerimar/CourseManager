#include "course_function.h" // Include the header file for helper functions

#include <iostream>   // This lets you do basic input and output.
#include <fstream>    // This allows you to work with files.
#include <sstream>    // This helps you work with strings as if they were streams of data.
#include <vector>     // This gives you a way to store lists of items that can change in size.
#include <algorithm>  // This provides tools for sorting and searching lists.
#include <stdexcept>  // This allows you to throw and catch runtime errors.
#include <limits>     // This provides information about the properties of numeric types.


using namespace std;

/*
* Function to read course data from a file and create Course objects
*/

vector<Course*> LoadCourseData(const string& filename) {
    // Create a vector to store Cousre objects
    vector<Course*> courses;

    // Open the file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return courses; // Return empty vector if file cannot be opened
    }

    // Read each line from the file
    string line;
    while (getline(file, line)) {
        //Break down the line to extract courseNumber and title 
        istringstream iss(line);
        string courseNumber, title, prerequisite;

        //Extract courseNumber and title from the line
        if (getline(iss, courseNumber, ',')) {
            if (getline(iss, title, ',')) {
                // Reserve memory for a new Course object
                Course* course = new Course(courseNumber, title);

                // Extract prerequisites from the line and add them to the Course object
                while (getline(iss, prerequisite, ',')) {
                    course->prerequisites.push_back(prerequisite);
                }
                // Add the Course object to the vector
                courses.push_back(course);
            }
            else {
                cerr << "Error: incorrect file format - missing title" << endl;
            }
        }
        else {
            cerr << "Error: incorrect file format - missing Course Number" << endl;
        }
    }
    // Close the file
    file.close();
    // Return the vector of Course objects
    return courses;
}


/*
* Function to print course information sorted by course number
*/

void PrintCourseInformationAlphabetically(const vector<Course*>& courses) {
    // Check if the vector  is empty
    if (!courses.empty()) {
        // Create a copy of the course vector to sort
        vector<Course*> sortedCourses = courses;

        //Sort courses by cousre number using lambda function
        sort(sortedCourses.begin(), sortedCourses.end(), [](const Course* a, const Course* b) {
            // Compare course number for sorting
            return a->courseNumber < b->courseNumber;
            });

        // Print sorted course information
        cout << "Here is a sample schedule: " << endl;
        cout << endl;

        // Print sorted course information 
        for (const auto& course : sortedCourses) {
            cout << course->courseNumber << ", "; // Print course number
            cout << course->title << endl; // Print course title

        }
    }
    else {
        // Print message if the vector  is empty
        cout << "No course data has been loaded yet. Please select option 1 in the menu to load course data." << endl;
    }
}

/*
*Function to find and print information for a specific course
*/

void PrintCourseInformation(const vector<Course*>& courses, const string& courseNumber) {
    // Checkes if the vector of courses is empty
    if (!courses.empty()) {
        // Go through each Course object in the vector
        for (const auto& course : courses) {
            //Check if the courseNumber matches the specified courseNumber
            if (course->courseNumber == courseNumber) {
                //Print cours information if found
                cout << "Course Information for " << courseNumber << ":" << endl;
                cout << "Course Title: " << course->title << endl;
                //Check if there are prerequisites for the course
                if (!course->prerequisites.empty()) {
                    cout << "Prerequisites: " << endl;
                    //Prints each prerequisites
                    for (const string& prereq : course->prerequisites) {
                        cout << " " << prereq << endl;
                    }
                }
                else {
                    // Print message if no prerequisites
                    cout << "No Prerequisites" << endl;
                }
                return; // Exit after printing information for the specified course
            }
        }
        // If the course number is not found
        cout << "Course " << courseNumber << " not found." << endl;
    }
    // Prints message if the vector is empty
    else { cout << "No course data has been loaded yet. Please select option 1 in the menu to load course data." << endl; }
}


/*
*Function to release memory for Course objects
*/
void CleanupCourses(vector<Course*>& courses) {
    // Go through each Course object in the list
    for (auto& course : courses) {
        // Free up memory used by each Course object
        delete course;
    }
    // Clear the list to remove all Course objects
    courses.clear();
}