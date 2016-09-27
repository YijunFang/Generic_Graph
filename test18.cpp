#include "Graph.h"
#include <iostream>

int main() {

	// test 9: tests copy assignment
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
	
	gCopy = g;	// copy assignment
	g.deleteNode("a");
	std::cout << "original graph after delete" << std::endl;
	g.printNodes();
	g.printEdges("b");
	std::cout << "copied graph after delete in other graph" << std::endl;
	gCopy.printNodes();
	gCopy.printEdges("b");
	
	std::cout << "copied graph after other graph is deleted" << std::endl;
	gCopy.printNodes();


	
}