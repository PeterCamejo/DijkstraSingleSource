********** INPUTFILE.TXT FORMAT **************

Line 1 : Source node number
Line 2 : Number of nodes followed by a single whitespace followed by number of edges
Remaining lines: For each edge, list the number of the source node, whitespace, the number of second node, whitespace, and the edge weight.

For example, for a an edge starting from node 1 and ending at node 2 with a weight of 10, the format would be:

1 2 10

So for a digraph with 3 nodes numbered 1-3 (1 is source) and 3 edges ( 1 to 2, 2 to 3, and 3 to 1, with wieghts of 5, 10, 15 respectively), the inputFile.txt should look as follows:

1
3 3
1 2 5
2 3 10
3 1 15 




*********Does the program compile without errors?************

Yes

*********Does the program compile without warnings?*************

Yes

*********Does the program run without crashing?*****************

Yes

******Describe how you tested the program.************************

Algoritm was first done with given sample Inputfile by hand to determine what correct output should be. Through extensive research
on the algorithm and given psuedocode, a C++ implementation was actually fairly simple to implement. Code was then tested by creating various cases of input Text, doing them by hand, and comparing the written algorithms output to the by-hand output.

**********Describe the ways in which the program does not meet standard specifications.********************

Algorithm is implemented 100% correctly as far as it is suppose to be implemented when utilizing an adjancency
matrix as opposed to a Fibbonacci Heap. Furthermore,

***************Describe all known and suspected bugs.*************

N/A

****************Does the program run correctly?*******************

Yes.
