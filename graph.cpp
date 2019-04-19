#include <iostream>
#include <string>
#include "graph.hpp"

#define INFI 1000000

/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph
Graph::Graph(int vertices, int routes)
{

  // Initialize numCities and numRoutes 
  numCities = vertices;
  numRoutes = routes;
  
  // Graph is represented as an adjacency list
  cout << "Vertices: " << numCities << endl;

}


// Returns the discovery time of vertex
int disc(int vertex)
{
  return 0;
}

// Returns the earliest discovery time of a node that can be reached to from vertex
int evaFun(int vertex)
{
  return 0;
}

bool isSeparationEdge(int vertex1, int vertex2)
{
  return evaFun(vertex1) > disc(vertex2);
}

// Performs an iterative depth first search
// Used to find separation edges
void dfs(int vertex)
{

}
