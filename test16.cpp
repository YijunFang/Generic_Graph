#include "Graph.h"
#include <iostream>

int main() {
	
	//// test 8: tests copy construction
	//copy constructor
	gdwg::Graph<std::string,int> g;
	// g.addNode("a");
	// g.addNode("b");
	// g.addNode("c");
	// g.addNode("d");
	
	// g.addEdge("b","a",3);
	// g.addEdge("b","a",5);
	// g.addEdge("b","d",4);
	// g.addEdge("c","a",3);

	// std::cout << "original graph" << std::endl;
	// g.printNodes();
	// g.printEdges("b");
	
	gdwg::Graph<std::string,int> gCopy{g};
	g.deleteNode("a");
	// std::cout << "original graph after delete" << std::endl;
	g.printNodes();
	// g.printEdges("b");


	// std::cout << "copied graph after delete in other graph" << std::endl;
	gCopy.printNodes();
	gCopy.printEdges("b");
	
	// std::cout << "copied graph after other graph is deleted" << std::endl;
	// gCopy.printNodes();
	

	std::cout << "iterate original graph" << std::endl;
	for (g.begin(); !g.end(); g.next()){
	   	std::cout << g.value() << std::endl;
	}

	std::cout << "iterate copy graph" << std::endl;
	for (gCopy.begin(); !gCopy.end(); gCopy.next()){
	   	std::cout << gCopy.value() << std::endl;
	}
	
	return 0;
}