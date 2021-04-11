/*
 * =====================================================================================
 *
 *       Filename:  Count.c
 *
 *    Description:  K&R Book Page 22
 *
 *        Version:  1.0
 *        Created:  2020年08月05日 15時54分40秒
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

/* count digits , white, space, others */

int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	memset(ndigit, 0, sizeof(int) * 10);

	while( (c = getchar()) != EOF )
		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if(c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else 
			++nother;

	printf("digits = ");
	for(i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
	
