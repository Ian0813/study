    

        #include <stdio.h>
        

        void main()
        {
            char n;
            int flag = 0;

            while ((n = getchar()) != '\n')
            {
                /* if n = blank character */
                if ( n == 32 && flag == 0 )  
                {
                    putchar(n);
                    flag = 1;
                }
                else if (n != 32)
                {
                    putchar(n);
                    flag = 0;
                }
            }
        }
