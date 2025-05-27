#include "utils.h"
#include "../node/node.h"
#include "../sentinel/sentinel.h"

void printList(Node * list, char * name){
    Node * curr = list;
    
    printf("%s : ", name);
    
    while(curr != NULL){
        printf("%d -> ",curr->val);
    
        curr = curr->next[0];
    }
    
    printf("NULL\n");
}

void freeAll(Sentinel * s){
    for(int i = 0; i < s->numLanes; i++)
    {
        freeNodes(s->lane[i]);
    }
    freeSentinel(*s);
}
