// cards.h
// Authors: Judy Li
// Class provided: cardList, card, player
// 
// ---------------cardList CLASS-------------
// CONSTRUCTOR for the card class:
//   cardList();
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of card objects 
//
// PUBLIC MODIFICATION member functions for the cardList class:
//   void insertEnd( pointer* end, string str);
//     Precondition: The pointer to the end of the list and the value to add at the end is given
//   void clear(node *ptr);
//     Precondition: 
//     Postcondition: All nodes of list have been returned to the heap and headptr is now NULL
//   void removeCard(node *ptr);
//     Precondition: ptr is the pointer to the node being removed
//     Postcondition: The node, the ptr is pointing to is removed from the list
//   
// PUBLIC CONSTANT member functions for the llist class:
//   string search( string str ) const
//     Precondition: The string that is searched for is given
//     Postcondition: The string s returned if it is found and an empty string is returned if it's not found
//
//  
//----------------card CLASS-------------------
// CONSTRUCTOR for the card class:
//   card(string str = "");
//     Postcondition: The card suit and number are initialized to empty char 
//
// PUBLIC MODIFICATION member functions for the card class:
//   void setSuitNum(string str);
//     Precondition: A char is provided
//     Postcondition: The card's suit is set to c
//   
// PUBLIC CONSTANT member functions for the llist class:
//   string getSuitNum() const;
//     Precondition: The string that is searched for is given
//     Postcondition: The string is returned if it is found and an empty string is returned if it's not found
//
//
//------------------player CLASS------------------
// CONSTRUCTOR for the player class:
//   player(string playerName = "", card c);
//     Postcondition: The player's name is initialized to empty string and hand is initialized to c
//
// PUBLIC MODIFICATION member functions for the card class:
//   void setName(string str);
//     Precondition: A string is provided
//     Postcondition: The players name will be set to str
//   void play();
//     Postcondition: A message that the cards matched will be printed if the card is found and the card will be deleted
//     if not found, then nothing is printed
//
// PUBLIC CONSTANT member functions for the llist class:
//   void printCardList(cardList& a) const
//     Precondition: The cardList of the player is given
//     Postcondition: The entire card list is printed


#include <string>

#ifndef CARDS_H
#define CARDS_H

class card 
    {
        public:
            //CONSTRUCTOR
            card(char suit = '\0', char type = '\0' );
            //MODIFICATION member functions
            void setSuit(char s);
            void setType(char t);
            
            //FRIEND functions
            friend bool operator== (const card& c1, const card& c2);
            friend std::ostream& operator<< (std::ostream& os, const card& random);

        private:
            char suit;
            char type;


};

class cardList 
    { 

        
        public:
            struct Node{
                card data;
                Node *next;
            };
            
        
            //CONSTRUCTOR
            cardList();
            ~cardList();
            cardList(const cardList& source);
            //MODIFICATION member functions
            void insertEnd(card c);
            void removeCard(Node *ptr);
            void play(cardList& list2);
            //CONST member functions
            Node* find(card c1) const;
            bool search(card c) const;
            void printCardList() const;
            int countCards();
            Node* getFirst();

        private:
            Node* head;
            Node* tail;
};



// NON-MEMBER functions for card class
bool operator== (const card& c1, const card& c2);
std::ostream& operator<< (std::ostream& os, const card& random);



#endif
