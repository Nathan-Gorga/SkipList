#include "utils.h"
#include "../build/node/node.h"
#include "../build/sentinel/sentinel.h"

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

void printSpaces(const int num){
    for(int i =0; i < num; i++){
        printf(" ");
    }
}

void printSkipList(Sentinel s){
    const int maxLanes = s.numLanes;
    for(int i = 0; i < maxLanes; i++){
        printf("\033[0;92m L%d \033[0m|",i);
    }
    printf("\n");

    printArrows(maxLanes);

    Node * curr = s.lane[0];
    while(curr != NULL){
        for(int i = 0; i < maxLanes; i++){
            if(i +1 <= curr->numLanes){
                printf("\033[0;91m %d\033[0m",curr->val);
            }else{
                printf(" |");
            }
            const int defaultSpaces = 3;
            int numspaces = 0;
            if(curr->val != 0)
                numspaces = log10(curr->val);
            printSpaces(defaultSpaces-numspaces);
        }
        printf("\n");
        printArrows(maxLanes);
        curr = curr->next[0];
    }

    for(int i = 0; i < maxLanes; i++){
        printf("NULL ");
    }

}
