

#include "./utils/utils.h"

int main(){
    const unsigned int size = 10;
    unsigned int arr[] = {0,1,2,3,4,5,6,7,8,9};

    Node * head = createLinkedListFromArray(arr,size);

    
    Sentinel s = createSentinel(1);

    s.lane[0] = head;
    
    printList(s.lane[0],"L0");

    
    
    
    
    freeNodes(head);
    return 0;
}