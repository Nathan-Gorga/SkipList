#include "./includes/includes.h"
#include "./build/list/list.h"
#include "./utils/utils.h"
#include "./build/node/node.h"
#include "./build/sentinel/sentinel.h"

#include "./algo/search/search.h"



int main(){
    srand(time(NULL));


    const unsigned int size = 10;
    unsigned int arr[] = {0,1,2,3,4,5,6,7,8,9};

    Node * head = createLinkedListFromArray(arr,size);

    
    Sentinel s = createSentinel(1);

    s.lane[0] = head;
    

    

    if(callBuildSkipList(&s) == 1) {
            
        return 1;

    }
    printSkipList(s);

    
    freeAll(s);

    return 0;
}