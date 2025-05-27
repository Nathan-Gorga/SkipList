#include "node.h"


Node* createNode(const unsigned int val, const unsigned int numPtrs){
    Node *temp = malloc(sizeof(Node));
    temp->val = val;
    temp->next = malloc(sizeof(Node*) * numPtrs);

    for(unsigned int i = 0; i < numPtrs; i++){
        temp->next[i] = NULL;
    }
    return temp;
}


void freeNodes(Node * head){
    Node * curr = head;

    while(curr != NULL){
        Node * temp = curr;
        curr = curr->next[0];
        free(temp->next);
        free(temp);
    }
}