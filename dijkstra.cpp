/*
 * Project Name: Dijkstra's Single Source Algorithm C++ Implementation
 * Author : The Alex Camejo
 * Last Modified: May 8th, 2014 2:31 PM EST
 * Description: A simple implementation of Dijkstra's Single Source Algorithm written in C++.
 *              Dijkstra's SS Algorithm is a basic shortest path algorithm taught in introductory algorithm and data structures classes
 *              that finds the shortest path between a single source vertex and all remaining vertices. This implementation is done inside a spanning tree
 *              and using an adjaceny matrix (as opposed to a Fibonacci heap priority queue.
 */ 



#ifndef _DIJKSTRASINGLESOURCE_CPP_
#define _DIJKSTRASINGLESOURCE_CPP_
#include <iostream>
#include <fstream>


/**************HELPER FUNCTION PROTOTYPES **************/
int dijkstraFindClosestVertex(bool visited[] , int n , int distanceFromSource[]);        //Finds closest vertex to param @n
void dijkstraPrint(int v , int predecessor[] , int src);                                 //Helps print output
void dijkstraPrintOutput(int distanceFromSource[] , int src, int predecessor[] , int n);         //Prints output of paths and weights



void dijkstraSingleSource(){

/******** From-File Initialization ********/

std::ifstream infile;

int src;    //source vertex
int n;      //Number of nodes
int e;      //Number of edges

infile.open("inputFile.txt");

infile >> src;
infile >> n;
infile >> e;

 int adjacencyMatrix[n][n];                 //first array = Columns. Second array = rows;
 int tempRow;
 int tempCol;
 int tempWeight;
 
 for(int i = 0 ; i < e  ; i++){             //Adjacency Matrix/ Graph initialized
   infile >> tempRow;
   infile >> tempCol;
   infile >> tempWeight;
   
   adjacencyMatrix[tempRow][tempCol] = tempWeight;   //Set weight
 }
 infile.close();                            //Done with inputFile.txt

 


/********* Preparing for Algorithm ************/

 int predecessor[n];
 int distFromSource[n];
 bool visited[n];

                 //Initializing predecessor, distFromSource, and visited

 for(int  i = 1 ; i < n+1 ; i++){
   predecessor[i] = -1;            //No nodes have a predecessor
   distFromSource[i] = 999;        //All distances from source set to very large number
                                   //Can be changed if algorithm needed for tree with weights > 999
   visited[i] = false;             //No nodes visited yet
 }

distFromSource[src] = 0;           // Distance from the source to itself is 0


 /*********** Dijkstra's Single Source Algorithm ***********/

 int closestNotVisitedVertex;
 int smallestWeight = 999;        //Begins as large number
 int count = 0;
 
 while(count < n){
   closestNotVisitedVertex  = dijkstraFindClosestVertex(visited , n , distFromSource); //Find the closest unvisted vertex
   visited[closestNotVisitedVertex] = true;                                            //Mark that it was visiited
   for(int i = 1 ; i < n+1 ; i++){
     if((adjacencyMatrix[closestNotVisitedVertex][i] > 0 ) && (!visited[i])){         //If there is a weight connecting the closest not Visited node
                                                                                      //And there it hasn't been visited yet

       if(distFromSource[i] > distFromSource[closestNotVisitedVertex] + adjacencyMatrix[closestNotVisitedVertex][i]){   //If the DistFrom the source on this
                                                                                                                        //on vertex i is less on a different
	                                                                                                                //path that the current one it's a
	                                                                                                                //part of...
	 
	 distFromSource[i] = distFromSource[closestNotVisitedVertex] + adjacencyMatrix[closestNotVisitedVertex][i];     //Update distance from source of i w/
	                                                                                                                //with distance from new path

	 predecessor[i] = closestNotVisitedVertex;                                                                      //Update predecessor on this new path
       }
     }
   }
   count++;
 }

 
 dijkstraPrintOutput(distFromSource , src, predecessor, n);  //Print output
 return ;
}




/****************HELPER FUNCTION IMPLEMENTATIONS******************/

/*
 * @Param visited[]:  a boolean array that keeps track of whether or not a vertex (represented by as an index) has been visited (true) or not (false)
 * @Param n : Simply the number of vertices in the graph/tree
 * @Param distanceFromSource[] : An integer array whose values are the total distance a vertex (represented as an index) is from the source
 *
 */


int dijkstraFindClosestVertex(bool visited[] ,int n , int distanceFromSource[] ){
  int closestVertex;
  int minWeight = 999;  //Starts as large number
  for(int i = 1 ; i < n+1 ; i++){
    if((!visited[i]) && (minWeight >= distanceFromSource[i])){   //If not visit and lower than current minWeight
      minWeight = distanceFromSource[i];                         //Make this vertex the new closest and just minWeight.
      closestVertex = i;
    }
  }
    return closestVertex;
}


void dijkstraPrint(int v , int predecessor[], int src){
  if(v == src){
    std::cout << v;
    return;
  }

  else{
    
    dijkstraPrint(predecessor[v] , predecessor ,src);
    std::cout << " -> " << v;
  }
  return;
}

void dijkstraPrintOutput(int distanceFromSource[] , int src , int predecessor[] , int n){
  for(int i = 1 ; i < n+1  ; i++){
    std::cout <<  distanceFromSource[i] <<": ";
    if(i == src){
 
      std::cout << src << " -> " << src ;
      std::cout << std::endl;
    }
    else{
      dijkstraPrint(i , predecessor , src);
      std::cout << std::endl;
      
    }
   
  }
  
  return;
}

#endif // _DIJKSTRASINGLESOURCE_CPP_
