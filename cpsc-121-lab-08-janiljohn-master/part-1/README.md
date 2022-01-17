# CPSC 121
# Go Fish
You're given a set of classes to use to create the card game named Go Fish. 

However, the class Packet is not complete. There are methods that need to be completed in order for it to work correctly. Complete the class Packet and add any additional functionality that you desire such that you can implement the game Go Fish. (Hint: look for the string `TODO` in Packet.cpp.)

The rules of the game are a little bit different than how you may have played it before.

The game is played with a deck of playing cards. A deck has 52 cards and two jokers. The jokers are not used in this game and are discarded. A deck of cards is composed of four suits, clubs, diamonds, hearts, spades. Each suit has 13 cards; Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. A book is defined as four cards who have the same value but from different suits. There are 13 books.

The objective of the game is to collect as many books as possible before the game ends. The game ends when there are no more cards left in the deck.

There are two players in the game. The first player is the computer and the second player is the person using the program. We'll call the computer the *AI* and the human being the *player*.

When the program starts, the program prints out instructions on how to play the game. Then the virtual deck of cards is created, the jokers are removed, the cards are shuffled, the deck is cut, and the cut is completed. Then each player is dealt 7 cards from the deck to their hand. (This means that there are 7 cards in the player's hand, 7 cards in the AI's hand, and 38 cards remaining in the deck.)

The first move always goes to the player. First, the player's hand is printed to the terminal. Then the player is prompted to name a card's name, such as *King*, *Six*, or *Ace*. If the AI has the card in it's hand, then a message is printed that the AI has the cards. Then the game removes the cards from the AI's hand and gives them to the player's hand. The player's hand is printed again and the player's turn continues until a card's name is given that the AI doesn't have. The game shall respond with "Go Fish!" and the top card from the deck is drawn and placed in the player's hand. The player's hand is printed one last time and the next player (the AI) shall play.

The turn goes to the AI and the AI will select a card's name. The AI's turn will continue until it is told to "Go Fish!". Whenever a card leaves a the player's hand, the player's hand is printed to the terminal.

Please slow down the AI using the sleep() function that was shown to you with the countdown lab exercise (lab 3 or lab 4). Otherwise the AI will play very fast and it will not be very interesting for the player.

The AI may select cards at random or you can develop a more sopisticated algorithm for this game.

Once the last card has been drawn from the deck, the game is over. The player that has the most books wins.

The included `Makefile` includes the targets:
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the linter to give you tips on how to improve your code

To build your program, use the command `make` or `make all`. 

### Don't Forget
Every file that you submit must have a header. Change the comment line (the one starting with ```//```) to state your full name. On the next line, start a new comment and state which section of CPSC 120 you are enrolled in. On the next line, start a new comment and state today's date. On the next line, start a new comment and state your CSUF email address. On the next line, start a new command and provide a short description of the program you are writing. For example, if your name is Tuffy Titan and you are in CPSC 120-01, the comment may look something like
  ```
  // Tuffy Titan
  // CPSC 120-01
  // 2050-01-01
  // tuffy.titan@csu.fullerton.edu
  //
  // This my first program and it prints out Hello World!
```
#### Style
You must adhere to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). It is important that what we write is easy to read and well organized. When in doubt, ask your instructor or ILA for assistance.

Use the makefile's format target to help you have the correct formatting.

## Testing Your Code
Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy
Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output
Please ensure your program's output is identical to the example below.
```
$ make
$ ./go_fish
Welcome to Go Fish!
The objective of the game is to collect as many books as 
  possible before the game ends. A book is defined as four cards who
  have the same value but from different suits, for example the four
  Kings (clubs, diamonds, hearts, spades) is a book. There are 13 books.
  The game ends when there are no more cards left in the deck.
  Each player is dealt 7 cards from the deck to their hand. You'll be
  playing against the computer and you'll have the first turn. You
  will be prompted to name a card's name, such as *King*, *Six*, or
  *Ace*. If the AI has the card in it's hand, then the game removes the
  cards from the AI's hand and gives them to your hand. Your hand will
  be printed again and the your turn continues until a card's name is
  given that the AI doesn't have. The game say "Go Fish!" and the top
  card from the deck is drawn and placed in your hand. Your hand will be
  printed one last time and the next player (the AI) shall play. The
  game continues until all the cards from the deck have been drawn.

Your hand is:
Seven of Diamond
Deuce of Heart
Ten of Diamond
Jack of Heart
King of Club
Deuce of Diamond
Ace of Heart

What card are you looking for?> King

The AI has the card you seek!

Your hand is:
Seven of Diamond
Deuce of Heart
Ten of Diamond
Jack of Heart
King of Club
Deuce of Diamond
Ace of Heart
King of Spade
King of Heart

What card are you looking for?> Ten

Go Fish!

Drawing a card from the deck...

Your hand is:
Seven of Diamond
Deuce of Heart
Ten of Diamond
Jack of Heart
King of Club
Deuce of Diamond
Ace of Heart
King of Spade
King of Heart
Seven of Heart

The AI wants your Kings...

Your hand is:
Seven of Diamond
Deuce of Heart
Ten of Diamond
Jack of Heart
Deuce of Diamond
Ace of Heart
Seven of Heart

The AI wants your Eights...

Go Fish!

It's your turn again.

Your hand is:
Seven of Diamond
Deuce of Heart
Ten of Diamond
Jack of Heart
Deuce of Diamond
Ace of Heart
Seven of Heart

What card are you looking for?>

```

