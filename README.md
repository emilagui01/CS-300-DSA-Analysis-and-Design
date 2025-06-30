# CS-300-DSA-Analysis-and-Design

## What was the problem you were solving in the projects for this course?
The main problem tackled was building an efficient course planning tool that allows users to load course data, sort it, and retrieve specific course details, including prerequisites. The goal was to analyze and compare different data structures to determine the most effective way to manage and access course information.

## How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by first implementing the program using a simple vector, then evaluating performance and complexity compared to hash tables and binary search trees. Understanding data structures was critical because each one provides unique trade-offs in terms of access time, sorting capability, and memory usage. This understanding allowed me to make informed decisions about how to structure data for both performance and maintainability.

## How did you overcome any roadblocks you encountered while going through the activities or project?
One challenge I faced was ensuring that courses were printed in alphanumeric order efficiently. Initially, using a vector required sorting the list manually after loading, which added computational overhead. I overcame this by experimenting with alternative structures, like a binary search tree, which naturally maintains order. Debugging input parsing and handling invalid user input also helped solidify error-handling techniques.

## How has your work on this project expanded your approach to designing software and developing programs?
Working on this project taught me the importance of choosing the right data structure early in the design process. It also emphasized planning functions and their responsibilities clearly before diving into code. I now approach software design with a stronger emphasis on modularity, separating concerns like data loading, user interaction, and course searching into distinct, testable components.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
This project improved my coding discipline by encouraging consistent naming conventions, clear control flow, and well-structured logic. I now better appreciate the role of documentation and inline comments in making code understandable to others (and to my future self). Writing maintainable and adaptable code became a priority as I realized the value of scalability and readability for long-term project success.
