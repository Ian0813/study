#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int size, backup;
int maxSize;
int *queue;


void Swap(int *val1, int *val2){
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int Left_Child(int number){
    return 2 * number;
}

int Right_Child(int number){
    return 2 * number + 1;
}

void SiftDown(int number){
    int maxIndex, left, right;
    maxIndex = number;
    left = Left_Child(number);
    right = Right_Child(number);

    if(left < size &&  queue[left] > queue[maxIndex])
        maxIndex = left;
    
    if(right < size &&  queue[right] > queue[maxIndex])
        maxIndex = right;
    
    if(number != maxIndex){
        Swap(&queue[number], &queue[maxIndex]);
        SiftDown(maxIndex);
    }
}


void BuildHeap(){
    int index;
    for(index = (size - 1)/2; index >= 0; index--){
        SiftDown(index);
    }
}

void Create_Array(){    

    for(int index = 0; index < size; index++){
        queue[index] = rand() % 100 + 1;
        printf("\t index[%d] : %d", index, queue[index]);
    }
    putchar(10);
}


void List_Queue(){
    if(size == 0)
        size = backup;
    if(size > maxSize){
        printf("The queue size exceeds the maximum.\n");
    }

    for(int index = 0; index < size; index++){
        printf("\t[%2d] : %2d", index, queue[index]);
    }
    printf("\n");
}

void HeapSort(){
    backup = size;
    while(size > 0){
        Swap(&queue[0], &queue[size - 1]);
        size -= 1;
        SiftDown(0);
    }
}
