//cards.cpp
//Authors: Judy Li
//Implementation of the classes defined in cards.h

#include <string>
#include <iostream>
#include "cards.h"
#include <cassert>

using namespace std;

//cardList

cardList::cardList(){
    head = NULL;
    tail = NULL;
}

cardList::~cardList(){
    Node *p = head;
    while(p){
        Node *n = p->next;
        delete p;
        p = n;
    }
    p=NULL;
}

cardList::cardList(const cardList& source){
    if(source.head == 0)
		head = 0;	
	Node *n = source.head;
	head = new Node;
	head->data = source.head -> data;
	Node *f = head;
    
    while(n->next){
        f->next = new Node;
        f = f->next;
        n = n->next;
        f->data = n->data;
    }
    f->next =0;	
}

void cardList::insertEnd(card c){
    if(head==0){
        Node *temp = new Node;
        temp->data = c;
        temp->next = 0;
        head = temp;
        tail = temp;
    }else{
        Node *n = new Node;
        tail->next = n;
        n->data = c;
        tail = n;
        tail->next = NULL;
    }


}

void cardList::removeCard(Node *ptr){
    Node *n = head;
    Node *s = tail;

    if (!ptr)
        return;

    if (head ==ptr){
        head = ptr->next;
        delete n;
        n = NULL;
        return;
    }

    if (tail == ptr){
        while(n->next != tail){
            n = n->next;
        }
        n->next = NULL;
        tail = n;
        delete s;
        s= NULL;
        return;
    }

    while (n){
        Node *current = ptr;
        if (n->next == ptr){
            n->next = ptr->next;
            delete current;
            current = NULL;
            return;
        }
        else
        {
            n = n->next;
        }
        
    }
}

int cardList::countCards(){
    Node *n = head;
    int count=0;
    if(!head)
	return count;
    while(n){
        count++;
        n = n->next;
    }
    return count;
}

/*void cardList::operator= (cardList c){

}*/

bool cardList::search(card c1) const {
    Node *ptr = head;
    while (ptr){
        if(ptr->data == c1)
            return true;
        ptr = ptr ->next;
    }
    return 0;
}

void cardList::printCardList() const{
    Node *n = head;
    while (n){
        cout << n->data;
        n = n->next;
    }
}

cardList::Node *cardList::find(card c1) const{
    Node *ptr = head;
    while (ptr){
        if(ptr->data == c1)
            return ptr;
        ptr = ptr ->next;
    }
    return 0;
}

cardList::Node* cardList::getFirst(){
    return head;
}




/*void cardList::play(cardList& list2){
    Node *temp = head;
     
    while(temp){
        Node *aptr = head;
        Node *bptr = list2.head;
        while (aptr){
            if (list2.search(aptr->data)){
                cout << "Alice picked matching card " << aptr->data;
                removeCard(aptr);
                list2.removeCard(list2.find(aptr->data));
                aptr = NULL;
                bptr = NULL;
            }else{
                aptr = aptr->next;
            }
        }
        
        if (aptr == 0){
            aptr = head;
            bptr = list2.head;
        }

        while (bptr){
            if (search(bptr->data)){
                cout << "Bob picked matching card " << bptr->data;
                removeCard(find(bptr->data));
                list2.removeCard(bptr);
                bptr = NULL;
                aptr = NULL;
            }else
            {
                bptr = bptr->next;
            }
        }

        temp = temp->next;
    }
}*/


//card

card::card(char s, char t){
    suit = s;
    type = t;
}



void card::setSuit(char s) {
    suit = s;
}

void card::setType(char t){
    type = t;
}



bool operator== (const card& c1, const card& c2){
    return ((c1.suit == c2.suit) && (c1.type == c2.type));
}

ostream &operator<< (std::ostream& os, const card& c){
    os << c.suit << " " << c.type << endl;
    return os;
}





