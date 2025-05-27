#ifndef LIST_H
#define LIST_H
#include "../includes/includes.h"
#include "../node/node.h"

Node* createLinkedListFromArray(unsigned int * arr, const unsigned int size);

unsigned int buildSkipList(Sentinel * s);

#endif