    

    #include <stdio.h>

    void main()
    {
        char n;
        int count = 0;
        
        while ((n = getchar()) != EOF)
            if (n == 9 || n == 32 || n == 10)
                count++;
        printf("Total : %d\n", count);
    
    }

