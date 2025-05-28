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



Node * linearSearch(const int key, Sentinel * s){
    Node * curr = s->lane[0];

    while(curr != NULL){
        if(curr->val == key) return curr;
        curr = curr->next[0];
    }

    return NULL;



}



Node * searchAlgo(const int key, Sentinel *s){// new algo
    
    const int maxLevel = s->numLanes -1;
    Node * curr = s->lane[maxLevel];

    for(int i = maxLevel; i >=0; i--){
        if(curr == NULL) curr = s->lane[i];

        while(curr->next[i] != NULL && curr->next[i]->val < key){
            curr = curr->next[i];
        }
    }

    //At this point curr->val < key <= curr->next[0]->val
    if(curr->next[0] != NULL && curr->next[0]->val == key)return curr->next[0];
    else return NULL;
}
