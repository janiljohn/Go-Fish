// Your header

#include "Hand.hpp"

Hand::Hand() {}
Hand::~Hand() {}

std::ostream& operator<<(std::ostream& out, const Hand& hand) {
  return hand.write(out);
}
