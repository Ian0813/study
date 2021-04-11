#include<stdio.h>
#include<bits/stdint-intn.h>
#include "API_Set.h"
#define MAXLINE 1000 /* maximum input line */
int32_t max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */


int32_t Getline_extern(void);
void Copy_extern(void);


/* print longest input line */
int main(int argc, char *argv[]){
    int32_t len; /* current line length */

    max = 0;
    while((len = Getline_extern()) > 0){
        if(len > max){
            max = len;
            Copy_extern();
        }
    }
    
    if(max > 0)  /* there was a line */
        printf("%s", longest);
    return 0;
}

