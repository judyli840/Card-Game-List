// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "cards.h"

using namespace std;

    void groupName(string str){
        cout << "-------------" << str << "-------------" << endl;
    }

    void test_printCardList(){
        groupName("test_printCardList");
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        cardList list1;
        cardList list2;
	cardList *list3 = new cardList;
        list1.insertEnd(c1);
        list1.insertEnd(c2);
        list1.insertEnd(c3);
        list2.insertEnd(c1);
	

        cout << "List 1 (3 cards): " << endl;
        list1.printCardList();
        cout << "List 2 (1 card): " << endl;
        list2.printCardList();
	cout << "List 3 (empty): " << endl;
	list3->printCardList();

	delete list3;
	
    }

    void test_search(){
        groupName("test_search");
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        cardList list1;
        cardList list2;
        list1.insertEnd(c1);
        list1.insertEnd(c2);
        list1.insertEnd(c3);
        list2.insertEnd(c1);

        if (list1.search(c3))
            cout << "PASSED" << endl;
        else
            cout << "FAILED" << endl;

	if (list2.search(c1))
            cout << "PASSED" << endl;
        else
            cout << "FAILED" << endl;

    }

    void test_insertEnd (){
        groupName("test_insertEnd");
        cardList list1;
        
        cardList *cptr = new cardList;
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        card arr[] ={ c1, c2, c3};

        for(int i = 0; i<3; i++){
        cptr->insertEnd(arr[i]);
        }

        if(list1.countCards() == 0)
        cout << "PASSED" << endl;
        else
        {
            cout << "FAILED" << endl;
        }

	if(cptr->countCards()==3)
            cout << "PASSED" << endl;
        else
            cout << "FAILED" << endl;
        
        delete cptr;
    }

    void test_cardDestructor(){
        groupName("test_cardDestructor");
        cardList *list1 = new cardList;
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        card arr[] ={ c1, c2, c3};

        for(int i = 0; i<3; i++){
        list1->insertEnd(arr[i]);
        }

        delete list1;

        if (!list1->search(c1))
            cout << "PASSED" << endl;
        else
            cout << "FAILED" << endl;

    }


    void test_cardListCopyCon(){
        groupName("test_cardListCopyCon");
        cardList *list1 = new cardList;
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        card arr[] ={ c1, c2, c3};

        for(int i = 0; i<3; i++){
            list1->insertEnd(arr[i]);
        }
        cardList list2(*list1);

        if (list2.countCards() == list1->countCards()){
            cout << "PASSED" << endl;
        }else
        {
                cout << "FAILED"<< endl;
        }
        delete list1;
    }

    void test_removeCard(){
        groupName("test_removeCard");
        cardList *list1 = new cardList;
        cardList *list2 = new cardList;
        card c1('s','2');
        card c2('c', '5');
        card c3 ('d', 'j');
        card arr[] ={ c1, c2, c3};
        
        for(int i = 0; i<3; i++){
            list1->insertEnd(arr[i]);
        }

        cardList::Node *temp = list1->getFirst();
        cardList::Node *temp2 = list2->getFirst();
        
        list1->removeCard(temp);
        list2->removeCard(temp2);
        if(list1->countCards() == 2){
            cout << "PASSED " << endl;
        }
        else
            cout << "FAILED"<< endl;

	 if(list2->countCards()==0)
		 cout << "PASSED" << endl;
	 else
		 cout << "FAILED" << endl;

        delete list1;
    }


    void test_cardList() {
        test_printCardList();
        test_search();
        test_insertEnd ();
        test_cardDestructor();
        test_cardListCopyCon();
        test_removeCard();
    }
    
int main(int argv, char** argc){
  
    test_cardList();
    return 0;
}
