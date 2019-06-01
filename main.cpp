#include "myHeader.h"


/*****************************************************************************
 * AUTHOR:       : Jose Cardenas
 * STUDENT ID    : 1026944
 * ASSIGNMENT 12 : Dijkstra
 * CLASS:        : CS1D
 * TIME:         : Mondays & Wednesday: 5:00 - 7:20PM
 * DUE DATE:     : 11/28/18
 * ---------------------------------------------------------------------------
 * PROGRAM DESCRIPTION:
 *  Implementation of Dijkstra’s algorithm to find the shortest distance from
 *  Atlanta to the remaining vertices of the graph. The paths (edges) and corresponding
 *  distance (weights)  are identified.
 ***************************************************************************/

int main()
{
	/************************************************************************************
	 * For Output purposes
	 * ----------------------------------------------------------------------------------
	 * Lab or Assignment, Author, Id of Author, Assignment #, Assignment Name, Due Date
	 ***********************************************************************************/
	assignmentDescription("___","Jose Cardenas",1026944 ,12,"Dijkstras Algorithm","11/28/18");


	Graph graph;

	graph.addVertex("Boston");
	graph.addVertex("New York");
	graph.addVertex("Atlanta");
	graph.addVertex("Miami");
	graph.addVertex("Chicago");
	graph.addVertex("Kansas City");
	graph.addVertex("Dallas");
	graph.addVertex("Houston");
	graph.addVertex("Denver");
	graph.addVertex("Seattle");
	graph.addVertex("San Francisco");
	graph.addVertex("Los Angeles");

	//Edges of Boston
	graph.addEdges(0, 214,  1);
	graph.addEdges(0, 983,  4);

	//Edges of New York
	graph.addEdges(1, 214, 0);
	graph.addEdges(1, 888, 2);
	graph.addEdges(1, 787, 4);
	graph.addEdges(1, 1260, 5);

	//Edges of Atlanta
	graph.addEdges(2, 888, 1);
	graph.addEdges(2, 661, 3);
	graph.addEdges(2, 864, 5);
	graph.addEdges(2, 781, 6);
	graph.addEdges(2, 810, 7);

	//Edges of Miami
	graph.addEdges(3, 661, 2);
	graph.addEdges(3, 1187, 7);

	//Edges of Chicago
	graph.addEdges(4, 983, 0);
	graph.addEdges(4, 787, 1);
	graph.addEdges(4, 533, 5);
	graph.addEdges(4, 1003, 8);
	graph.addEdges(4, 2097, 9);

	//Edges of Kansas City
	graph.addEdges(5, 1260, 1);
	graph.addEdges(5, 864, 2);
	graph.addEdges(5, 533, 4);
	graph.addEdges(5, 496, 6);
	graph.addEdges(5, 599, 8);
	graph.addEdges(5, 1663, 11);

	//Edges of Dallas
	graph.addEdges(6, 781, 2);
	graph.addEdges(6, 496, 5);
	graph.addEdges(6, 239, 7);
	graph.addEdges(6, 1435, 11);

	//Edges of Houston
	graph.addEdges(7, 810, 2);
	graph.addEdges(7, 1187, 3);
	graph.addEdges(7, 239, 6);

	//Edges of Denver
	graph.addEdges(8, 1003, 4);
	graph.addEdges(8, 599, 5);
	graph.addEdges(8, 1331, 9);
	graph.addEdges(8, 1267, 10);
	graph.addEdges(8, 1015, 11);

	//Edges of Seattle
	graph.addEdges(9, 2097, 4);
	graph.addEdges(9, 1331, 8);
	graph.addEdges(9, 807, 11);

	//Edges of San Francisco
	graph.addEdges(10, 1267, 8);
	graph.addEdges(10, 807, 9);
	graph.addEdges(10, 381, 11);

	//Edges of Los Angeles
	graph.addEdges(11, 1663, 5);
	graph.addEdges(11, 1435, 6);
	graph.addEdges(11, 1015, 8);
	graph.addEdges(11, 381, 10);

	// Dijkstra’s algorithm
	graph.dijkstrasShortestPath(2);

	graph.printDijkstrasPath( 2,  2);  // Atlanta to Atlanta
	graph.printDijkstrasPath( 2,  3);  // Atlanta to Miami
	graph.printDijkstrasPath( 2,  6);  // Atlanta to Dallas
	graph.printDijkstrasPath( 2,  7);  // Atlanta to Houston
	graph.printDijkstrasPath( 2,  5);  // Atlanta to Kansas City
	graph.printDijkstrasPath( 2,  1);  // Atlanta to New York
	graph.printDijkstrasPath( 2,  0);  // Atlanta to Boston
	graph.printDijkstrasPath( 2,  4);  // Atlanta to Chicago
	graph.printDijkstrasPath( 2,  8);  // Atlanta to Denver
	graph.printDijkstrasPath( 2,  11); // Atlanta to Los Angeles
	graph.printDijkstrasPath( 2,  10); // Atlanta to San francisco
	graph.printDijkstrasPath( 2,  9);  // Atlanta to Seattle

	return 0;
}
