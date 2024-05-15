# CourseManager

CourseManager is a simple command-line program written in C++ for managing course information. It allows users to load data from a file, display course information alphabetically, and retrieve details about specific courses.

## Features

- Load course data from a file.
- Display course information in alphabetical order.
- Retrieve information about a specific course.
- Error handling for invalid user inputs.

## Getting Started

### Prerequisites

To run CourseManager, you need:

- C++ compiler (supporting C++11 or later)
- [Git](https://git-scm.com/) (for cloning the repository)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/RoyceZerimar/CourseManager.git
   
## Usage

1. **Navigate to the project directory:**

    ```bash
    cd CoursePlanner
    ```

2. **Compile the code:**

    ```bash
    g++ -o course_planner course_planner.cpp course_functions.cpp -std=c++11
    ```

3. **Place the file `course_data.txt` containing course data in the project directory.**

4. **Run the compiled executable:**

    ```bash
    ./course_planner course_data.txt
    ```

    Replace `course_data.txt` with the name of the file containing course data.

5. **Follow the on-screen menu to perform desired actions:**

    - Option 1: Load Data Structure
    - Option 2: Print Course information in alphabetical order
    - Option 3: Print information for a specific course
    - Option 9: Exit
