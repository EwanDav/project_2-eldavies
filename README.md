# CS 2240 Section OL1, Project 2
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


REPORT========================================

My dataset is simply the top 1000 songs from 1920-2010. The fields it uses are:
id: the songs id on the dataset
trackName: the songs name
artist: the songs artist
album: the album it was a part of, if any
decade: the decade it was creted

Time Complexities:
Queue: 
-constructor = O(1)
-deconstructor = O(n)
-isEmpty = O(1)
-enqueue = O(1)
-dequeue = O(1)
-find = O(n)
-print = O(n)

Stack:
-constructor = O(1)
-deconstructor = O(n)
-push = O(1)
-pop = O(1)
-find = O(n)
-isEmpty = O(1)
-print = O(n)

WHY DO WE USE POINTERS?
In this case the use of pointers lets us increase and decrease the size of the queue without wasting memory. It also lets
us set the time complexities of enqueue and dequeue to O(1) because we have pointers that acess the front and rear of the 
queue directly. This means we dont need to iterate through the queue to add a new node, meaning we dont use any while loops, 
meanign the complexity isn't O(n) its O(1). 

The objects in the main function swapped order simply beciase queues work on a FIFO basis and stacks work on a LIFO basis.
Each takes from a different end meaning the order they are acessed is reversed. 



