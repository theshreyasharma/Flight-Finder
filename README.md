## CS 225 Final Project 
The goal of this project is to detect the shortest flight path from a start point to an end point with certain restrictions regarding the maximum distance that can be traveled in one path between two airports to create situations in which layover is needed. To achieve this goal, we will be incorporating BFS traversal, Dijkstra's Algorithm, and Landmark Path Algorithm.  

## Installation
Do a clone from the master branch to obtain the code base.

## Build and Run
In order to build and run our executable, run the command `make final` followed by `./final`. Then, check the files `bfs.txt`, `landmarkpath.txt`, and `dijkstra.txt` to view the output of the traversal and both algorithms. If you would like to change the origin and/or destination of any traversal or algorithm, you should replace our sample input airports with your own in `main.cpp` then run as indicated. Furthemore, running `make test` then `./test` will produce the output of our sample unit tests. 

## Contributors
Siddhartha Adatrao, Saket Vissapragada, Sruthi Kilari, Shreya Sharma

## Credits
We utilized the [Open Flights](https://openflights.org/data.html) dataset for this project. The Graph class, Edge class,Random class, as well as the cs225 folder were taken from lab_ml.
The DijkstraPair and Compare struct in `dijkstras.cpp` were derived from [Geeks for Geeks](https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/).
