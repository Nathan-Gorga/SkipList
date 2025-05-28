#include "list.h"
#include "../sentinel/sentinel.h"
#include "../utils/utils.h"
#include "../list/list.h"


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

        Node * curr= s->lane[counter]->next[counter]; // guarantees there are no duplicate lanes
      
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
            printf("ERROR : failed to add lane to node ()\n");
            return 1;
        case SENTINEL_ADD_LANE:
            printf("ERROR : failed to add lane to sentinel\n");
            return 1;        
    }
    s->numLanes--;

    return 0;

}



unsigned int fileToListNode(Sentinel * s, const int val, const int numLanes){
    Node * temp = createNode(val, numLanes);
    if(temp == NULL) return 1;
    

    while(numLanes > s->numLanes){
        sentinelPlusOneLane(s);
    }


    for(int i =0; i < numLanes; i++){//add it to the end of every lane it belongs to
        if(s->lane[i] == NULL) s->lane[i] = temp;
        else{

            Node* curr = s->lane[i];

            while(curr->next[i] != NULL){
                curr = curr->next[i];
            }

            curr->next[i] = temp;
        }
    }
    return 0;
}