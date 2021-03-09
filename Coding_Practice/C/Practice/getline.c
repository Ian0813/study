/*
 * =====================================================================================
 *
 *       Filename:  getline.c
 *
 *    Description:  j
 *
 *        Version:  1.0
 *        Created:  2021年03月03日 09時37分03秒
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
#include<string.h>


int main() {
    // Write C code here
    char *str = NULL;
    size_t num = 0;
    ssize_t nread = 0;
    nread = getline(&str, &num, stdin);
    printf("%s", str);
    
    return 0;
}
