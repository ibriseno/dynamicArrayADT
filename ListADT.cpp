#include "ListADT.h"
#include <new>
#include <cstddef>
#include <list>


ListADT::~ListADT(){
    Node *toDelete = head;
    while(toDelete != NULL){
        head = toDelete->next;
        delete toDelete;
        toDelete = head;
    }
}
ListADT::ListADT(const ListADT &cloneList1){
    size = 0;
    head=NULL;
    Node* temp = cloneList1.head;
    int s = cloneList1.size;
    while(s--){
        push_back(temp->value);
        temp = temp->next;
    }    
}

ListADT& ListADT::operator =(const ListADT& cloneList1){
    size = 0;
    head=NULL;
    Node* temp = cloneList1.head;
    int s = cloneList1.size;
    while(s--){
        push_back(temp->value);
        temp = temp->next;
    }   
    return (*this);
    
}

int ListADT::operator[](int i) const{
    Node* temp = head;
    while(i--){
        temp=temp->next;
    }
    return temp->value;
}

ostream &operator<<(ostream &OUT,const ListADT v){
    if(v.size==0)
        return(OUT);
    OUT <<v[0];
    for (int i = 1; i < v.size; i++)
    {
      OUT << ","<<v[i];
    }
    OUT << endl;
    return( OUT );
}


ListADT::ListADT():head(NULL), size(0){
        
}


void ListADT::push_back(int val){
    Node *newNode = new Node(val);
    Node* temp = head;
    if(head==NULL){
        head=newNode;
        size++;
        return;
    }

    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = newNode;
    size++;
}

void ListADT::push_front(int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    size += 1;
}

void ListADT::pop_back(){
    if(head==NULL)
        return;
    if(head->next==NULL){
        head=NULL;
        size--;
        return;
    }

    Node* temp = head;
    Node* prev = head;
    
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next = NULL;
    size--;
}

void ListADT::pop_front(){
    if(head==NULL)
        return;
    Node* temp = head;
    head=head->next;
    delete(temp);
    size--;
}


int ListADT::length() const{ 
    return size;
}               