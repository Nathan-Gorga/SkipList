#include "utils.h"

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


void printList(Node * list, char * name){
    Node * curr = list;
    printf("%s : ", name);
    while(curr != NULL){
        printf("%d -> ",curr->val);
        curr = curr->next[0];
    }
    printf("NULL\n");
}


Sentinel createSentinel(const unsigned int numLanes){
    Sentinel temp;

    temp.numLanes = numLanes;

    temp.lane = malloc(sizeof(Node*) * numLanes);

    for(unsigned int i = 0; i < numLanes; i++){
        temp.lane[i] = NULL;
    }

    return temp;
}