#pragma once
#include <string>

constexpr auto SIZE = 15, VERYBIGNUMBER = 1000000;

class Graph
{
	struct Vertex
	{
		size_t number_ = 0;
		std::string name_;
	};
	size_t adjacencyMatrix_[SIZE][SIZE], connectionsMatrix_[SIZE][SIZE];
	Vertex vertexes_[SIZE];
	size_t vertexesCount_ = 0;
public:
	Graph();
	~Graph();
	void addVertex(size_t number, std::string name);
	void addEdge(size_t vertex1, size_t vertex2);
	void findMinDistancesFloyd();
	auto edgeExists(size_t vertex1, size_t vertex2) -> bool;
	void printSocialConnections();
};

