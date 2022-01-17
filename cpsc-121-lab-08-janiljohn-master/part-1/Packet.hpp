// Your header

#include <vector>

#include "Card.hpp"

#ifndef _Packet_HPP_
#define _Packet_HPP_

class Packet {
 protected:
  std::vector<Card> cards_;

 public:
  Packet();
  Packet(std::vector<Card> cards);
  // copy
  Packet(Packet const& p);
  // move
  Packet(Packet&& p);

  ~Packet();

  auto getCards() -> std::vector<Card>;

  auto shuffle() -> void;
  auto perfect_shuffle() -> void;

  auto cut(const int at_location) -> Packet;
  auto reverse_cut(const int at_location) -> Packet;
  auto perfect_cut() -> Packet;
  auto reverse_perfect_cut() -> Packet;

  auto top_deal() -> Card;
  auto top_deal(const int n_cards) -> Packet;

  auto bottom_deal(const int n_cards) -> Packet;
  auto bottom_deal() -> Card;

  auto add_packet_on_bottom(const Packet& packet) -> void;
  auto add_packet_on_top(const Packet& packet) -> void;

  auto add_card_on_bottom(const Card& c) -> void;
  auto add_card_on_top(const Card& c) -> void;

  auto size() -> int;

  auto num_books() -> int;

  auto has_card(const Card& c) -> bool;
  auto has_card(const std::string name, const std::string suit) -> bool;
  auto has_card(const int value, const std::string suit) -> bool;
  auto has_cards_with_name(const std::string name) -> bool;
  auto has_cards_with_value(const int value) -> bool;
  auto has_cards_with_suit(const std::string suit) -> bool;
  auto has_jokers() -> bool;

  auto discard(const Card& c) -> Packet;
  auto discard(std::string name, std::string suit) -> Packet;
  auto discard(int value, std::string suit) -> Packet;
  auto discard_all(std::string name) -> Packet;
  auto discard_all(int value) -> Packet;
  auto discard_suit(std::string suit) -> Packet;
  auto discard_jokers() -> Packet;

  auto check_book() -> int;

  auto operator==(const Packet& p) -> bool;
  auto operator!=(const Packet& p) -> bool;

  auto write(std::ostream& out) const -> std::ostream&;
};

std::ostream& operator<<(std::ostream& out, const Packet& packet);

#endif