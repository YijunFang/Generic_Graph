#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <exception>


namespace gdwg{

	template <typename N, typename E> 
	class Graph{
	private:
			class Node;
			std::vector<Node> nodeVector_;							//vector of all node
			mutable typename std::vector<Node>::const_iterator it;	//pointer to value N

	public:
			//constructor
			Graph();

			//copy constructor
			template <typename N2, typename E2> 
			Graph(const Graph<N2,E2>&);

			//move constructor
			template <typename N2, typename E2>
			Graph(Graph<N2,E2> &&g);

			//copy assignment
			template <typename N2, typename E2>
			Graph& operator=(const Graph<N2,E2> &g);

			//move assignment
			template <typename N2, typename E2>
			Graph& operator=(Graph<N2,E2> &&g);

			//Destructor
			~Graph();
			
			// =============Getter and Setter============
			std::vector<Node> getNodeVector() const {return nodeVector_;};
			
			// =============Graph functions=============
			//Adds a new node with value val to the graph. 
			bool addNode(const N& v);

			// Adds a new edge src → dst with weight w. 
			bool addEdge(const N& src, const N& dst, const E& w);

			//Replaces the original data, by the replacement data, newData.
			bool replace(const N& oldData, const N& newData);

			//Replace the old data with new data, modify in/out edge and remove duplicated
			void mergeReplace(const N& oldData, const N& newData);

			//delete node with certain node value 
			void deleteNode(const N&) noexcept;

			//delete edge from graph match weight(from src->dst)
			void deleteEdge(const N& src, const N& dst, const E& w) noexcept;

			//Remove all nodes and edges from the graph
			void clear() noexcept;

			//Returns true if a node with value val exists
			bool isNode(const N& val) const;

			//Returns true if two nodes with value are connected
			bool isConnected(const N& src, const N& dst) const;

			//print all nodes in the graph (min->max outdegree)
			void printNodes() const;
			
			//print all edges that start from node(with value val) (min->max node value)
			void printEdges(const N& val) const;
			
			//iterator point to first node
			void begin() const;

			//iterator point to last node
			bool end() const;

			//iterator point to next node
			void next() const;

			//get the node value of node
			const N& value() const;
			
			//get the node vith value v
			Node& getNode(const N& v );

			//recieve a nodeVector, copy and return a new nodeVector
			std::vector<Node> copyNodeVector(const std::vector<Node> original);
			
	private:
			class Node{
			private:
					class Edge;
					int outDegree_;					//store number of outgoing edge
					std::vector<Edge> edgeVector_;	//a vector of outgoing edge				
					std::shared_ptr<N> sp_N_;		//point to the value N
				public:
					//node constructor
					Node(const N& value);
					
					//copy node constructor
					Node(const Node& node);
					
					// ===============Getter and Setter=================
					std::vector<Edge> getEdgeVector(){return edgeVector_;}
					
					std::shared_ptr<N> getSharePtr() const { return sp_N_; }
					
					int getDegree() const {return outDegree_; }
					
					void setSharePtr(const N& newData){sp_N_=std::make_shared<N>(newData);}
					
					void setDegree(int degree){outDegree_ = degree;}
					
					void freeSharePtr(){sp_N_.reset();}
					
					// =============Node functions=============
					bool makeEdge(Node& dst, E w);
					
					//print the edge(dest & weight) in the edgeVector
					void printEdgeVector() const;
					
					//return true if their exist this edge
					bool isEdge(Node& dst, E w);
					
					//return true if the two nodes are connected
					bool checkIsConnected(const N& dst) const;

					//delete the outgoing edge from this node
					void deleteEdgeFromNode(const N& dst);

					//delete the outgoing edge with the given weight
					void deleteEdgeFromNode_matchWeight(const N& dst, const E& w);

					//in the node change every edge that point to old to new
					void modifyEdge(const N& oldData, Node& dstNode);
					
					//given a edge vector, copy and return a new edge vector
					std::vector<Edge> copyEdgeVector(const std::vector<Edge> original);
					
					
					
				private:
					class Edge{
						public:
							//Edge constructor
							Edge(Node& dst, E& w);
							
							//Edge copy constructor
							Edge(const Edge& ori);
							
							//destructor
							~Edge();
							
							// ===============Getter and Setter=================
							void setWeakPtr(const Node& newData){ wp_N_=newData.getSharePtr();}
							
							std::weak_ptr<N> getWeakPtr() const { return wp_N_; }
							
							E getweight()const {return weight;}
							
							void freeWeakPtr(){wp_N_.reset();}
							

						private:
							std::weak_ptr<N> wp_N_;		//point to the destination
							E weight;					//store the weight of edge

					};


			};
		
	};

	#include "Graph.tem"
}

#endif
