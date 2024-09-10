#include "LinkedList.h"

#include <limits>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) {
  head = nullptr;

  for (int i = len - 1; i >= 0; --i) {
    head = new Node(array[i], head);
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  if (pos <= 1) {
    head = new Node(newNum, head);
    return;
  }

  int currentPos = 1;
  Node* current = head;

  while (current != nullptr && currentPos < pos - 1) {
    current = current->getLink();
    currentPos++;
  }

  if (current == nullptr) {
    return;
  }

  Node* newNode = new Node(newNum, current->getLink());
  current->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
  if (pos < 1 || head == nullptr) {
    return false;
  }

  Node* prev = nullptr;
  Node* current = head;
  for (int i = 1; current != nullptr && i < pos; ++i) {
    prev = current;
    current = current->getLink();
  }

  if (!current) {
    return false;
  }

  if (prev) {
    prev->setLink(current->getLink());
  } else {
    head = current->getLink();
  }

  delete current;

  return true;
};

int LinkedList::get(int pos) {
  Node* current = head;
  for (int i = 1; current != nullptr && i < pos; ++i) {
    current = current->getLink();
  }

  if (current) {
    return current->getData();
  } else {
    return numeric_limits<int>::max();
  }
}

int LinkedList::search(int target) {
  Node* current = head;
  int pos = 1;
  while (current) {
    if (current->getData() == target) {
      return pos;
    }
    current = current->getLink();
    pos++;
  }
  return -1;
}

void LinkedList::printList() {
  cout << '[';
  Node* current = head;
  if (current) {
    while (current) {
      cout << current->getData();
      if (current->getLink()) {
        cout << ' ';
      }
      current = current->getLink();
    }
  }
  cout << ']' << endl;
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* nextNode = current->getLink();
    delete current;
    current = nextNode;
  }
}