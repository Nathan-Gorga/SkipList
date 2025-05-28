#include "search.h"



Node * linearSearch(const int key, Sentinel * s){
    Node * curr = s->lane[0];

    while(curr != NULL){
        if(curr->val == key) return curr;
        curr = curr->next[0];
    }

    return NULL;



}



Node * searchAlgo(const int key, Sentinel *s){// new algo
    
    /*const int maxLevel = s->numLanes -1;
    Node * curr = s->lane[maxLevel];

    for(int i = maxLevel; i >=0; i--){
        if(curr == NULL) curr = s->lane[i];

        while(curr->next[i] != NULL && curr->next[i]->val < key){
            curr = curr->next[i];
        }
    }

    //At this point curr->val < key <= curr->next[0]->val
    if(curr->next[0] != NULL && curr->next[0]->val == key) return curr->next[0];
    else return NULL;*/



    const unsigned int maxLanes = s->numLanes;
    int lane = maxLanes - 1;

    Node * curr = s->lane[lane];

    
    while(lane >= 0){
        
        if(curr == NULL) lane--;
        
        else if(curr->val == key) return curr;

        else if(curr->val < key){
            Node * nextCurr = curr->next[lane];

            if(nextCurr == NULL || nextCurr->val > key) lane--;

            else if(nextCurr->val == key) return nextCurr;
    
            else curr = nextCurr;

        }else {
            lane--;
            curr = s->lane[lane];
        }

    }
    return NULL;
}
