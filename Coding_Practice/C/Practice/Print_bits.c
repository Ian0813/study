#include <stdio.h>
#include<stdlib.h>

int main() {
    // Write C code here
    int i = 14, k;
    int arr[8];
    for(k = 0; k < 8; k++){
        printf("The %d bit: %d\n", (k+1), ((i >> k) & 1));
        arr[k] = ((i >> k) & 1);
    }
    printf("\n--------------------------------------\n");
    printf("The 1 - 8 bit: ");
    for(k = (8-1); k >= 0; k--){
        printf("%d ", arr[k]);
    }
    putchar(10);
    return 0;
}
