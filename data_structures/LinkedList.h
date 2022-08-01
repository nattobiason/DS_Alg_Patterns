#include <iostream>
using namespace std;
/*
    A list is a data structure that allows for individual elements to be added and removed as needed. 
    In a typical list implementation, called a linked list, memory is allocated for individual elements, 
    and then pointers link those individual elements together.
*/

// single LL
struct listNode{
    int key;
    listNode *next;
    // listNode* previous; // for doubly linked lists
};

class LinkedList{
    listNode *head;
    listNode *tail;
public:
    LinkedList();
    void insertNode(int prevValue, int value);
    void deleteNode(int value);
    ~LinkedList();
    listNode *search(int value);
    void printList();
};


LinkedList::LinkedList(){ // create list
    listNode *n = new listNode();
    head = n;
    tail = n;
    n->next = NULL;
    n->key = 0;
}

void LinkedList::insertNode(int prevValue, int value){
    listNode *prev = search(prevValue);
    listNode *n = new listNode();
    n->key = value;
    if(prev == NULL){ // head node
        n->next = head;
        head = n;
    }
    else if(prev->next == NULL){ // tail node
        prev->next = n;
        tail = n;
    }
    else{ // middle node
        n->next = prev->next;
        prev->next = n;
    }
}

void LinkedList::deleteNode(int value){
    listNode *tmp;
    bool found;
    if(head->key == value){ // head node
        tmp = head;
        head = head->next;
        delete tmp;
    }
    else{ // middle or tail
        listNode *prev = head;
        tmp = head->next;
        found = false;
        while(tmp != NULL && !found){
            if(tmp->key == value){
                prev->next = tmp->next;
                if(tmp == tail){
                    tail = prev;
                }
                delete tmp;
                found = true;
            }
            else{
                prev = tmp;
                tmp = tmp->next;
            }
        }
    }
}

LinkedList::~LinkedList(){
    listNode *tmp = head;
    listNode *t = head->next;
    while(tmp != NULL){
        delete tmp;
        tmp = t;
        t = t->next;
    }
}

listNode* LinkedList::search(int value){
    listNode *tmp = head;
    listNode *returnNode = NULL;
    bool found = false;
    while(!found && tmp != NULL){
        if(tmp->key == value){
            found = true;
            returnNode = tmp;
        }
        else{
            tmp = tmp->next;
        }
    }
    
    return returnNode;
}

void LinkedList::printList(){
    listNode *tmp = head;
    while(tmp != NULL){
        cout << tmp->key << endl;
        tmp = tmp->next;
    }
}
