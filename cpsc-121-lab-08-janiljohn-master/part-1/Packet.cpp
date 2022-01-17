// Your header

#include "Packet.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <random>
#include <type_traits>
#include <vector>

// A packet is a collection of cards. Imagine a packet of playing cards
// face down on a table. The top (begining of the vector) is the card that is
// visible on top and the bottom (end of the vector) is the card that is laying
// on the table.

Packet::Packet() : cards_{} {
  // empty
}

Packet::Packet(std::vector<Card> cards) : cards_{cards} {
  // empty
}

// copy
Packet::Packet(Packet const& p) : cards_{begin(p.cards_), end(p.cards_)} {}

// move
Packet::Packet(Packet&& p)
    : cards_{std::make_move_iterator(begin(p.cards_)),
             std::make_move_iterator(end(p.cards_))} {
}

Packet::~Packet() {
  // empty
}

auto Packet::getCards() -> std::vector<Card> {
  return cards_;
}

auto Packet::shuffle() -> void {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(begin(cards_), end(cards_), rng);
}

auto Packet::perfect_shuffle() -> void {
  std::vector<Card> cards_copy{cards_};
  int half_size = cards_.size() / 2;
  for (int i = 0; i < cards_copy.size(); i += 2) {
    cards_[i] = cards_copy[half_size + i / 2];
    cards_[i + 1] = cards_copy[i / 2];
  }
}

auto Packet::cut(const int at_location) -> Packet {
  assert(at_location < cards_.size());
  std::vector<Card> top_cards{begin(cards_), begin(cards_) + at_location};
  std::vector<Card> bottom_cards{begin(cards_) + at_location, end(cards_)};
  // This is the packet (face down) that would go to the table from a tabled cut
  Packet top{top_cards};
  cards_ = bottom_cards;
  return top;
}

auto Packet::reverse_cut(const int at_location) -> Packet {
  assert(at_location < cards_.size());
  std::vector<Card> top_cards{begin(cards_), begin(cards_) + at_location};
  std::vector<Card> bottom_cards{begin(cards_) + at_location, end(cards_)};
  cards_ = top_cards;
  // The bottom of the packet (face down) is put to the table in lieu of the top
  // of the deck
  Packet bottom{bottom_cards};
  return bottom;
}

auto Packet::perfect_cut() -> Packet { 
  // TODO
  std::vector<Card> top_cards{begin(cards_), begin(cards_) + 26};
  std::vector<Card> bottom_cards{begin(cards_) + 26, end(cards_)};
  cards_ = bottom_cards;
  // The bottom of the packet (face down) is put to the table in lieu of the top
  // of the deck
  Packet top{top_cards};
  return top;
}

auto Packet::reverse_perfect_cut() -> Packet {
  // TODO
}

auto Packet::top_deal(const int n_cards) -> Packet {
  assert(n_cards < cards_.size());
  // This may be off by 1
  return cut(n_cards);
}

auto Packet::top_deal() -> Card {
  Packet p = top_deal(1);
  Card c = p.cards_[0];
  return c;
}

auto Packet::bottom_deal(const int n_cards) -> Packet {
  // TODO
}

auto Packet::bottom_deal() -> Card {
  // TODO
}

auto Packet::add_packet_on_bottom(const Packet& packet) -> void {
  std::vector<Card> joined_packets;
  joined_packets.reserve(cards_.size() + packet.cards_.size());
  joined_packets.insert(end(joined_packets), begin(cards_), end(cards_));
  joined_packets.insert(end(joined_packets), begin(packet.cards_),
                        end(packet.cards_));
  cards_ = joined_packets;
}

auto Packet::add_packet_on_top(const Packet& packet) -> void {
  std::vector<Card> joined_packets;
  joined_packets.reserve(cards_.size() + packet.cards_.size());
  joined_packets.insert(end(joined_packets), begin(packet.cards_),
                        end(packet.cards_));
  joined_packets.insert(end(joined_packets), begin(cards_), end(cards_));
  cards_ = joined_packets;
}

auto Packet::add_card_on_bottom(const Card& c) -> void {
  cards_.insert(end(cards_), c);
}

auto Packet::add_card_on_top(const Card& c) -> void {
  // TODO
  cards_.insert(begin(cards_), c);
}

auto Packet::size() -> int { return cards_.size(); }

auto Packet::num_books() -> int {

  

}

