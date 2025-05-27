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


unsigned int changeLaneToSentinel(const unsigned int numLanes, Sentinel * s){ // 0 : success, 1 : fail
    Node **temp = realloc(s->lane, numLanes * sizeof(Node*));
    if (temp == NULL) {
        return 1;
    }

    
    unsigned int oldNumLanes = s->numLanes;
    s->lane = temp;
    s->numLanes = numLanes;

    
    for (unsigned int i = oldNumLanes; i < numLanes; i++) {
        s->lane[i] = NULL;
    }

    return 0;
}