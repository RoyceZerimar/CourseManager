#pragma once
#ifndef COURSE_FUNCTIONS_H
#define COURSE_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//============================================================================
// Course class definition
//============================================================================
class Course {
public:
    string courseNumber; // Store the course number
    string title; // Store the course title
    vector<string> prerequisites; // A list(vector) to stor coures prerequisites

    // Constructor to initialize Course object
    Course(const string& courseNumber, const string& title)
        : courseNumber(courseNumber), title(title) {}

    // Destructor to release memory
    ~Course() {}
};

//============================================================================
// Helper Functions definitions
//============================================================================

vector<Course*> LoadCourseData(const string& filename);
void PrintCourseInformationAlphabetically(const vector<Course*>& courses);
void PrintCourseInformation(const vector<Course*>& courses, const string& courseNumber);
void CleanupCourses(vector<Course*>& courses);

#endif
