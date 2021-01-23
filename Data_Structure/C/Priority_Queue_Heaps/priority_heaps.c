#include<stdio.h>
#include<stdlib.h>
#include "priority_heaps.h"


int main(int argc, char *argv[]){

    char action;
    int value;

    if(argc < 3){
        printf("Please enter the correct amount of arguments.\n");
        exit(1);
    }else{        
        maxSize = atoi(argv[1]);
        size = atoi(argv[2]);
        queue = (int *) malloc(sizeof(int) * maxSize);
    }

    Create_Queue();

    List_Queue();    

    while(1){
        printf("Insert  : i\n");
        printf("Extract : e\n");
        printf("Remove  : r\n");
        printf("View    : v\n");
        if(scanf("%c", &action) == EOF)
            exit(1);
        getchar();

        switch(action){

            case 'i':
                printf("Enter a value for insert to queue : \n");
                if(scanf("%d", &value) == EOF)
                    exit(1);
                getchar();
                Insert(value);
                break;

            case 'e':
                printf("ExtractMAx result : %d\n", ExtractMax());
                break;
            
            case 'r':
                printf("Enter a value for remove from a queue : \n");
                if(scanf("%d", &value) == EOF)
                    exit(1);
                getchar();
                if(Remove(value) == MAX_VAL)
                    printf("Remove success.\n");
                break;            
            case 'v':
                List_Queue();
                break;
        }
    }

    return 0;

}


