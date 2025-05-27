#ifndef NODE_H
#define NODE_H


#include "../includes/includes.h"

Node* createNode(const unsigned int val, const unsigned int numPtrs);

void freeNodes(Node * head);

unsigned int nodePlusOneLane(Node * n);


#endif