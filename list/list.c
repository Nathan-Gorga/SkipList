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
    
    unsigned int counter = 0;
    while(s->lane[counter] != NULL){

        if(sentinelPlusOneLane(s) == 1) return SENTINEL_ADD_LANE;

        Node * curr = s->lane[counter];
        Node * Lane_ptr = NULL;
        
        while(curr != NULL){
            
            if(coinFlip()){
                if(nodePlusOneLane(curr) == 1) return NODE_ADD_LANE;

                if(Lane_ptr != NULL){
                    Lane_ptr->next[counter + 1] = curr;
                    Lane_ptr = Lane_ptr->next[counter +1];
                }else{
                    s->lane[counter +1] = curr;
                    Lane_ptr = s->lane[counter +1];
                }   
            }
            curr = curr->next[counter];
        }
        counter++;
    }
    return 0;
}



unsigned int callBuildSkipList(Sentinel *s){
    const int temp = buildSkipList(s);
    switch(temp){
        case NODE_ADD_LANE:
            printf("ERROR : failed to add lane to node\n");
            return 1;
        case SENTINEL_ADD_LANE:
            printf("ERROR : failed to add lane to sentinel\n");
            return 1;        
    }
    return 0;
}