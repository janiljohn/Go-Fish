// Your header

#include <vector>

#include "Packet.hpp"

#ifndef _DECK_HPP_
#define _DECK_HPP_

// A deck of cards is a special case of packet of cards.

// This is new deck order for almost all standard US
// playing cards.
// Imagine the deck of cards, squared, and facing up. The face of
// a card is visible and the backs of the cards are towards
// the table top. The 0th card is the card facing you.
// The 0th card is the joker & guarantee card
// The 1st card is the joker
// The 2nd - 14th cards are the spades ♠️ in ascending order (Ace -> King)
// The 15th - 27th cards are the diamonds ♦️in ascending order (Ace -> King)
// The 28th - 40th cards are the clubs ♣️in descending order (King -> Ace)
// The 41st - 53rd cards are the hearts ♥️ in descending order (King -> Ace)
void make_new_deck(std::vector<Card>& cards);

class Deck : public Packet {
 public:
  Deck();
  ~Deck();
};

#endif