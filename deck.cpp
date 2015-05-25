#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

/**
* Default constructor. This will initialize and shuffle the deck
*/
Deck::Deck()
{
    Shuffle();
}

/**
* Reinitilaize the deck and shuffle it.
*/
void Deck::Shuffle()
{
    cards.erase(cards.begin(), cards.end());
    for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
    {
        for ( int j = Card::TWO; j <= Card::ACE; j++ )
        {
            cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
        }
    }
    
random_shuffle ( cards.begin(), cards.end() );

}

/**
* Dump out the contents of the current deck, minus already dealt cards
*/
void Deck::ShowDeck()
{

    for(int i=0;i<cards.size();i++)
    {
        Card c= cards[i];
        cout<<c.str()<<" ";
    }
    
    cout<<std::endl<<std::endl;
}

/**
* Return a vector of cards that are dealt. 
* @param count number of cards to deal
* @return a set of cards from the front of the deck
*/
std::vector<Card> Deck::Deal( int count )
{
    vector<Card> dealCards;
    
    for(int i=0;i<count;i++)
    { 
        //insert cards into vectors
        dealCards.push_back(Deck::cards[0]);
        //remove the card from the orighnal vector
        Deck::cards.erase(Deck::cards.begin());
    
    }

    return dealCards;
}


