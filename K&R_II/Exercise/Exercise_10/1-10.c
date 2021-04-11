

        #include <stdio.h>


        void main()
        {
            char n;
            while ((n = getchar()) != EOF)
            {
                switch (n)
                {
                    case '\t':
                        printf("\\t");
                        break;
                    case '\b':
                        printf("\\b");
                        break;
                    case '\\':
                        printf("\\\\");
                        break;
                    default:
                        putchar(n);
                        break;
                }
            }
        }
