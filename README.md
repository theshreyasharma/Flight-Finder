## CS 225 Final Project 
The goal of this project is to detect the shortest flight path from a start point to an end point. To accomplish this, we created a randomized graph of airport nodes that have the distances as edge weights. To compute these edge weights, we used the [Haversine formula](https://en.wikipedia.org/wiki/Haversine_formula). Additionally, we were able to detect the shortest flight path between two points when given a point that must be visited in between. Our project incorporated Breadth-first search (BFS), Dijkstra's Algorithm, and the Landmark path algorithm.

## Installation
Clone this repository into your desired location `git clone https://github-dev.cs.illinois.edu/cs225-fa20/adatrao2-saketv2-skilari2-ssharm90.git`

## Build and Run
In order to build and run our executable, run the command `make final` followed by `./final`. Note: Running `make final` and `./final` will run using default airports that we have determined. For further use, change the airports that are being used by picking an airport in the `openflightsformatted.csv` and replace under the comment section for which algorithm to run. Then, check the files `bfs.txt`, `landmarkpath.txt`, and `dijkstra.txt` to view the output of the traversal and both algorithms. If you would like to change the origin and/or destination of any traversal or algorithm, you should replace our sample input airports with your own in `main.cpp` then run as indicated. Furthemore, running `make test` then `./test` will produce the output of our sample unit tests.

## Contributors
Siddhartha Adatrao, Saket Vissapragada, Sruthi Kilari, Shreya Sharma

## Credits
We utilized the [Open Flights](https://openflights.org/data.html) dataset for this project. The Graph class, Edge class, Random class, as well as the cs225 folder were taken from lab_ml.
The DijkstraPair and Compare struct in `dijkstras.cpp` were derived from [Geeks for Geeks](https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/).
