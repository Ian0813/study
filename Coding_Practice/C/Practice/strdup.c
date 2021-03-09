/*
 * =====================================================================================
 *
 *       Filename:  strdup.c
 *
 *    Description:  Practice API strdup() and toupper()
 *
 *        Version:  1.0
 *        Created:  2021年03月07日 18時51分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char *argv[]){

    if(argc > 1){
        char *str = strdup(argv[1]);
        char *c;
        printf("str address : %p, argv[1] address : %p\n", str, &argv[1]);
        printf("Duplicate the passed string : %s, pass string : %s\n", str, argv[1]);
        for(c = str; *c != '\0'; c++){
            *c = toupper(*c);            
        }
        printf("Uppercase : %s.\n", str);
    }else{
        fprintf(stderr ,"Usage %s [string] to execute.\n", argv[0]);
    }

    return 0;
}

