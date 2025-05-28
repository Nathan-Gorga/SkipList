#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <limits.h>

enum error_codes { NODE_ADD_LANE = 1, SENTINEL_ADD_LANE};

typedef struct Node{
    unsigned int val;
    unsigned int numLanes;
    struct Node ** next;// array of pointers to the next node depending on the lane on which the node is
}Node;

typedef struct Sentinel{
    
    unsigned int numLanes;
    Node ** lane;
}Sentinel;

#endif