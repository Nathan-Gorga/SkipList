#include "sentinel.h"
#include "../../utils/utils.h"
#include "../list/list.h"

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
    
    s->lane = temp;
    s->lane[s->numLanes] = NULL;
    s->numLanes++;

    return 0;
}


unsigned int sentinel(Node * head, Sentinel * s){
    
    *s = createSentinel(1);

    s->lane[0] = head;

    if(callBuildSkipList(s) == 1) return 1;

    return 0;
}