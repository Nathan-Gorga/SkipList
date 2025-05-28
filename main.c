#include "./includes/includes.h"
#include "./build/list/list.h"
#include "./utils/utils.h"
#include "./build/node/node.h"
#include "./build/sentinel/sentinel.h"
#include "./algo/search/search.h"
#include "./memory/file/file.h"



int main(){
    srand(time(NULL));
    

    // create link list
    const unsigned int size = 10;

    unsigned int * arr = malloc(sizeof(int) * size);

    for(int i =0; i < size; i++){
        arr[i] = i;
    }
    
    Node * head = createLinkedListFromArray(arr,size);
    

    
    // create sentinel
    Sentinel s;
    
    if(sentinel(head, &s) == 1) return 1;

    char path[] ="C:\\Users\\gorga\\CodeProjects\\SkipList\\memory\\file\\storage\\skiplist.txt";
    if(serializeSkipList(&s,path) == 1) return 1;




    freeAll(s,arr);

    
    return 0;
}