#include "./includes/includes.h"
#include "./build/list/list.h"
#include "./utils/utils.h"
#include "./build/node/node.h"
#include "./build/sentinel/sentinel.h"
#include "./algo/search/search.h"
#include "./memory/file/file.h"



int main(){
    srand(time(NULL));

    
    const unsigned int size = 10;
    unsigned int * arr = malloc(sizeof(int) * size);
    for(int i =0; i < size; i++){
        arr[i] = i;
    }
    
    Node * head = createLinkedListFromArray(arr,size);
    
    
    
    Sentinel s;
    
    if(sentinel(head, &s) == 1) return 1;

    if(serializeSkipList(&s) == 1) return 1;

    printSkipList(s);
    freeAll(s,arr);

    Sentinel s1 = createSentinel(1);
    
    if(deserializeSkipList(&s1) == 1) return 1;

    printSkipList(s1);

    freeSentinel(s1);
    
    return 0;
}