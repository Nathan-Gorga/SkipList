#include "file.h"

unsigned int serializeSkipList(Sentinel * s){
    FILE* file = fopen("skiplist.txt", "w");
    if (file == NULL) {
        perror("Cannot open file for writing");
        return 1;
    }

    Node* curr = s->lane[0]; // Niveau de base
    while (curr != NULL) {
        fprintf(file, "%d,%d\n", curr->val,curr->numLanes);
        curr = curr->next[0];
    }

    fclose(file);
    return 0;
}


unsigned int deserializeSkipList(Sentinel * s){
    FILE* file = fopen("skiplist.txt","r");
    if(file == NULL){
        perror("Cannot open file for reading");
        return 1;
    }

    int val, numLanes;
    
    while (fscanf(file, "%d,%d\n", &val, &numLanes) == 2) {
        if(fileToListNode(s, val, numLanes) == 1) return 1;
    }

    

    fclose(file);
}