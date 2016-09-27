#include "Graph.h"
#include <iostream>

int main() {
	
	// test 15: tests move assignment
	gdwg::Graph<std::string,int> g;
	
	// add this data into the graph
	g.addNode("a");
	g.addNode("b");
	g.addNode("c");
	g.addNode("d");
	
	g.addEdge("b","a",3);
	g.addEdge("b","a",5);
	g.addEdge("c","a",3);
	
	std::cout << "original graph" << std::endl;
	g.printNodes();
	g.printEdges("b");
	
	gdwg::Graph<std::string,int> gCopy;
	gCopy.addNode("z");
	std::cout << "Graph before copy assignment" << std::endl;
	gCopy.printNodes();
	
	gCopy = std::move(g);	// move assignment

	// We shouldn't use a moved-from object, in general.
	// However, here, for testing purposes, we assumed
	// a moved-from graph is an empty graph.
	std::cout << "moved-from graph (expected to be empty)" << std::endl;
	g.printNodes();

	std::cout << "moved-to graph" << std::endl;
	gCopy.printNodes();
	gCopy.printEdges("b");


	
	
}