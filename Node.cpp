#include <iostream>
using namespace std;
#include "Node.h"

Node::Node(int data, Node* link) {
  this->data = data;
  this->link = link;
};