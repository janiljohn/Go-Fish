// Your header

#include "Deck.hpp"

#include <algorithm>
#include <iterator>

auto make_new_deck() -> std::vector<Card> {
  std::vector<Card> cards = {
      Card("Guarantee Joker", "Joker", 0),
      Card("Joker", "Joker", 0),
      Card("Ace", "Spade", 1),
      Card("Deuce", "Spade", 2),
      Card("Three", "Spade", 3),
      Card("Four", "Spade", 4),
      Card("Five", "Spade", 5),
      Card("Six", "Spade", 6),
      Card("Seven", "Spade", 7),
      Card("Eight", "Spade", 8),
      Card("Nine", "Spade", 9),
      Card("Ten", "Spade", 10),
      Card("Jack", "Spade", 11),
      Card("Queen", "Spade", 12),
      Card("King", "Spade", 13),

      Card("Ace", "Diamond", 1),
      Card("Deuce", "Diamond", 2),
      Card("Three", "Diamond", 3),
      Card("Four", "Diamond", 4),
      Card("Five", "Diamond", 5),
      Card("Six", "Diamond", 6),
      Card("Seven", "Diamond", 7),
      Card("Eight", "Diamond", 8),
      Card("Nine", "Diamond", 9),
      Card("Ten", "Diamond", 10),
      Card("Jack", "Diamond", 11),
      Card("Queen", "Diamond", 12),
      Card("King", "Diamond", 13),

      Card("King", "Club", 13),
      Card("Queen", "Club", 12),
      Card("Jack", "Club", 11),
      Card("Ten", "Club", 10),
      Card("Nine", "Club", 9),
      Card("Eight", "Club", 8),
      Card("Seven", "Club", 7),
      Card("Six", "Club", 6),
      Card("Five", "Club", 5),
      Card("Four", "Club", 4),
      Card("Three", "Club", 3),
      Card("Deuce", "Club", 2),
      Card("Ace", "Club", 1),

      Card("King", "Heart", 13),
      Card("Queen", "Heart", 12),
      Card("Jack", "Heart", 11),
      Card("Ten", "Heart", 10),
      Card("Nine", "Heart", 9),
      Card("Eight", "Heart", 8),
      Card("Seven", "Heart", 7),
      Card("Six", "Heart", 6),
      Card("Five", "Heart", 5),
      Card("Four", "Heart", 4),
      Card("Three", "Heart", 3),
      Card("Deuce", "Heart", 2),
      Card("Ace", "Heart", 1),
  };
  return cards;
}

Deck::Deck() { Packet::cards_ = make_new_deck(); }
Deck::~Deck(){};
