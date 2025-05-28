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


    Sentinel s;
    if(sentinel(head, &s) == 1) return 1;


    printSkipList(s);

    Node * keyNode = searchAlgo(6,&s);
    if(keyNode == NULL){
        printf("key not present in list\n");
    }else{
        printf("key %d found \n",keyNode->val);
    }





    
    freeAll(s);

    return 0;
}