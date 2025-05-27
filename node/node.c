#include "node.h"


Node* createNode(const unsigned int val, const unsigned int numPtrs){
    Node *temp = malloc(sizeof(Node));
    temp->val = val;
    temp->numLanes = numPtrs;
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

unsigned int nodePlusOneLane(Node * n){
    Node ** testNULL = realloc(n->next, sizeof(Node*) * (n->numLanes + 1));

    if(testNULL == NULL) return 1;

    n->next[n->numLanes] = NULL;
    n->numLanes++;
    return 0;
}