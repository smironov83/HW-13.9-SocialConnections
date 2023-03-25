#include "graph.h"
#include <iostream>

Graph::Graph()
{
  for (size_t i = 0; i < SIZE; i++)
    for (size_t j = 0; j < SIZE; j++)
    {
      adjacencyMatrix_[i][j] = 0;
      connectionsMatrix_[i][j] = 0;
    }
  vertexesCount_ = 0;
}

Graph::~Graph() {}

void Graph::addVertex(size_t number, std::string name)
{
  vertexes_[vertexesCount_++] = { number, name };
}

void Graph::addEdge(size_t vertex1, size_t vertex2)
{
  adjacencyMatrix_[vertex1][vertex2] = 1;
  adjacencyMatrix_[vertex2][vertex1] = 1;
}

void Graph::findMinDistancesFloyd()
{
  for (size_t i = 0; i < SIZE; i++)
    for (size_t j = 0; j < SIZE; j++)
      if (i == j) { connectionsMatrix_[i][j] = 0; }
      else
      {
        if (!edgeExists(i, j)) { connectionsMatrix_[i][j] = VERYBIGNUMBER; }
        else { connectionsMatrix_[i][j] = adjacencyMatrix_[i][j]; }
      }

  for (size_t k = 0; k < vertexesCount_; k++)
  {
    size_t ck = vertexes_[k].number_;
    for (size_t i = 0; i < vertexesCount_; i++)
    {
      if (i == k)
        continue;
      size_t ci = vertexes_[i].number_;
      for (size_t j = 0; j < vertexesCount_; j++)
      {
        if (j == k)
          continue;
        size_t cj = vertexes_[j].number_;
        if (connectionsMatrix_[ci][ck] + connectionsMatrix_[ck][cj]
          < connectionsMatrix_[ci][cj])
          connectionsMatrix_[ci][cj] = connectionsMatrix_[ci][ck]
          + connectionsMatrix_[ck][cj];
      }
    }
  }
}

void Graph::printSocialConnections()
{
  std::cout << "Пары знакомств через одно рукопожатие: " << std::endl;
  for (size_t i = 0; i < vertexesCount_; i++)
    for (size_t j = i + 1; j < vertexesCount_; j++)
      if (connectionsMatrix_[i][j] == 1)
        std::cout << vertexes_[i].name_ << " - " << vertexes_[j].name_
        << std::endl;
  std::cout << std::endl << "Пары знакомств через два рукопожатия: "
    << std::endl;
  for (size_t i = 0; i < vertexesCount_; i++)
    for (size_t j = i + 1; j < vertexesCount_; j++)
      if (connectionsMatrix_[i][j] == 2)
        std::cout << vertexes_[i].name_ << " - " << vertexes_[j].name_
        << std::endl;
  std::cout << std::endl << "Пары знакомств через три рукопожатия: "
    << std::endl;
  for (size_t i = 0; i < vertexesCount_; i++)
    for (size_t j = i + 1; j < vertexesCount_; j++)
      if (connectionsMatrix_[i][j] == 3)
        std::cout << vertexes_[i].name_ << " - " << vertexes_[j].name_
        << std::endl;
  std::cout << std::endl << "Пары не знакомые друг с другом: " << std::endl;
  for (size_t i = 0; i < vertexesCount_; i++)
    for (size_t j = i + 1; j < vertexesCount_; j++)
      if (connectionsMatrix_[i][j] > 3)
        std::cout << vertexes_[i].name_ << " - " << vertexes_[j].name_
        << std::endl;
}


auto Graph::edgeExists(size_t vertex1, size_t vertex2)->bool
{
  return adjacencyMatrix_[vertex1][vertex2] != 0;
}
