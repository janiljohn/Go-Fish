// Your header

#include <iostream>
#include <vector>
#include <map>

#include "Deck.hpp"
#include "Hand.hpp"
#include "Packet.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Welcome to Go Fish!\n";
  cout << "The objective of the game is to collect as many books as \n\
  possible before the game ends. A book is defined as four cards who\n\
  have the same value but from different suits, for example the four\n\
  Kings (clubs, diamonds, hearts, spades) is a book. There are 13 books.\n\
  The game ends when there are no more cards left in the deck.\n\
  Each player is dealt 7 cards from the deck to their hand. You'll be\n\
  playing against the computer and you'll have the first turn. You\n\
  will be prompted to name a card's name, such as *King*, *Six*, or\n\
  *Ace*. If the AI has the card in it's hand, then the game removes the\n\
  cards from the AI's hand and gives them to your hand. Your hand will\n\
  be printed again and the your turn continues until a card's name is\n\
  given that the AI doesn't have. The game say \"Go Fish!\" and the top\n\
  card from the deck is drawn and placed in your hand. Your hand will be\n\
  printed one last time and the next player (the AI) shall play. The\n\
  game continues until all the cards from the deck have been drawn.\n";

  Deck deck;
  deck.discard_jokers();
  deck.shuffle();
  Packet top = deck.perfect_cut();
  deck.add_packet_on_bottom(top);

  
  Hand player;
  Hand ai;
  player.add_packet_on_top(deck.top_deal(7));
  ai.add_packet_on_top(deck.top_deal(7));

  cout << "Deck:\n" << deck << endl;
  cout << "Player:\n" << player << endl;
  cout << "AI:\n" << ai << endl;

  int turn = 1;

  vector<Card> ai_hand = ai.getCards();
      

      map<string,int> check = {

        {"Ace",false},
        {"Deuce",false},
        {"Three",false},
        {"Four",false},
        {"Five",false},
        {"Six",false},
        {"Seven",false},
        {"Eight",false},
        {"Nine",false},
        {"Ten",false},
        {"Jack",false},
        {"Queen",false},
        {"King",false}

      };

  bool game_over = false;
  while (!game_over) {

    map<string,int> books = {

        {"Ace",0},
        {"Deuce",0},
        {"Three",0},
        {"Four",0},
        {"Five",0},
        {"Six",0},
        {"Seven",0},
        {"Eight",0},
        {"Nine",0},
        {"Ten",0},
        {"Jack",0},
        {"Queen",0},
        {"King",0}

      };

    if(turn%2!=0){

      cout << "********************Player********************" << endl;

      cout << "What card are you looking for?> ";
      string player_choice;
      cin >> player_choice;
      if(player_choice=="q"){
        game_over = true;
      }
      // TODO - fill in the logic for this game.
      if(ai.has_cards_with_name(player_choice)){
        for(int x = 0; x<ai.size(); x++){
          if(ai.getCards().at(x).getName()==player_choice){
            
            Card temp = ai.getCards().at(x);
            player.add_card_on_top(temp);
          }
        }
        ai.discard_all(player_choice);
      }
      else {
        Card temp = deck.top_deal();
        cout << "\nGo Fish!" << endl;
        player.add_card_on_top(temp);
        deck.discard(temp);
        turn++;
        //game_over = true;
      }
      cout << "\nPlayer:\n" << player << endl;
      cout << "AI:\n" << ai << endl;
      
    }
    else{

      cout << "********************AI********************" << endl;

      

      for(int x = 0; x<ai_hand.size(); x++){
        string name = ai_hand[x].getName();
        books[name] += 1;
      }

      // for(auto it = books.begin(); it != books.end(); ++it)
      // {
      //   std::cout << it->first << " " << it->second << "\n";
      // }
      // game_over = true;

      string ai_choice;

      int max = 0;
      for(auto it = books.begin(); it != books.end(); ++it){
        //cout << "Max: " << max << "\nCurrent: " << it->first << "\t" << it->second << "\t" << check[it->first] << "\n" << endl;
        if( (it->second > max) && (check[it->first]==false) ){
          ai_choice = it->first;
          max = it->second;
        }
      }

      if(ai_choice == ""){

        map<string,int> check = {

        {"Ace",false},
        {"Deuce",false},
        {"Three",false},
        {"Four",false},
        {"Five",false},
        {"Six",false},
        {"Seven",false},
        {"Eight",false},
        {"Nine",false},
        {"Ten",false},
        {"Jack",false},
        {"Queen",false},
        {"King",false}

        };

      for(auto it = books.begin(); it != books.end(); ++it){
        //cout << "Max: " << max << "\nCurrent: " << it->first << "\t" << it->second << "\t" << check[it->first] << "\n" << endl;
        if( (it->second > max) && (check[it->first]==false) ){
          ai_choice = it->first;
          max = it->second;
        }
      }

      }

      cout << "AI's choice is: " <<ai_choice << endl;
      check[ai_choice] = true;

      if(player.has_cards_with_name(ai_choice)){
        for(int x = 0; x<player.size(); x++){
          if(player.getCards().at(x).getName()==ai_choice){
            
            Card temp = player.getCards().at(x);
            ai.add_card_on_top(temp);
          }
        }
        player.discard_all(ai_choice);
        
      }
      else {
        Card temp = deck.top_deal();
        cout << "\nGo Fish!" << endl;
        ai.add_card_on_top(temp);
        deck.discard(temp);
        turn++;
        string name2 = temp.getName();
        cout << "\nTHIS IS THE NAME OF THE CARD THAT WAS ADDED FROM THE DECK: " << name2 << endl;
        books[name2] += 1;
        //game_over = true;
        cout << "\n" << endl;
        for(auto it = books.begin(); it != books.end(); ++it){
        cout << "Max: " << max << "\nCurrent: " << it->first << "\t" << it->second << "\t" << check[it->first] << "\n" << endl;
        }
      }
      cout << "\nPlayer:\n" << player << endl;
      cout << "AI:\n" << ai << endl;


    } // end of AI's turn
    
    if(deck.size()<=0){
      game_over = true;
    }

  } // end of while

  return 0;
}