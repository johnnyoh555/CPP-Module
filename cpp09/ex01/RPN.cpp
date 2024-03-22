#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& rhs) {
  if (this != &rhs) {
    sk = rhs.sk;
  }
}

RPN& RPN::operator=(const RPN& rhs) {
  if (this != &rhs) {
    sk = rhs.sk;
  }
  return *this;
}

void RPN::calculate(std::string str) {
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == ' ')
      continue;
    else if (std::isdigit(str[i]))
      check_and_push(str, i);
    else
      check_and_pop(str, i);
  }
  print_result();
}

void RPN::check_and_push(std::string str, size_t i) {
  if (str.size() - 1 != i) {
    if (str[i + 1] != ' ') throw WrongArgumentException();
  }
  sk.push(str[i] - '0');
}

void RPN::check_and_pop(std::string str, size_t i) {
  if (str.size() - 1 != i) {
    if (str[i + 1] != ' ') throw WrongArgumentException();
  }
  char oper[4] = {'+', '-', '*', '/'};
  int j = 0;
  for (; j < 4; j++) {
    if (oper[j] == str[i]) break;
  }
  switch (j) {
    case 0:
      addition();
      break;
    case 1:
      subtraction();
      break;
    case 2:
      multiplication();
      break;
    case 3:
      division();
      break;
    default:
      throw WrongArgumentException();
  }
}

void RPN::check_over(long tmp) {
  if (tmp > std::numeric_limits<int>::max())
    throw OverFlowException();
  else if (tmp < std::numeric_limits<int>::min())
    throw UnderFlowException();
}

void RPN::addition() {
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp1 = sk.top();
  sk.pop();
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp2 = sk.top();
  sk.pop();
  long tmp = tmp1 + tmp2;
  check_over(tmp);
  sk.push(tmp);
}

void RPN::subtraction() {
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp1 = sk.top();
  sk.pop();
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp2 = sk.top();
  sk.pop();
  long tmp = tmp2 - tmp1;
  check_over(tmp);
  sk.push(tmp);
}

void RPN::multiplication() {
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp1 = sk.top();
  sk.pop();
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp2 = sk.top();
  sk.pop();
  long tmp = tmp2 * tmp1;
  check_over(tmp);
  sk.push(tmp);
}

void RPN::division() {
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp1 = sk.top();
  sk.pop();
  if (!tmp1) throw CantDivideWithZero();
  if (sk.empty()) throw TooMuchOperatorException();
  long tmp2 = sk.top();
  sk.pop();
  long tmp = tmp2 / tmp1;
  check_over(tmp);
  sk.push(tmp);
}

void RPN::print_result() {
  if (sk.size() > 1) throw NotEnoughOperatorException();
  if (sk.empty()) return;
  std::cout << sk.top() << '\n';
}