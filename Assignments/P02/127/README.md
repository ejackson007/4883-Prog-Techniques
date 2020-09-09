# "Accordian" Patience

The goal of the program was to simulate the game of "Accordian." In the game, you deal cards and stack them to either their immediate left, or card to the 3rd left given that their suit or rank match. The input consists of lines with 26 strings formatted with their rank and suit. A '#' as the input signifies the end of the decks.

To solve the problem, the deck of cards was dealt out in a list length 52, with position being its own list to simulate a stack. The algorithm will procedurally go through the list moving cards to prioritize the movement that has more left travel. Because a for loop does not allow for the iterator to be decrimented, a while loop was used instead.

Knowing this, he program used the following algorithm:

1. initialize deck list
2. add first half of deck
3. while first card isn't '#'
   1. add second half of deck
   2. initialize i to 0
   3. while i < len(deck)
      1. if i > 2 and the current card can stack on the third left card
         - stack cards
         - if stack is now empty, delete it
         - decriment i by 4
      2. if i > 0 and current card can stack on left adjacent card
         - stack cards
         - if stack is now empty, delete it
         - decriment i by 2
      3. incriment i by 1
   4. print resulting piles with sizes
   5. clear deck
   6. add new first half of deck
