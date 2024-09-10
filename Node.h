#pragma once
#include <iostream>
using namespace std;
#include <limits>

class Node {
 private:
  int data;
  Node* link;

 public:
  Node(int data, Node* link);

  Node* getLink() { return link; }

  int getData() { return data; }

  void setLink(Node* nextIndex) { link = nextIndex; }

  void setData(int newData) { data = newData; }
};