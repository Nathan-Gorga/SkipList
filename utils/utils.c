#include "utils.h"




void printList(Node * list, char * name){
    Node * curr = list;
    printf("%s : ", name);
    while(curr != NULL){
        printf("%d -> ",curr->val);
        curr = curr->next[0];
    }
    printf("NULL\n");
}


