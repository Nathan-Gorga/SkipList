#include "sentinel.h"

Sentinel createSentinel(const unsigned int numLanes){
    Sentinel temp;

    temp.numLanes = numLanes;

    temp.lane = malloc(sizeof(Node*) * numLanes);

    for(unsigned int i = 0; i < numLanes; i++){
        temp.lane[i] = NULL;
    }

    return temp;
}