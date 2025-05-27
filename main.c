

#include "./utils/utils.h"

int main(){
    const unsigned int size = 10;
    unsigned int arr[] = {0,1,2,3,4,5,6,7,8,9};

    Node * head = createLinkedListFromArray(arr,size);


    printList(head,"name");

    freeNodes(head);


    return 0;
}