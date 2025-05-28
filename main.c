#include "./includes/includes.h"
#include "./build/list/list.h"
#include "./utils/utils.h"
#include "./build/node/node.h"
#include "./build/sentinel/sentinel.h"

#include "./algo/search/search.h"



int main(){
    srand(time(NULL));

    LARGE_INTEGER freq, start, end;
    
    const unsigned int size = 100;
    unsigned int * arr = malloc(sizeof(int) * size);
    for(int i =0; i < size; i++){
        arr[i] = i;
    }
    
    Node * head = createLinkedListFromArray(arr,size);
    
    const int findThisNum = rand() % (size);
    printf("looking for %d...\n",findThisNum);

    QueryPerformanceFrequency(&freq);
    
    
    Sentinel s;
    
    if(sentinel(head, &s) == 1) return 1;

    QueryPerformanceCounter(&start);
    
    Node * keyNode = searchAlgo(findThisNum,&s);

    if(keyNode == NULL){

        printf("\nkey not present in list\n");

    }else{

        printf("\nkey %d found \n",keyNode->val);

    }

    QueryPerformanceCounter(&end);

    double elapsed_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;

    printf("time taken for skiplist(%d) search algo : %.3f ms\n",size, elapsed_ms);
    
    QueryPerformanceCounter(&start);


    Node * keyNodeL = linearSearch(findThisNum,&s);

    if(keyNodeL == NULL){

        printf("\nkey not present in list\n");

    }else{

        printf("\nkey %d found \n",keyNodeL->val);

    }

    QueryPerformanceCounter(&end);

    elapsed_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;

    printf("time taken for linear list(%d) search algo : %.3f ms\n",size, elapsed_ms);


    freeAll(s,arr);

    return 0;
}