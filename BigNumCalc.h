#pragma once
#include <iostream>
using namespace std;
#include <list>

class BigNumCalc {
 public:
  BigNumCalc();
  ~BigNumCalc();

  list<int> buildBigNum(string numString);
  list<int> add(list<int> num1, list<int> num2);
  list<int> sub(list<int> num1, list<int> num2);
  list<int> mul(list<int> num1, list<int> num2);
};