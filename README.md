# CS 2240 Section OL1, Project 2

NOTE: This specification and rubric are for CS 2240 OL1 only (Cafiero). If you are in a different section, you're reading the wrong file.

## Overview
For this project, you will:
* implement a queue class based on the Node class presented in lecture (supplied),
* analyze the complexity of stacks and queues and express this in asymptotic (Big O) notation,
* test your queue on three different object types: integers, strings, and objects of your own custom class created in the previous project,
* demonstrate enqueuing, dequeueing, finding, and printing,
* use heap memory for object storage, and
* ensure your queue class has no memory leaks

## Requirements

### Queue class: `Queue.h`
* Recall that a queue is a FIFO data structure—first in, first out.
* Your queue class should have an appropriate constructor and destructor. Node objects should be stored on the heap. The destructor must ensure that objects allocated on the heap are correctly de-allocated to prevent memory leaks.
* Your queue class should have the following methods in addition to the above:
  * `enqueue()` --- to add a new Node to the back of the queue; this should take an object of the appropriate type as a parameter
  * `dequeue()` --- to fetch the object from the front of the queue and remove it from the queue; this should return an object of the appropriate type; this method requires no parameters
  * `find()` --- which will check to see if a given object is in the queue; hint: you will need to use the overridden `==` for this to work with your custom class; this method will take an object of the appropriate type as a parameter and return a boolean true if the object is in the queue and false otherwise
  * `isEmpty()` --- which will check to see if your queue is empty; this will return boolean true if empty; false otherwise
  * `print()` --- to print your queue; this method requires no parameters

### Driver: `main.cpp`
* Create three queues: one queue of integers, one queue of strings, and one queue of your custom data type (from previous assignment).
* Demonstrate that your queue methods work correctly by calling the methods on each of the objects and making assertions and printing to the console when appropriate
* Perform the following test:
  * Create a queue and a stack, both to hold objects of your custom type.
  * Read your data from file into a vector (as you did in the previous assignment).
  * Print the first ten objects from your vector and enqueue them.
  * Dequeue the ten objects and as you do so push them onto the stack.
  * Pop all the items off the stack and print them as you do so.
  * What is the order of the objects before and after adding them to the queue and to the stack?
  * When and why did this order change?
  * Include discussion in your report.

## Design
Consider the following questions:
* Do node links point from the front of the queue to the back? Or from the back to the front?
* Which nodes in the queue do you need to keep track of? Is there still a top node pointer?
* How can you use the `isEmpty()` method to simplify things in `main.cpp`?
* How will you make sure there are no memory leaks?
* How will you print objects in `main.cpp`? When will you use your `print()` method and when does it make sense to print objects individually?

## Testing
Print stuff out! Write tests! Make assertions!

## Report
You must write a report about your project. 
* Indicate how you know your functions work correctly.
* Do node links point from the front of the queue to the back? Or from the back to the front?
* Explain what happened when you dequeued from the queue, pushed onto the stack, and popped
from the stack. Again: when and why did this order change?
* Explain how you prevent memory leaks.

## What to submit
* Submit via GitHub/Gradescope as with project part 1.
* Your repo should be named `project_2-[your NetID]`
* The minimum set of files needed to compile and run your program should be supplied, along with your data file and report.
  * `.gitignore`,
  * `CMakeLists.txt`,
  * `main.cpp`,
  * `Node.h` (as supplied),
  * `README.md`,
  * `Queue.h`
  * `Stack.h` (as supplied),
  * header for your custom class, and,
  * your data file.
* Your report should be in Markdown format --- just modify this `README.md`! Report should include 
  * information about your data set (you will be assigned a different grader for this project, so you should provide explanation);
  * the time complexities of each method in the `Stack` and `Queue` classes;
  * justification of your use of pointers in the queue (_i.e.,_ the direction of arrows between the nodes) as it relates to the complexity of the enqueue and dequeue methods; and
  * An explanation of when and why the ten objects in the `main` function changed their order.
* You should include your data file, so we can run your program!
* Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## What not to submit
* Do not submit reports in DOCX or other word-processing format.
* Do not submit auxiliary files created by your IDE, build artifacts, executables, or other cruft. Note that IDEs can produce many auxiliary files---do not submit these. Use `.gitignore`.

## Code
* Follow the style guide (on Brightspace).
* Use C++ 17 Standard.
* Use of `<bits/stdc++.h>` is non-standard, and is strictly prohibited.
* We will compile using CLion, or if that fails we may try compiling from the command line. However, it is in your best interest to stick to the basics and make sure your code complies and runs without any fuss.
* Note: Any code that was not authored by yourself or an instructor _must be cited in your report_. This includes the use of any concepts not taught in lecture or presented on Brightspace.

## Grading / rubric

| points | item                                                                                                                                                                                                                 |
|--------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 5      | You submitted all files in the correct formats. You did not submit any files that were not requested.                                                                                                                |
| 10     | Program compiles without error and runs without error.                                                                                                                                                               |
| 10     | Your code is readable, follows good code style and standards for this class, uses consistent naming, and has comments where appropriate. Your name must appear in a comment or doc block atop each source code file. |
| 20     | Your queue class is correctly implemented, includes all required methods, and satisfies all stated requirements.                                                                                                    |
| 15     | You create three queue objects of different types, `int`, `std::string`, and your custom type.                                                                                                                       |
| 20     | You test `enqueue()`, `dequeue()`, `push()`, `pop()`, `print()`, with ten objects as described above, with correct result.                                                                                           |
| 10     | You test / exercise your code to demonstrate that everything works correctly.                                                                                                                                        |
| 20     | Your report satisfies all requirements, answers all questions including questions about time complexity of methods, and is well-written.                                                                             |
| 110    | TOTAL                                                                                                                                                                                                                |


**NOTE: If you were asked to revise your class or the function which reads data from a source file in comments on Project 1 up to 20 points may be deducted from your score on project 2 if you have failed to correct deficiencies.**
