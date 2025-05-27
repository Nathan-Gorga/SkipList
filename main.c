#include "./includes/includes.h"
#include "./list/list.h"
#include "./utils/utils.h"
#include "./node/node.h"
#include "./sentinel/sentinel.h"

int main(){
    srand(time(NULL));


    const unsigned int size = 10;
    unsigned int arr[] = {0,1,2,3,4,5,6,7,8,9};

    Node * head = createLinkedListFromArray(arr,size);

    
    Sentinel s = createSentinel(1);

    s.lane[0] = head;
    
    if(buildSkipList(&s) == 1) return 1;
    
    printList(s.lane[1],1,"L1");
    
    freeAll(s);

    return 0;
}