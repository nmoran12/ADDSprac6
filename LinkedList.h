#include "Node.h"

class LinkedList {
 private:
  Node* head;

 public:
  int len;
  LinkedList();

  LinkedList(int* array, int len);

  ~LinkedList();

  void insertPosition(int pos, int newNum);

  bool deletePosition(int pos);

  int get(int pos);

  int search(int target);

  void printList();
};