#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <limits>
#include <stack>

class RPN {
 private:
  std::stack<long> sk;

  void check_and_push(std::string str, size_t i);
  void check_and_pop(std::string str, size_t i);

  void addition();
  void subtraction();
  void multiplication();
  void division();

  void check_over(long tmp);

  void print_result();

 public:
  RPN();
  ~RPN();
  RPN(const RPN& rhs);
  RPN& operator=(const RPN& rhs);

  void calculate(std::string str);

  class WrongArgumentException : public std::logic_error {
   public:
    WrongArgumentException() : logic_error("Not A Vaild Argument") {}
  };

  class OverFlowException : public std::out_of_range {
   public:
    OverFlowException() : out_of_range("The Number OverFlowed") {}
  };

  class UnderFlowException : public std::out_of_range {
   public:
    UnderFlowException() : out_of_range("The Number UnderFlowed") {}
  };

  class TooMuchOperatorException : public std::logic_error {
   public:
    TooMuchOperatorException() : logic_error("There Are Too Much Operators") {}
  };

  class CantDivideWithZero : public std::logic_error {
   public:
    CantDivideWithZero() : logic_error("You Can`t Divide With Zero") {}
  };

  class NotEnoughOperatorException : public std::logic_error {
   public:
    NotEnoughOperatorException() : logic_error("Not Enough Operators") {}
  };
};

#endif
