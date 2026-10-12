# Course Planner: Advising Assistance Program (CS-300)

> **This is the original version, built for CS-300 Data Structures and Algorithms at Southern New Hampshire University (June 2025).**
> I later enhanced this program for my CS-499 capstone, adding an `unordered_map` hash table for faster course lookup, CSV row validation, duplicate detection and safer menu input.
> See the enhanced version in my **[Capstone ePortfolio](https://emilagui01.github.io/capstone/algorithms.html)**.

A C++ console program for a university advising office. It loads course data from a CSV file, prints every course in alphanumeric order, and looks up any course to show its title and prerequisites.

## Files

| File | Purpose |
|---|---|
| `CoursePlanner.cpp` | Program source code (Project Two) |
| `CS 300 ABCU_Advising_Program_Input.csv` | Course data the program loads |
| `CS 300 Project One.docx` | Project One: pseudocode and runtime analysis for a vector, a hash table and a binary search tree |

## Running it

Open the folder in Visual Studio 2022 with the C++ desktop development workload, add `CoursePlanner.cpp` to a new console project, keep the CSV file in the project folder, and run with **Ctrl + F5**. Or compile from a terminal:

```
g++ -o CoursePlanner CoursePlanner.cpp
./CoursePlanner
```

Choose **1** and press Enter to load the default CSV file, then **2** to print the course list or **3** to look up a course.

## Sample output

```
What would you like to do? 2
Here is a sample schedule:
CSCI100, Introduction to Computer Science
CSCI101, Introduction to Programming in C++
CSCI200, Data Structures
CSCI300, Introduction to Algorithms
CSCI301, Advanced Programming in C++
CSCI350, Operating Systems
CSCI400, Large Software Development
MATH201, Discrete Mathematics

What would you like to do? 3
What course do you want to know about? csci400
CSCI400, Large Software Development
Prerequisites: CSCI301, CSCI350
```

## Data structure analysis (Project One)

Before writing the program, I compared three data structures for the advisor's three tasks: loading course data, printing a sorted course list and looking up a single course. The full pseudocode for each is in `CS 300 Project One.docx`.

### Cost of loading the course file

| Step | Vector | Hash table | Binary search tree |
|---|---|---|---|
| Read each line, split by commas, validate | n | n | n |
| Check or record prerequisites | n | n | n |
| Create the course object | n | n | n |
| Insert the course | n (append) | n (average O(1) each) | n log n (O(log n) each) |
| **Runtime** | **O(n)** | **O(n)** | **O(n log n) average, O(n²) if unbalanced** |

### Strengths and tradeoffs

| | Vector | Hash table | Binary search tree |
|---|---|---|---|
| Find one course | O(n), checks courses one by one | O(1) average | O(log n) when balanced |
| Print in order | Needs a sort, O(n log n) | Needs a sort, O(n log n) | In-order traversal, O(n) |
| Main drawback | Slow lookups as the list grows | Keeps no order | Can degrade if it becomes unbalanced |

### Recommendation from Project One

Based on this analysis, the binary search tree is the most suitable structure for this program. It supports fast retrieval, maintains order, and enables efficient sorting with in-order traversal without the need for additional operations. Given the importance of displaying courses in alphanumeric order and retrieving individual course details based on course number, the BST offers the best balance of efficiency and functionality among the three structures.

The final Project Two program in this repo uses a vector, sorting the list before printing. In my capstone I kept the vector for sorted output and added a hash table so single-course lookups no longer scan the whole list.

## Known limitations (fixed in the capstone)

This is the course version and is kept as it was submitted. These issues were found and fixed in the [enhanced capstone version](https://emilagui01.github.io/capstone/algorithms.html):

* Typing a letter at the menu makes the program print "0 is not a valid option" over and over.
* Courses with no prerequisites print an empty "Prerequisites:" line instead of "None", because of the trailing commas in the CSV.
* Loading the file a second time adds every course again as a duplicate.
* Searching or printing before loading the file gives no message telling the user to load the data first.
* Rows with missing fields are not checked before they are added.
* Finding a course checks the whole list one course at a time.

## Course reflection

### What was the problem you were solving in the projects for this course?
The main problem tackled was building an efficient course planning tool that allows users to load course data, sort it, and retrieve specific course details, including prerequisites. The goal was to analyze and compare different data structures to determine the most effective way to manage and access course information.

### How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by first implementing the program using a simple vector, then evaluating performance and complexity compared to hash tables and binary search trees. Understanding data structures was critical because each one provides unique trade-offs in terms of access time, sorting capability, and memory usage. This understanding allowed me to make informed decisions about how to structure data for both performance and maintainability.

### How did you overcome any roadblocks you encountered while going through the activities or project?
One challenge I faced was ensuring that courses were printed in alphanumeric order efficiently. Initially, using a vector required sorting the list manually after loading, which added computational overhead. I overcame this by experimenting with alternative structures, like a binary search tree, which naturally maintains order. Debugging input parsing and handling invalid user input also helped solidify error-handling techniques.

### How has your work on this project expanded your approach to designing software and developing programs?
Working on this project taught me the importance of choosing the right data structure early in the design process. It also emphasized planning functions and their responsibilities clearly before diving into code. I now approach software design with a stronger emphasis on modularity, separating concerns like data loading, user interaction, and course searching into distinct, testable components.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
This project improved my coding discipline by encouraging consistent naming conventions, clear control flow, and well-structured logic. I now better appreciate the role of documentation and inline comments in making code understandable to others (and to my future self). Writing maintainable and adaptable code became a priority as I realized the value of scalability and readability for long-term project success.
