#include "card.h"
#include <sstream>

using namespace std;
/** 
* Default constructor
*/
Card::Card()
{
}

/**
* Constructor to initialize our suit and value
*
* @param _suit enum of SUITS
* @param _val  value of the card (COUNT enum)
*/
Card::Card( Card::SUITS _suit, Card::COUNT _val )
{
    suit= _suit;
    value= _val;
}

/**
* Get a string representation of the card.
* @return string in the format similar to this: "10D", which would be 10
* of diamonds
*/
std::string Card::str()
{
    ostringstream os;
    os << valToStr() << suitToStr();
    return os.str();
}

/**
* Convert card value to string
* @return string representation of the card value
*/
std::string Card::valToStr()
{
    COUNT c= getValue();
    if(c>=2&&c<=10)
    {
        ostringstream os;
        os<<c;
        return os.str();
    }
    else if(c==11)
    {
        return "J";
    }
    else if(c==12)
    {
        return "Q";
    }
    else if(c==13)
    {
        return "K";
    }
    else if(c==14)
    {
        return "A";
    }
   
}

/**
* Convert card suit to string
* @return string representation of the card suit
*/
std::string Card::suitToStr()
{
    SUITS s= getSuit();
    if(s==1)
    {
       return "C";
    }
    else if(s==2)
    {
       return "D";
    }
    else if(s==3)
    {
       return "H";
    }
    else if(s==4)
    {
       return "S";
    }
    else
    {
    return "";
    }
}

/**
* Accessor to get this card's suit
* @return value of this card's suit
*/
Card::SUITS Card::getSuit()
{
    return suit;
}

/**
* Accessor to get this card's value
* @return value of this card
*/
Card::COUNT Card::getValue()
{
    return value;
}

