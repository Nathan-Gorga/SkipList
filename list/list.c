#include "list.h"

Node* createLinkedListFromArray(unsigned int * arr, const unsigned int size){
    Node * head = createNode(arr[0],1);

    Node * curr = head;
    const unsigned int numPtrs = 1;
    for(unsigned int i = 1; i < size; i++){
        curr->next[0] = createNode(arr[i],numPtrs);
        curr = curr->next[0];
    }

    return head;
}