#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

typedef priority_queue < pair<int,int>,
						 vector< pair<int,int> >,
						 greater< pair<int,int> > > pri_que;

// composite data type declaration
struct vertex
{
	bool visited;
	string cityName;  			     // name of the city
	int knownDistance;               // distance from starting pointing
	int previousVertex;  			 // previous vertex with the least mileage
	vector< pair< int, int> >  edge; // edge of pairs (distance, endingCity)

	vertex(){
		this->visited = false;
		this->cityName = " ";
		this->knownDistance = 9999;
		this->previousVertex = -1;
	}
};


class Graph
{
private:
	vector<vertex> vertices; // container holding the vertices inside a graph

public:
	Graph();  // constructor
	~Graph(); // destructor

	// adds vertex to the graph
	void addVertex(const string & cityName);

	 // adds edges to the graph
	void addEdges(int vertex, int distance, int endingVertex);

	// performs the Dijkstra's Algorithm
	void dijkstrasShortestPath(int start);

	// checks if the city is inside the heap, if so it changes the know distance
	bool makeChangeInHeap(pri_que &my_min_heap,int city, int distance);

	// prints the paths and total distance from Atlanta
	void printDijkstrasPath(int start, int end);




};

// constructor
Graph::Graph(){}

// destructor
Graph::~Graph() {}


// adds edges to the graph
void Graph::addVertex(const string & cityName)
{
	vertex newVertex; // creates vertex

	newVertex.cityName = cityName;  // name is assigned to the new vertex

	vertices.push_back(newVertex); // added to container
}

// adds vertex to the graph
void Graph::addEdges(int startingVertex, int distance, int endingVertex)
{
	vertices.at(startingVertex).edge.push_back(make_pair(distance, endingVertex ));
}

// performs the Dijkstra's Algorithm
void Graph::dijkstrasShortestPath(int start)
{
	int index = 0;

	// min priority_queue to hold order of lowest known distance
	pri_que my_min_heap;

	cout << left;

	while(index < vertices.size())
	{
		// sets the known distance of the city
		int knownDistanceOfVertex = vertices.at(start).knownDistance;

		// sets the first starting location to a know distance of zero
		if(index == 0)
			knownDistanceOfVertex = vertices.at(start).knownDistance = 0;

		vertices.at(start).visited = true; // starting vertex becomes visited

		//for loop - runs through the adjacent edges of the starting vertex
		for(int i = 0; i < vertices.at(start).edge.size(); i++)
		{
			// sets the city adjacent to starting vertex
			int city = vertices.at(start).edge.at(i).second;

			// sets the distance between the city and the starting vertex
			int distance = vertices.at(start).edge.at(i).first;

			// if - checks if the city has been visited,
		    //      And that the knowDistance of the of the starting point
			//      plus the distance to the city is less than the
			//      knownDistance of the city.
			if(!vertices.at(city).visited && (knownDistanceOfVertex + distance)
					                       < vertices.at(city).knownDistance)
			{
				 // sets the previous vertex to the city
				vertices.at(city).previousVertex = start;

				// sets the known distance
				vertices.at(city).knownDistance = knownDistanceOfVertex + distance;

				// checks if the city is inside the priority_queue, if so it
				// manually changes the know distance, otherwise it pushes the
				// new city to the priority_queue
				if(!makeChangeInHeap(my_min_heap, city,
									vertices.at(city).knownDistance))
					my_min_heap.push(  make_pair(
												vertices.at(city).knownDistance,
											    city ) );
			}
		}

		// if - checks if the priority_queue is not empty.
		//      if not empty, it grabs the top and assigns
		//      it to become the next starting point. Then pops the top
		if(!my_min_heap.empty())
		{
			start = my_min_heap.top().second;
					my_min_heap.pop();
		}

		index++; // increment index
	}
	cout << right;

}


// checks if the city is inside the heap, if so it changes the know distance
bool Graph::makeChangeInHeap(pri_que &my_min_heap, int city, int distance )
{

	pri_que newQueue; // new queue is created
	const int SIZE = my_min_heap.size();
	bool found = false;

	// for loop - run through the priority queue checking if the city
	//            is to be found
	for(int index = 0; index < SIZE; index++)
	{
		// if a match is found - push a new known path with the same city
		if(my_min_heap.top().second == city)
		{
			newQueue.push(  make_pair(distance, city ) );
			found = true;
		}
		else // pushed the regular item of the passed in priority_queue
		{
			newQueue.push(make_pair(
					      my_min_heap.top().first,
					      my_min_heap.top().second ) );
		}

		my_min_heap.pop(); // pop the passed in priority queue
	}
	// assign the passed in priority_queue with a new modified priority_queue
	my_min_heap = newQueue;

	return found;
}

// prints the paths and total distance from Atlanta
void Graph::printDijkstrasPath(int start, int end)
{
	vector <string> outputPath;
	cout << "\n**" << vertices.at(start).cityName << " --> "
		 << vertices.at(end).cityName << "**"
		 << "\nDistance From Center: " << vertices.at(end).knownDistance;

	cout << "\nThe path take: ";

	while(end != -1) // while runs until it reaches the starting point
	{
		outputPath.push_back( vertices.at(end).cityName);
		end = vertices.at(end).previousVertex;
	}

	for(vector<string>::reverse_iterator it  = outputPath.rbegin();
										  it != outputPath.rend(); it++)
		cout << *it << "   ";

	cout << endl << endl;
}
#endif /* GRAPH_H_ */
