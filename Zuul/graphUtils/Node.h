#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "Edge.h"

class Node{
 protected:
  int id;
  vector<Edge*> edges;
 public:
  Node(int id, vector<Edge*> edges);
  Node(const Node& source);
  Node& operator=(const Node& source);
  std::ostream& operator<<(std::ostream& os, const Node& node);
  ~Node();
  
}

#endif
