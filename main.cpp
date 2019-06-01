#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
    if(argv != 3){
        cout << "Please provide 2 file names" << endl;
        return 1;
    }
    ifstream cardFile1 (argc[1]);
    ifstream cardFile2 (argc[2]);
    string line;

    if (cardFile1.fail()){
        cout << "Could not open file " << argc[1];
        return 1;
    }

    if (cardFile2.fail()){
        cout << "Could not open file " << argc[2];
        return 1;
    }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
    cardList list1;
    cardList list2;
  // Read each file and store cards

    while (getline (cardFile1, line) && (line.length() > 0)){
        char s = line[0];
        char t = line[2];
        card temp(s,t);
        list1.insertEnd(temp);
    }
    cardFile1.close();

    while (getline (cardFile2, line) && (line.length() > 0)){
        char s = line[0];
        char t = line[2];
        card temp2(s,t);
        list2.insertEnd(temp2);
    }
    cardFile2.close();
    
    // Start the game

    cardList::Node* temp = list1.getFirst();
     
    while(temp){
        cardList::Node* aptr = list1.getFirst();
        cardList::Node* bptr = list2.getFirst();
        while (aptr){
            if (list2.search(aptr->data)){
                cout << "Alice picked matching card " << aptr->data;
                list2.removeCard(list2.find(aptr->data));
                list1.removeCard(aptr);
                aptr = NULL;
                bptr = NULL;
            }else{
                aptr = aptr->next;
            }
        }
        
        if (aptr == 0){
            aptr = list1.getFirst();
            bptr = list2.getFirst();
        }

        while (bptr){
            if (list1.search(bptr->data)){
                cout << "Bob picked matching card " << bptr->data;
                list1.removeCard(list1.find(bptr->data));
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



    cout << endl;
    cout << "Alice's cards:" << endl;
    list1.printCardList();
    cout << endl;

    cout << "Bob's cards:" << endl;
    list2.printCardList();
    


  return 0;
}

