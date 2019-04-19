#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "graph.hpp"

using namespace std;

// TODO: Should we make the reading routes into a single function for all three parts to use?

// Part 1 : Find the connected components and the bridge
void part1(ifstream &inputfile, ofstream &outputfile)
{

  /*
    The input is:
      1. Integer "1" followed by two integers
          n = number of places
          m = number or routes
      2. m lines in the format <source> <destination> <cost>
  */

  int numberOfPlaces, numberOfRoutes;
  inputfile >> numberOfPlaces >> numberOfRoutes;
  inputfile.ignore(); // Ignore newline
  
  // Construct Graph
  Graph g (numberOfPlaces, numberOfRoutes);
  
  // Add routes to graph
  for (int i = 0; i < numberOfRoutes; i++)
  {
    string routeInfo;
    getline(inputfile, routeInfo); 
    string source, destination, ticketPrice;
    istringstream ss(routeInfo);
    getline(ss, source, ' ');
    getline(ss, destination, ' ');
    getline(ss, ticketPrice, ' '); // Note: ticketPrice is a floating point, not a string
    outputfile << "The cost from " << source << " to " << destination << " is: " << ticketPrice << endl;
    //outputfile << "Origin: " << source << endl;
    //outputfile << "Destination: " << destination << endl;
    //outputfile << "Ticket Price: " << ticketPrice << endl;
  }

  /*
    The output should be:
      <Number of connected components in the graph>, integer
      <Number of separation edges>, integer
      <Separation edges listed in alphabetical order> (use std:sort)

      There should not be any newline at end of output file.
  */
}

// Part 2 :  Find a ticket using Dijkstra
void part2(ifstream &inputfile, ofstream &outputfile)
{
  // Assume that there is only one cheapest route between two different cities.
  
  /*
    The input is:
      1. Integer "2" followed by two integers
          n = number of places
          m = number of routes
      2. m lines in the format <source> <destination> <cost>
      3. 1 or more lines containing ticket queries in the form <source> <destination>
      4. A line containing "END".
  */

  int numberOfPlaces, numberOfRoutes;
  inputfile >> numberOfPlaces >> numberOfRoutes;
  inputfile.ignore(); // Ignore newline

  // Construct Graph
  Graph g (numberOfPlaces, numberOfRoutes);

  // Add routes to graph
  for (int i = 0; i < numberOfRoutes; i++)
  {
    string routeInfo;
    getline(inputfile, routeInfo);
    string source, destination, ticketPrice;
    istringstream ss(routeInfo);
    getline(ss, source, ' ');
    getline(ss, destination, ' ');
    getline(ss, ticketPrice, ' '); // Note: ticketPrice is a floating point, not a string
    outputfile << "The cost from " << source << " to " << destination << " is: " << ticketPrice << endl;
  }

  string query;
  outputfile << "Queries:" << endl;
  do
  {
    getline(inputfile, query);
    if (query == "END") break;
    outputfile << query << endl;
  } while (query != "END");

  /*
    The output should be:
      For each query, output <source> <intermediate noes> <destination> <total cost 2 decimal places>
      If destination is not possible, output "not possible"

      There should not be any newline at end of output file.
  */
}

// Part 3 :Try to do a tour of all cities
void part3(ifstream &inputfile, ofstream &outputfile)
{

  /*
    The input is:
      1. Integer "3" followed by two integers
          n = number of places
          m = number of routes
      2. m lines in the format <source> <destination> <cost>
      3. One line containing the place that will be the root of MST (Minimum Spanning Tree)
  */

  int numberOfPlaces, numberOfRoutes;
  inputfile >> numberOfPlaces >> numberOfRoutes;
  inputfile.ignore(); // Ignore newline

  // Construct Graph
  Graph g (numberOfPlaces, numberOfRoutes);

  // Add routes to graph
  for (int i = 0; i < numberOfRoutes; i++)
  {
    string routeInfo;
    getline(inputfile, routeInfo);
    string source, destination, ticketPrice;
    istringstream ss(routeInfo);
    getline(ss, source, ' ');
    getline(ss, destination, ' ');
    getline(ss, ticketPrice, ' '); // Note: ticketPrice is a floating point, not a string
    outputfile << "The cost from " << source << " to " << destination << " is: " << ticketPrice << endl;
  }

  string rootOfMST;
  getline(inputfile, rootOfMST);

  outputfile << "The root of MST is: " << rootOfMST << endl;

  /*
    The output should be:
      The Eulerian traversal according to the given pseudocode
      If it is not possible to visit all cities, output "not possible"

      There should not be any newline at end of output file.
  */
}

int main(int argc, char *argv[])
{
	//Read in the test case
	ifstream inputfile;
	ofstream outputfile;

	if (argc == 3)
	{
		inputfile.open(argv[1]);
		outputfile.open(argv[2]);
	}
	else
	{
		cout << "Not enough arguments" << endl;
	}

	string str;

	getline(inputfile, str);
	int part;
	stringstream convert(str);
	convert >> part;

	if (part == 1)
		part1(inputfile, outputfile);
	else if (part == 2)
		part2(inputfile, outputfile);
	else if (part == 3)
		part3(inputfile, outputfile);

	return 0;
}
