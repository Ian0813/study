            

        #include<stdio.h>
        
        
        /* print Fahrenheit-Celsius table 
            for fahr = 0, 20, ..., 300 */
        
        void main()
        {
            float fahr, celsius, _fahr;
            int lower, upper, step;

            lower = 0;   /* lower limit of temperature table */
            upper = 300; /* upper limit */
            step = 20;   /* step size */
            
            fahr = lower;
            while (fahr <= upper) {
                celsius = (5.0/9.0) * (fahr-32.0);
                printf("%3f %6f\t | ", fahr, celsius);
                fahr = fahr + step;
                _fahr = (celsius*9) / 5 + 32;
                printf(" %3.1f\n", _fahr);
            }
        }
