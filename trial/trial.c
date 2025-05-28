#include "trial.h"
#define REPEAT 10

double oneTrial(Sentinel * s, const int size){
    srand(time(NULL));
    
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);


    for(int i = 0; i < REPEAT; i++){
        const int findThisNum = rand() % size;

        printf("%d) looking for %d...\n",i+1,findThisNum);

        Node * res = searchAlgo(findThisNum,s);

        if(res == NULL) printf("%d) node %d not found\n\n",i+1,findThisNum);

        else printf("%d) node %d found\n\n",i+1, res->val);

    }

    QueryPerformanceCounter(&end);

    double elapsed_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    return elapsed_ms / REPEAT;
}



Sentinel * contest(Sentinel * s1, Sentinel * s2,const int size){
    double avgTime1 = oneTrial(s1,size);
    double avgTime2 = oneTrial(s2,size);
    printf("Average time for S1 : %.3f ms\n\n\n", avgTime1);
    printf("Average time for S2 : %.3f ms\n\n\n", avgTime2);

    return avgTime1 <= avgTime2 ? s1 : s2;
}