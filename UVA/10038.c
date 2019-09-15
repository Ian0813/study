
	#include<stdio.h>
	#include<math.h>


	int main()
	{
		int n;
		
		while(scanf("%d", &n) == 1)
		{
			int temp[3000] = {0};
			int jolly[3000] = {0};
			int i, flag = 1;

			for(i = 1; i<=n; i++)
				scanf("%d", &temp[i]);

			for(i = 1; i <= n-1; i++)
				jolly[abs(temp[i+1] - temp[i])] = 1;
			
			for(i = 1; i <= n-1; i++)
			{
				if(jolly[i] == 0)
					flag = 0;
			}
			if(flag == 1)
				printf("Jolly");
			else if(flag == 0)
				printf("Not jolly");
			printf("\n");
		}
		return 0;
	}
