//============================================================================
// Name        : CourseManager.cpp
// Author      : Justin Ramirez
// Version     : 1.0
//============================================================================


#include <iostream>          // This lets you do basic input and output.
#include <vector>            // This gives you a way to store lists of items that can change in size.
#include <algorithm>         // This provides tools for sorting and searching lists.
#include "course_function.h" // Include the header file for helper functions

using namespace std; // This lets you use the standard functions and objects without typing "std::" each time.


//============================================================================
// Main method
//============================================================================

int main(int argc, char* argv[]) {
    //Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        // Print usage message if the correct number of arguments is not provided
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;// Return with error code
    }
    // Get filename from the command-line argument
    string filename = argv[1];

    // Create a vector to store pointers to Course objects
    vector<Course*> courses;

    //Create a string variable to store the cours number
    string courseNum;

    //Create a int variable to store the user's choice from the menu
    int choice;

    // Start a do-while loop to display the menu and prompt the user fot input
    do {
        // Display the menu options
        cout << "\nMenu:\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course information in alphabetical order\n";
        cout << "3. Print information for a specific course\n";
        cout << "9. Exit\n";
        cout << "What would you like to do? ";

        // Get the user's choice
       // Use a try-catch to handle input errors
        try {
            cin >> choice;
            if (cin.fail()) {
                throw runtime_error("Invalid input. Please enter a valid number.");
            }
        }

        catch (const runtime_error& e) {
            cerr << e.what() << endl; // Print error message
            cin.clear();// Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Ger rid of invalid input
        }

        //Process the user's choice using a switch statment
        switch (choice) {
        case 1:
            //load course data from the file and store it in th course vector
            courses = LoadCourseData(filename);
            cout << "Data loaded successfully...." << endl;
            break;

        case 2:
            // Print course information in alphabetical order
            cout << endl;
            PrintCourseInformationAlphabetically(courses);
            cout << endl;
            break;

        case 3:
            // Prompt the user to enter a cousr number and print the information from that course
            cout << "Enter the course number: ";
            try {
                cin >> courseNum;
                if (cin.fail()) {
                    throw runtime_error("Invalid input.");
                }

            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;// Print error mesage
                cin.clear();// Clear the error 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// get rid of the invalid input
            }

           
            cout << endl;
            // Convert the course number to uppercase for case-insensitive comparison
            transform(courseNum.begin(), courseNum.end(), courseNum.begin(), ::toupper);

            PrintCourseInformation(courses, courseNum);
            break;

        case 9:
            // Clean up dynamically allocated memory
            CleanupCourses(courses);
            cout << "Thank you for using the course planner!";
            break;

        default:
            //Show an erroe message for invalid choices
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 9);// Continue the loop until the user chooses 9

    return 0;// return with success code 
}
