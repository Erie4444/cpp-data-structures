#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <unordered_map>

class Node;

class Edge{
 protected:
  unordered_map<char, Node> nodes;
 public:
  Edge(unordered_map<char, Node> nodes);
  Edge(const Edge& source);
  Edge& operator=(const Edge& source);
  friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
  ~Edge();
  
}

#endif
