#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* nxt = head->next;

  if(head->val <= pivot){
    smaller = head;
    smaller->next = nullptr;
    llpivot(nxt, smaller->next, larger, pivot);
  }
  else{
    larger = head;
    larger->next = nullptr;
    llpivot(nxt, smaller, larger->next, pivot);
  }
  
  head = nullptr;
}