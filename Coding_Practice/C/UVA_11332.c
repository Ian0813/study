

    #include<stdio.h>
    #include<stdlib.h>



    int main()
    {
        int n;

        while(scanf("%d", &n) == 1)
        {
            if(n == 0)
                break;
 
            repeat:;
            
            int sum = 0, temp = 0;
            while( n > 0)
            {
                temp = n%10;
                sum += temp;
                n /= 10;
            }

            if(sum < 10)
                printf("%d\n", sum);
            else if(sum >= 10)
            {
                n = sum;
                goto repeat;
            }  
        }
        return 0;
    }

