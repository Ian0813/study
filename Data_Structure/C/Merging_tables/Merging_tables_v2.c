#include<stdio.h>
#include<stdlib.h>

int total, operation_times;
int dest, source;
int maximum = 0;

struct files{
    int data[100000], link[100000];
}file;

void MAX(int value){
    if(value > maximum)
        maximum = value;
}

void Makeset(){

    if(scanf("%d %d", &total, &operation_times) == EOF){
        exit(1);
    }
    
    for(int index = 0; index < total; index++){
        if(scanf("%d", &file.data[index]) == EOF){
            exit(1);
        }        
        if(maximum < file.data[index])
            maximum = file.data[index];
        file.link[index] = -1;
    }
}

// path compression
int Find_Link(int index){    
    int temp = index;
    while(file.link[temp] != -1){
        temp = file.link[index] = Find_Link(file.link[index]);
    }        
    return temp;
}

void Union(){

    if(file.link[source] != -1)
        source = Find_Link(source);

    if(file.link[dest] != -1)
        dest = Find_Link(dest);

    if(dest != source){                                                   
        file.link[source] = dest;
        file.data[dest] += file.data[source];
        MAX(file.data[dest]);
        file.data[source] = 0;
    }
    printf("%d\n", maximum);
}


int main(int argc, char *argv[]){

    Makeset();

    for(int index = 0; index < operation_times; index++){
        if(scanf("%d %d", &dest, &source) == EOF){
            exit(1);
        }
        // getchar();
        dest -= 1;
        source -= 1;
        if(dest != source){
            Union();
        }else{
            printf("%d\n", maximum);
        }            
    }    

    return 0;
}