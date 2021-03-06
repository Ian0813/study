/*
 * =====================================================================================
 *
 *       Filename:  1-14.c
 *
 *    Description:  Write a program to print a histogram of the frequencies of different characters in its input.
 *
 *        Version:  1.0
 *        Created:  2020年08月07日 11時05分48秒
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
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

/* print horizontal histogram freq. of different characters */

int main()
{
	int c, i;
	int len;   /* length of each bar */
	int maxvalue; /* maximum value for cc[] */
	int cc[MAXCHAR];  /* character counters */

	for(i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	// memset(cc, 0, sizeof(int) * MAXCHAR);
	
	while((c = getchar()) != EOF)
		if(c < MAXCHAR)
			++cc[c];
	maxvalue = 0;

	for(i = 1; i < MAXCHAR; ++i)
		if(cc[i] > maxvalue)
			maxvalue = cc[i];
	
	for(i = 1; i < MAXCHAR; ++i)
	{
		if(isprint(i))
			printf("%5d - %c - %5d : ", i, i, cc[i]);
		else
			printf("%5d -   - %5d : ", i, cc[i]);
		if(cc[i] > 0)
		{
			if((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
			printf("len = %d", len);
		}else
			len = 0;
		while( len > 0 )
		{
			//putchar('*');
			printf("*");
			--len;
		}
		putchar('\n');
	}
}

