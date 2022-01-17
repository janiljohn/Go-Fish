// Your header

#include "Card.hpp"

Card::Card(std::string name, std::string suit, int value)
    : name_{name}, suit_{suit}, value_{value} {
  // empty
}

Card::~Card() {
  // empty
}

auto Card::getName() const -> std::string { return name_; }

auto Card::getSuit() const -> std::string { return suit_; }

auto Card::getValue() const -> int { return value_; }

auto Card::is_suit(const std::string& suit) const -> bool {
  bool truth = false;
  if (suit == suit_) {
    truth = true;
  }
  return truth;
}

auto Card::is_name(const std::string& name) const -> bool {
  bool truth = false;
  if (name == name_) {
    truth = true;
  }
  return truth;
}

auto Card::write(std::ostream& out) const -> std::ostream& {
  if (suit_ != "Joker") {
    out << name_ << " of " << suit_;
  } else {
    out << name_;
  }
  return out;
}

auto Card::operator==(const Card& c) const -> bool {
  return (suit_ == c.getSuit() && name_ == c.getName());
}

auto Card::operator!=(const Card& c) const -> bool { return !(*this == c); }

std::ostream& operator<<(std::ostream& out, const Card& card) {
  return card.write(out);
}
