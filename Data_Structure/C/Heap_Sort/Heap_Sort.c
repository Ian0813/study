#include<stdio.h>
#include<stdlib.h>
#include "Heap_Sort.h"



int main(int argc, char *argv[]){

    srand(time(NULL));

    if(argc < 3){
        printf("Please enter a correct amount.\n");
    }else{
        maxSize = atoi(argv[1]);
        size = atoi(argv[2]);        
        queue = (int *) malloc(sizeof(int) * maxSize);
    }

    Create_Array();
    BuildHeap();
    List_Queue();
    HeapSort();
    List_Queue();

    return 0;
}