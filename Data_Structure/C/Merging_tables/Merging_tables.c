#include<stdio.h>
#include<stdlib.h>

int total, operation_times;
int dest, source;
int maximum = 0;

struct files{
    int *data, *link;
}file;


void MAX(int value){
    if(value > maximum)
        maximum = value;
}

int main(int argc, char *argv[]){

    if(scanf("%d %d", &total, &operation_times) == EOF){
        exit(1);
    }

    file.data = (int *) malloc(sizeof(int)*total);
    file.link = (int *) malloc(sizeof(int)*total);

    for(int index = 0; index < total; index++){
        if(scanf("%d", &file.data[index]) == EOF){
            exit(1);
        }        
        if(maximum < file.data[index])
            maximum = file.data[index];
        file.link[index] = -1;
    }

    for(int index = 0; index < operation_times; index++){
        int temp;
        int dest_2;
        if(scanf("%d %d", &dest, &source) == EOF){
            exit(1);
        }
        getchar();
        dest -= 1;
        source -= 1;
        if(dest != source){
            if(file.link[source] == -1){
                if(file.link[dest] == -1){
                    file.link[source] = dest;
                    file.data[dest] += file.data[source];
                    MAX(file.data[dest]);
                    file.data[source] = 0;
                }else{
                    dest_2 = file.link[dest];
                    while(file.link[dest_2] != -1){
                        temp = file.link[dest_2];
                    }
                    dest = dest_2;
                    if(dest == source){                        
                        printf("%d\n", maximum);
                        continue;
                    }else{
                        file.link[source] = dest;
                        file.data[dest] += file.data[source];
                        MAX(file.data[dest]);
                        file.data[source] = 0;
                    }
                }
            }else{
                temp = file.link[source];                
                while(file.link[temp] != -1){
                    temp = file.link[temp];
                }
                source = temp;
                if(file.link[dest] != -1){
                    dest_2 = file.link[dest];
                    while(file.link[dest_2] != -1){
                       dest_2 = file.link[dest_2];
                    }
                    dest = dest_2;
                }
                if(source == dest){
                    printf("%d\n", maximum);
                    continue;
                }else{
                    file.data[dest] += file.data[source];
                    MAX(file.data[dest]);
                    file.data[source] = 0;
                    file.link[source] = dest;
                }
            }
        }
        printf("%d\n", maximum);
    }    
    return 0;
}