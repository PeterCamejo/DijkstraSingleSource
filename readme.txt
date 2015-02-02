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
