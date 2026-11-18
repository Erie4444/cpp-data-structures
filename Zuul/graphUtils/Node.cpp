#include <iostream>
#include "Node.h"
#include "Edge.h"


using namespace std;

Node::Node(int id, vector<Edge*> edges){
  this -> id = id;
  this -> edges = edges;
}

Node::Node(const Node& source){
  this -> id = source.id;
  this -> edges = source.edges;
}

Node& operator=(const Node& source){
  if (this == &source){
    return (*this);
  }
  this -> id = source.id;
  this -> edges = source.edges;
}

ostream& operator<<(ostream& os, const Node& node){
  char idMsg[5] = "ID: ";
  char edgeMsg = "Edges: ";
  os << idMsg << node.id << endl;
  os << edgeMsg << node.edges << endl;
}

Node::~Node(){}

