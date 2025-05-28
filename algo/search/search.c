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
