#include "utils.h"
#include "../node/node.h"
#include "../sentinel/sentinel.h"

void printList(Node * list, const unsigned int lane,char * name){
    Node * curr = list;
    
    printf("%s : ", name);
    
    while(curr != NULL){
        printf("%d -> ",curr->val);
    
        curr = curr->next[lane];
    }
    
    printf("NULL\n");
}

void freeAll(Sentinel s){
    freeNodes(s.lane[0]);
    freeSentinel(s);
}


bool coinFlip(){
    return (rand() % 2) == 0;
}


void printArrows(const int size){
    for(int i = 0; i < size; i++){
        
        printf(" |   ");
    }
    printf("\n");
    for(int i = 0; i < size; i++){

        printf(" v   ");
    }
    printf("\n");
   
    
}

void printSkipList(Sentinel s){
    const int maxLanes = s.numLanes;
    for(int i = 0; i < maxLanes; i++){
        printf(" L%d |",i);
    }
    printf("\n");

    printArrows(maxLanes);

    Node * curr = s.lane[0];
    while(curr != NULL){
        for(int i = 0; i < maxLanes; i++){
            if(i +1 <= curr->numLanes){
                printf(" %d   ",curr->val);
            }else{
                printf(" |  ");
            }
        }
        printf("\n");
        printArrows(maxLanes);
        curr = curr->next[0];
    }

    for(int i = 0; i < maxLanes; i++){
        printf("NULL ");
    }
}
