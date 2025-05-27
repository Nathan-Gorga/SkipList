#include "list.h"
#include "../sentinel/sentinel.h"
#include "../utils/utils.h"


Node* createLinkedListFromArray(unsigned int * arr, const unsigned int size){
    Node * head = createNode(arr[0],1);

    Node * curr = head;
    const unsigned int numPtrs = 1;
    for(unsigned int i = 1; i < size; i++){
        curr->next[0] = createNode(arr[i],numPtrs);
        curr = curr->next[0];
    }

    return head;
}


unsigned int buildSkipList(Sentinel * s){
    
    if(sentinelPlusOneLane(s) == 1) return 1;

    Node * curr = s->lane[0];
    Node * L1_ptr = NULL;
    
    while(curr != NULL){
        
        if(coinFlip()){
            if(nodePlusOneLane(curr) == 1) return 1;
            if(L1_ptr != NULL){
                L1_ptr->next[1] = curr;
                L1_ptr = L1_ptr->next[1];
            }else{
                s->lane[1] = curr;
                L1_ptr = s->lane[1];
            }
            
        }

        
        curr = curr->next[0];
    }

    return 0;
}

