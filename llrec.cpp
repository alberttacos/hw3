#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == NULL){ //if list is empty
    smaller = NULL;
    larger = NULL;
    return;
  }
  else if(head != NULL){
    
    llpivot(head->next, smaller, larger, pivot);

    if(head->val <= pivot){
      head->next = smaller;
      smaller = head;
    }
    else if( head->val > pivot){
      head-> next = larger;
      larger = head;
    }
  }
  head = NULL;
}
/*
smaller = NULL;
larger = NULL;
  if(head->val <= pivot){ //if value is less than or equal to pivot
    smaller ->next = head;
    smaller = head;
    llpivot(head->next, smaller->next, larger, pivot);
  }
  if(head->val > pivot){//if value is greater than pivot
    larger -> next = head;
    larger = head;
    llpivot(head->next, smaller, larger->next, pivot);
  }
}
*/