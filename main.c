#include "./includes/includes.h"
#include "./build/list/list.h"
#include "./utils/utils.h"
#include "./build/node/node.h"
#include "./build/sentinel/sentinel.h"
#include "./algo/search/search.h"
#include "./memory/file/file.h"
#include "./trial/trial.h"


int main(){
    srand(time(NULL));
    

    // create link list
    const unsigned int size = 20;

    unsigned int * arr = malloc(sizeof(int) * size);

    for(int i =0; i < size; i++){
        arr[i] = i;
    }
    
    Node * head = createLinkedListFromArray(arr,size);
    

    
    // create sentinel
    Sentinel s1,s2;
    
    if(sentinel(head, &s1) == 1) return 1;
    srand(time(NULL));
    if(sentinel(head, &s2) == 1) return 1;

    printSkipList(s1);
    printSkipList(s2);


    
   


    Sentinel * winner = contest(&s1,&s2,size);

    char path[] ="C:\\Users\\gorga\\CodeProjects\\SkipList\\memory\\file\\storage\\skiplist.txt";
    if(serializeSkipList(winner,path) == 1) return 1;




    freeAll(*winner,arr);
    freeSentinel(s1);
    freeSentinel(s2);
    
    return 0;
}