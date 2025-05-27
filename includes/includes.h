#ifndef INCLUDES_H
#define INCLUDES_H

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

#endif