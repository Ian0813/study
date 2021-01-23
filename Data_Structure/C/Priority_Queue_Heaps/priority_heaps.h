

#define MAX_VAL 99999

int maxSize, size;
int *queue;


int Parent(int number){
    return number / 2;
}

int Left_Child(int number){
    return 2 * number;
}

int Right_Child(int number){
    return 2 * number + 1;
}

void Swap(int *value1, int *value2){
    int temp;
    temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void Create_Queue(){
    if(size > maxSize){
        printf("The queue size exceeds the maximum.\n");
    }

    for(int index = 0; index < size; index++){        
        printf("Input a value for [%2d]\n", index);
        if(scanf("%d", &queue[index]) == EOF){
            perror("scanf : ");
            exit(1);
        }else if(index > 0){
            while(queue[index] > queue[Parent(index)] || queue[index] > MAX_VAL){
                getc(stdin);
                printf("Please enter a value again.\n");
                if(scanf("%d", &queue[index]) == EOF){
                    perror("scanf : ");
                    exit(1);
                }
            }
        }
        getc(stdin); // To eliminate the enter key in the standard input.
    }
}

void List_Queue(){
    if(size > maxSize){
        printf("The queue size exceeds the maximum.\n");
    }

    for(int index = 0; index < size; index++){
        printf("\t[%2d] : %2d\n", index, queue[index]);
    }
}

void SiftUp(int number){
    while(number > 0 && queue[Parent(number)] < queue[number]){
        Swap(&queue[Parent(number)], &queue[number]);
        number = Parent(number);
    }
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

void Insert(int value){
    if(value > MAX_VAL){
        printf("Value too large.\n");
        exit(1);
    }
    if(size > maxSize){
        printf("Over the size of queue.\n");
        exit(1);
    }    
    queue[size] = value;
    SiftUp(size);
    size += 1;
}

int ExtractMax(){
    int result = queue[0];
    queue[0] = queue[size-1];    
    SiftDown(0);
    size -= 1;
    return result;
}

int Remove(int number){
    queue[number] = MAX_VAL;
    SiftUp(number);
    return ExtractMax(number);
}

