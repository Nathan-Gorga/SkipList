#ifndef UTILS_H
#define UTILS_H
#include "../includes/includes.h"


void printList(Node * list, const unsigned int lane,char * name);

void freeAll(Sentinel s, unsigned int *arr);

void printSkipList(Sentinel s);

bool coinFlip();

#endif