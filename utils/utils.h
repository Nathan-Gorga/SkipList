#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    unsigned int val;
    struct Node ** next;// array of pointers to the next node depending on the lane on which the node is
}Node;

typedef struct Sentinel{
    unsigned int numLanes;
    Node ** lane;
}Sentinel;


Node* createNode(const unsigned int val, const unsigned int numPtrs);

Node* createLinkedListFromArray(unsigned int * arr, const unsigned int size);

void freeNodes(Node * head);

void printList(Node * list, char * name);

Sentinel createSentinel(const unsigned int numLanes);

#endif