	
		
    #include<stdio.h>
		#include<stdlib.h>
		#include<math.h>
    #include<string.h>
		
		
		
		int is_Prime(int num)
		{
			if(num == 1)
				return 1;
			int temp = sqrt(num);
			
			for(; temp>1; temp--)
			{
				if(num%temp == 0)
					return 0;
			}
			return 1;
		}

    int reverse(int num)
    {
      char temp[20];
      int n, index = 0;
      while(num > 0)
      {
        temp[index] = num%10 + '0';
        num /= 10;
        index++;
      }
      n = atoi(temp);
      return n;
    }
		
		
		
		int main()
		{
			int num1, num2, mark1, mark2;
			
			while(scanf("%d", &num1) == 1)
			{
				num2 = reverse(num1);
        mark1 = is_Prime(num1);
        mark2 = is_Prime(num2);

				if(!mark1)
					printf("%d is not prime.\n", num1);
				else if((mark1 && !mark2) || (mark1 && num1 == num2 && mark2))
					printf("%d is prime.\n", num1);
				else if(mark1 && mark2)			
					printf("%d is emirp.\n", num1);				
			}
			
			return 0;
		} 