auto Packet::has_card(const Card& c) -> bool {
  return std::find_if(begin(cards_), end(cards_), [&c](Card& a_card) {
           return (a_card == c);
         }) != end(cards_);
}

auto Packet::has_card(const std::string name, const std::string suit) -> bool {
  return std::find_if(begin(cards_), end(cards_), [name, suit](Card& a_card) {
           return (a_card.getName() == name && a_card.getSuit() == suit);
         }) != end(cards_);
}

auto Packet::has_card(const int value, const std::string suit) -> bool {
  // TODO
}

auto Packet::has_cards_with_name(const std::string name) -> bool {
  // TODO
  return std::find_if(begin(cards_), end(cards_), [name](Card& a_card) {
           return (a_card.getName() == name);
         }) != end(cards_);
}

auto Packet::has_cards_with_value(const int value) -> bool {
  // TODO
}

auto Packet::has_cards_with_suit(const std::string suit) -> bool {
  return std::find_if(begin(cards_), end(cards_), [suit](Card& a_card) {
           return (a_card.getSuit() == suit);
         }) != end(cards_);
}

auto Packet::has_jokers() -> bool { return has_cards_with_suit("Joker"); }

auto Packet::discard(const Card& c) -> Packet {
  Packet p;
  std::copy_if(begin(cards_), end(cards_), std::back_inserter(p.cards_),
               [&c](Card& a_card) { return a_card == c; });
  cards_.erase(remove_if(begin(cards_), end(cards_),
                         [&c](Card& a_card) { return a_card == c; }),
               end(cards_));
  return p;
}

auto Packet::discard(std::string name, std::string suit) -> Packet {
  Packet p;
  std::copy_if(begin(cards_), end(cards_), std::back_inserter(p.cards_),
               [name, suit](Card& a_card) {
                 return (a_card.getName() == name && a_card.getSuit() == suit);
               });
  cards_.erase(
      remove_if(begin(cards_), end(cards_),
                [name, suit](Card& a_card) {
                  return (a_card.getName() == name && a_card.getSuit() == suit);
                }),
      end(cards_));
  return p;
}

auto Packet::discard(int value, std::string suit) -> Packet {
  Packet p;
  std::copy_if(
      begin(cards_), end(cards_), std::back_inserter(p.cards_),
      [value, suit](Card& a_card) {
        return (a_card.getValue() == value && a_card.getSuit() == suit);
      });
  cards_.erase(remove_if(begin(cards_), end(cards_),
                         [value, suit](Card& a_card) {
                           return (a_card.getValue() == value &&
                                   a_card.getSuit() == suit);
                         }),
               end(cards_));
  return p;
}

auto Packet::discard_all(std::string name) -> Packet {
  Packet p;
  std::copy_if(begin(cards_), end(cards_), std::back_inserter(p.cards_),
               [name](Card& a_card) { return (a_card.getName() == name); });
  cards_.erase(
      remove_if(begin(cards_), end(cards_),
                [name](Card& a_card) { return (a_card.getName() == name); }),
      end(cards_));
  return p;
}

auto Packet::discard_all(int value) -> Packet {
  Packet p;
  std::copy_if(begin(cards_), end(cards_), std::back_inserter(p.cards_),
               [value](Card& a_card) { return (a_card.getValue() == value); });
  cards_.erase(
      remove_if(begin(cards_), end(cards_),
                [value](Card& a_card) { return (a_card.getValue() == value); }),
      end(cards_));
  return p;
}

auto Packet::discard_suit(std::string suit) -> Packet {
  Packet p;
  std::copy_if(begin(cards_), end(cards_), std::back_inserter(p.cards_),
               [suit](Card& a_card) { return (a_card.getSuit() == suit); });
  cards_.erase(
      remove_if(begin(cards_), end(cards_),
                [suit](Card& a_card) { return (a_card.getSuit() == suit); }),
      end(cards_));
  return p;
}

auto Packet::discard_jokers() -> Packet { return discard_suit("Joker"); }

auto Packet::check_book() -> int {
  
}

auto Packet::operator==(const Packet& p) -> bool { return cards_ == p.cards_; }
auto Packet::operator!=(const Packet& p) -> bool { return cards_ != p.cards_; }

auto Packet::write(std::ostream& out) const -> std::ostream& {
  copy(cards_.begin(), cards_.end(), std::ostream_iterator<Card>(out, "\n"));
  return out;
}

std::ostream& operator<<(std::ostream& out, const Packet& packet) {
  return packet.write(out);
  return out;
}
