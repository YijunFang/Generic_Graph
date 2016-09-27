#include "Graph.h"
#include <iostream>

int main() {

	// test 14: tests move construction
	//move constructor
	gdwg::Graph<std::string,int> g;
	
	// add this data into the graph
	g.addNode("a");
	g.addNode("b");
	g.addNode("c");
	g.addNode("d");
	
	g.addEdge("b","a",3);
	g.addEdge("b","a",5);
	g.addEdge("b","d",4);
	g.addEdge("c","a",3);
	
	std::cout << "original graph" << std::endl;
	g.printNodes();
	g.printEdges("b");
	
	gdwg::Graph<std::string,int> gCopy = std::move(g);
	// We shouldn't use a moved-from object, in general.
	// However, here, for testing purposes, we assumed
	// a moved-from graph is an empty graph.
	std::cout << "moved-from graph (expected to be empty)" << std::endl;
	g.printNodes();
	// delete g;

	std::cout << "moved-to graph" << std::endl;
	gCopy.printNodes();
	gCopy.printEdges("b");

	// for (gCopy.begin(); !gCopy.end(); gCopy.next()){
	//    	std::cout << gCopy.value() << std::endl;
	// }
	// delete gCopy;

	
	return 0;

}