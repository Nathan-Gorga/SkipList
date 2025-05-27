#include "sentinel.h"
#include "../utils/utils.h"

Sentinel createSentinel(const unsigned int numLanes){
    Sentinel temp;

    temp.numLanes = numLanes;

    temp.lane = malloc(sizeof(Node*) * numLanes);

    for(unsigned int i = 0; i < numLanes; i++){
        temp.lane[i] = NULL;
    }

    return temp;
}

void freeSentinel(Sentinel s){
    free(s.lane);
}


unsigned int sentinelPlusOneLane(Sentinel * s){ // 0 : success, 1 : fail
    
    Node **temp = realloc(s->lane, sizeof(Node*) * (s->numLanes + 1));
   
    if (temp == NULL) return 1;

    s->lane[s->numLanes] = NULL;
    s->numLanes++;

    return 0;
}