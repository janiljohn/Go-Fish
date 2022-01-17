// Your header

#include <iostream>

#include "Packet.hpp"

#ifndef _HAND_HPP_
#define _HAND_HPP_

class Hand : public Packet {
 public:
  Hand();
  ~Hand();
};

std::ostream& operator<<(std::ostream& out, const Hand& hand);

#endif