#include "BigNumCalc.h"

BigNumCalc::BigNumCalc() {};
BigNumCalc::~BigNumCalc() {};

list<int> BigNumCalc::buildBigNum(string numString) {
  list<int> listOfNumbers;
  for (auto i = 0u; i < numString.length(); i++) {
    listOfNumbers.push_back(numString[i] - '0');
  }

  return listOfNumbers;
}

list<int> BigNumCalc::add(list<int> num1, list<int> num2) {
  list<int> result;

  num1.reverse();
  num2.reverse();
  int carry = 0;

  auto iterator1 = num1.begin();
  auto iterator2 = num2.begin();

  while (iterator1 != num1.end() || iterator2 != num2.end() || carry != 0) {
    int digit1 = 0;
    if (iterator1 != num1.end()) {
      digit1 = *iterator1;
      ++iterator1;
    }

    int digit2 = 0;
    if (iterator1 != num2.end()) {
      digit2 = *iterator2;
      ++iterator2;
    }

    int sum = digit1 + digit2 + carry;
    result.push_back(sum % 10);
    carry = sum / 10;
  }

  result.reverse();
  return result;
};

list<int> BigNumCalc::sub(list<int> num1, list<int> num2) {
  list<int> result;
  num1.reverse();
  num2.reverse();
  int carry2 = 0;

  auto iterator1 = num1.begin();
  auto iterator2 = num2.begin();

  while (iterator1 != num1.end() || iterator2 != num2.end()) {
    int digit1 = 0;
    if (iterator1 != num1.end()) {
      digit1 = *iterator1;
      ++iterator1;
    }

    int digit2 = 0;
    if (iterator2 != num2.end()) {
      digit2 = *iterator2;
      ++iterator2;
    }

    int difference = digit1 - digit2 - carry2;
    if (difference < 0) {
      difference += 10;
      carry2 = 1;
    } else {
      carry2 = 0;
    }

    result.push_back(difference);
  }

  result.reverse();

  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2) {
  list<int> result;

  if (num2.size() != 1) {
    throw invalid_argument(
        "num2 must be a single-digit number. Please try again!");
  }

  int multiplyNum = num2.front();
  int carry3 = 0;

  num1.reverse();
  auto iterator1 = num1.begin();

  while (iterator1 != num1.end() || carry3 != 0) {
    int digit1 = 0;
    if (iterator1 != num1.end()) {
      digit1 = *iterator1;
      ++iterator1;
    }

    int multiplyResult = digit1 * multiplyNum + carry3;
    result.push_back(multiplyResult % 10);
    carry3 = multiplyResult / 10;
  }

  result.reverse();

  return result;
}