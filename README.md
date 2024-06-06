# Evidence-4

**Context**
The problem that was chosen for this is the following one:

<img width="790" alt="image" src="https://github.com/produce101levi/Evidence-4/assets/117374505/4875e372-0378-47ba-8112-53c15efff4d1">

This problem can be found in this link: https://codeforces.com/problemset/problem/1970/C1

Basically, what is needed for this problem to be solved is to create a program that, with an input that indicates the number of nodes in the tree, another one that explains how the nodes are connected to each other, and a final one that indicates which node the game begins on, determines the winner of the game. 

The reason this problem is useful to demonstrate a functional paradigm is because it requires working with trees. Which means a solution to this problem would be using a 
Depth First Search algorithm, which requires functions. 

A Depth First Search algorithm is also recursive, which is a key element in a functional programming paradigm. 


**Diagram**

![0](https://github.com/produce101levi/Evidence-4/assets/117374505/e1b69511-2af1-4086-8bc3-89f3217250a5)

The functional programming paradigm is used because the functions in the program are recursive and the solution is based on functions. 

While C++ does not suppport pure functions inherently, the program's solution has been thought of in such a way that the least amount of external variables and states possible are modififed. However, because inmutability is not present in the code, we cannot say that the functions are pure.

**Time Complexity**

The time complexity for this solution is O(n) in the worst case.

The function for the DFS is recursive. It calls itself over and over again until it reaches the end of the tree, therefore the function runs n times. 

So its complexity is O(n). 

Since the function to determine the winner calls the DFS function as well, this function has a complexity of O(n) as well. 

The complexity for the function that's in charge of printing the tree is O(n). The outer for loop iterates over each node of the tree n times, and for each time the outer loop does this, the inner loop iterates over the neighbors of each node an equal amount of times because it's a for each loop. Therefore, the complexity is O(n).

There are no other components, lines or functions in the code that have an equal or higher complexity than O(n), so the time complexity for this solution is O(n).

**Why is this the best solution?**

A functional programming paradigm is more fitting for this problem because the problem is inherently sequential and it requires a recursive function like depthFirstSearch(). 

In any case, concurrent programming would be used in order to run the print_tree() function and depthFirstSearch() at the same time. Since print_tree() is really an optional function (because it's not a requirement to solve the problem), concurrent programming wouldn't be relevant and therefore not a better option than functional programming.

Other paradigms such as Object-Oriented programming or parallel programming would be more complicated to code and understand. It'd be unnecessary to put an additional amount of effort and understanding into this solution; especially considering the fact that factors such as the time complexity would remain the same.


**Tests**

These are the tests that were implemented for the model. 

The first line is the input for the values of n and t. 
The next n-1 lines are the nodes as they are connected. In the case of test #1, node 2 is connected to node 3 and node 3 is connected to node 1.
The last line is the starting node.

#1

Input:

3  1

2  3

3  1

3

Output:

Ron

#2

Input:

5  1

1  2

2  3

3  4

4  5

5

Output:

Hermione



**References**

Stungeye. (N.D.). _Arrays_. Retrieved from https://stungeye.github.io/Programming-1-Notes/docs/06-collections/02-arrays.html

GeeksForGeeks. (2024). _Depth First Search or DFS for a Graph_. Retrieved from https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

GeeksForGeeks. (2022). _Functional Programming Paradigm_. Retrieved from https://www.geeksforgeeks.org/functional-programming-paradigm/
