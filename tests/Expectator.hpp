
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef EXPECTATOR_HPP
#define EXPECTATOR_HPP

#include <iostream>

template <class T>
class ExpectAssertion {

public:

  ExpectAssertion(T value) :
    _value(value),
    _negation(false) {

  }

  void equal(const T& value) { 
    compare(value, _value == value, "equal");
  }

  void lessThan(const T& value) {
    compare(value, _value < value, "be less than");
  }

  void greaterThan(const T& value) {
    compare(value, _value > value, "be greater than");
  }

  void lessOrEqual(const T& value) {
    compare(value, _value <= value, "be less than or equal");
  }

  void greaterOrEqual(const T& value) {
    compare(value, _value >= value, "be less than or equal");
  }

  ExpectAssertion<T>& no() {
    _negation = !_negation;
    return *this;
  }


private:

  T     _value;
  bool  _negation;

  void compare(const T& expectedValue, bool t, const std::string& str) {
    if (this->_negation ^ !t) {
      std::cout << "\033[1;31m" << "        Assertion error : Expected `" << _value << "` ";

      if (this->_negation)
        std::cout << "not ";

      std::cout << "to " << str << "`" << expectedValue << "`" << "\033[0m" << std::endl;
    }
  }

};


template <class T>
ExpectAssertion<T> expect(T value) {
  return ExpectAssertion<T>(value);
}

void describe(std::string featureName) {
  std::cout << std::endl << "\033[30;01m" << featureName << " :\033[0m" << std::endl;
}

void it(std::string description) {
  std::cout << std::endl << "    \033[30;01m" << description << " :\033[0m" << std::endl;
}

#endif
