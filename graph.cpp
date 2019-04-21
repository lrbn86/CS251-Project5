#include <iostream>
#include <string>
#include <vector>
//#include <set> // Used to map integers. Used to remove duplicates
#include <list> // Linked List
#include <algorithm> // Used for sorting routine, finding elements
#include "graph.hpp"

#define INFI 1000000

/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

/*
  Graph is represented as an adjacency list.
  The adjacency list will be a vector of linked lists.
  The Linked List will contain the neighbors of the nodes at the vector[i].
*/

// Map strings to integers
vector<string> nodes;

vector< list<int> > adjList; // The Adjacency List Data Structure

static int idx = 0; // Helps with organizing where to put the vertices in the adjList

// Constructor for Graph
Graph::Graph(int vertices, int routes)
{
  // Initialize numCities and numRoutes 
  numCities = vertices;
  numRoutes = routes;
  // Graph is represented as an adjacency list
  // Initialize the adjacency list to have empty lists
  for (int i = 0; i < numCities; i++)
  {
    list<int> emptyList;
    adjList.push_back(emptyList);
  }
}

// Adds a route to the graph
void Graph::addRoute(string source, string destination, string ticketPrice)
{
  // Check whether src and dest vertices are already in the nodes vector
  bool sourceVertexExists = std::find(nodes.begin(), nodes.end(), source) != nodes.end();
  bool destinationVertexExists = std::find(nodes.begin(), nodes.end(), destination) != nodes.end();

  // These checks prevents the nodes vector from containing duplicates
  // As well as assigning an integer to a string
  if (!sourceVertexExists)
  {
    nodes.push_back(source);
  }

  if (!destinationVertexExists)
  {
    nodes.push_back(destination);
  }

  // The routes are two-way. If there's a route between A and B, then there's a route between B and A.
  // However, the ticketPrice remains the same.
  int indexOfSource = getIndexOf(source);
  int indexOfDestination = getIndexOf(destination);

  adjList[indexOfSource].push_back(indexOfDestination);
  adjList[indexOfDestination].push_back(indexOfSource);
}

// Given a string, this will return the index or the integer assigned to this string via vector.
int Graph::getIndexOf(string s)
{
  int indexOfString;
  for (int i = 0; i < nodes.size(); i++)
  {
    if (s == nodes[i])
    {
      indexOfString = i;
      break;
    }
  }
  return indexOfString;
}

// Helper function for checking what's inside the adjList
void Graph::getRoutes()
{
  for (int i = 0; i < adjList.size(); i++)
  {
    cout << nodes[i] << " has the following neighbors: ";
    list<int>::iterator it;
    for (it = adjList[i].begin(); it != adjList[i].end(); it++)
    {
      cout << nodes[(*it)] << " ";
    }
    cout << endl;
  }
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
