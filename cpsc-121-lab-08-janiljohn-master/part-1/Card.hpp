// Your header

#include <iostream>
#include <string>

#ifndef _CARD_HPP_
#define _CARD_HPP_

class Card {
 private:
  std::string name_;
  std::string suit_;
  int value_;

 public:
  Card(std::string name, std::string suit, int value);
  ~Card();
  auto getName() const -> std::string;
  auto getSuit() const -> std::string;
  auto getValue() const -> int;
  auto is_suit(const std::string& suit) const -> bool;
  auto is_name(const std::string& name) const -> bool;
  auto write(std::ostream& out) const -> std::ostream&;
  auto operator==(const Card& c) const -> bool;
  auto operator!=(const Card& c) const -> bool;
};

std::ostream& operator<<(std::ostream& out, const Card& card);

#endif