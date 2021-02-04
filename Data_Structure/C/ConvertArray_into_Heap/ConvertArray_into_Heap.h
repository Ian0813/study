#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))


int *arr;
int length;
int times;
int *loc_1, *loc_2;
int index_loc = -1;

void Swap(int *val1, int *val2){    
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    times++;
}

int Parent(int index){
    if(index != 0)
        return ((index + 1) / 2) - 1;
    else
        return index;
}

int Right_Child(int index){
    return ((index + 1) * 2 + 1) - 1;
}

int Left_Child(int index){
    return ((index + 1) * 2) - 1;
}

void SiftDown(int index){    
    int mini = index;
    int rindex = Right_Child(index);
    int lindex = Left_Child(index);

    if(rindex < length && arr[mini] > arr[rindex]){
        mini = rindex;
    }

    if(lindex < length && arr[mini] > arr[lindex]){
        mini = lindex;
    }
             
    if(index != mini){        
        Swap(&arr[index], &arr[mini]);
        index_loc++;
        loc_1[index_loc] = index;
        loc_2[index_loc] = mini;     
        SiftDown(mini);
    }
}
void Array_Initialize(){

    if(scanf("%d", &length) == EOF){
        perror("scanf : ");
        printf("LINE %d\n", __LINE__);
        exit(1);
    }else{
        arr = (int *) malloc(sizeof(int) * length);
        loc_1 = (int *) malloc(sizeof(int) * length);
        loc_2 = (int *) malloc(sizeof(int) * length);
    }

    for(int index = 0; index < length; index++){
        if(scanf("%d", &arr[index]) == EOF){
            perror("scanf : ");
            printf("LINE %d\n", __LINE__);
            exit(1);
        }
    }
}

void BuildHeap(){
    int index;
    for(index = length/2; index >=0; index--){
        SiftDown(index);
    }
}

void Convert_To_Heap(){
    int index;
    
    BuildHeap();

    printf("%d\n", times);
    for(index = 0; index <= index_loc; index++){
        printf("%d %d\n", loc_1[index], loc_2[index]);
    }
}

void List_Array(){
    for(int index = 0; index < length; index++){
        printf("index[%d] : %d ", index, arr[index]);
    }
    printf("\n");
}

