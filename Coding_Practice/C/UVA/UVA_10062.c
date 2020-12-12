
	#include<stdio.h>

	int output(int *);


	int main()
	{
		int c, newline;
		int ary[96] = {0};

		newline = 0;

		while((c = getchar()) != EOF)
		{
			if(c > 31 && c < 128)
				ary[c - 32]++;
			if(c == '\n')
			{
				if(++newline > 1)
					printf("\n");
				while(output(ary));

			}
		}

		return 0;
	}

	/* output : 輸出排序後的結果 */

	int output(int *s)
	{
		int i, j, min;

		for(min = 1001, i = 95; i > -1; i--)
			if(min > s[i] && s[i] > 0)
			{
				min = s[i];
				j = i;
			}
		if(min == 1001)
			return 0;
		printf("%d %d\n", j + 32, min);
		s[j] = 0;
		return 1;
	}
