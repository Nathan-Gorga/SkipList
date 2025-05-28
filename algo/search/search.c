#include "search.h"

Node * recurSearch(const int key,const int lane,  Node* curr, Sentinel *s){
    
    printf("lane %d, val : %d\n", lane, curr->val);
    if(curr->val == key) return curr;//

    else if(lane < 0) return NULL;//

    else if(curr->val < key){

        Node * nextCurr = curr->next[lane];
        if(nextCurr == NULL){
            return recurSearch(key,lane-1, curr,s);
        }

        if(nextCurr->val == key) return nextCurr;

        else if(nextCurr->val > key){

            return recurSearch(key, lane-1, curr,s);

        }else{
            
            return recurSearch(key,lane,nextCurr,s);

        }
    }else{
        // if(curr->next[lane] != NULL)
        //     return recurSearch(key,lane,curr->next[lane],s);
        // else{
            return recurSearch(key,lane-1, s->lane[lane-1],s);
        // }
    }


}


Node* rSearchAlgo(const int key, Sentinel * s){
    const unsigned int maxLanes = s->numLanes;
    return recurSearch(key, maxLanes-1,s->lane[maxLanes-1],s);
}

Node * searchAlgo(const int key, Sentinel *s){// for now does, the job
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