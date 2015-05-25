#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
   vector< Hand > hands;
   Deck deck;
   int players; 
   int seed;
   int sizeOfHand = 5;

   cout << "Enter seed: ";
   cin >> seed;
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players; 

   deck.Shuffle();

    
    //Initialize the hands vector with the empty hand objects.
    for(int i=0;i<players;i++)
    {
        hands.push_back(Hand());
    }
    
    for(int i=0;i<sizeOfHand;i++)
    {
        //Get the cards to be dealt
        vector<Card> dealCards= deck.Deal(players);
        
        //Deal the cards to the players in round robin fashion
        for ( int j=0;j<hands.size();j++)
        { 
            Hand hand= hands[j];
            hand.add(dealCards[j]);
            hands[j]=hand;  
        }
    }
    
    //Display the hand of the players 
    for(int i=0;i<hands.size();i++)
    {
        Hand hand= hands[i];
        std::cout<<"Player "<<i+1<<" hand:  ";
        hand.showHand();
    }
}
