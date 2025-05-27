#include "./includes/includes.h"
#include "./list/list.h"
#include "./utils/utils.h"
#include "./node/node.h"
#include "./sentinel/sentinel.h"

int main(){
    const unsigned int size = 10;
    unsigned int arr[] = {0,1,2,3,4,5,6,7,8,9};

    Node * head = createLinkedListFromArray(arr,size);

    
    Sentinel s = createSentinel(1);

    s.lane[0] = head;
    
    
    
    printList(s.lane[0],"L0");
    
    if (changeLaneToSentinel(2, &s) == 1){
        fprintf(stderr, "ERROR : Reallocation of memory to sentinel lanes has failed\n");
        return 1;
    } 

    
    printList(s.lane[1], "L1");
    

    
    

    freeNodes(head);
    freeSentinel(s);
    return 0;
}