

       #include<stdio.h>
       #include<string.h>
       #include<math.h>
       
   
       int is_Prime(long long num)
       {
           long long temp =(long long) sqrt(num);
           if(num == 1)
            return 1;
  
            for(temp; temp>1; temp--)
            {
                if(num%temp == 0)
                  return 0;
            
                
            }
          return 1;
       }
      
      long long reverse(long long num)
      {
          char temp[10] = {0};
          long long  index = 0;
          long long t;
          
          while(num > 0)
          {
              temp[index] = (num%10) + 48;
              num /= 10;
              index++;
          }
          t = atoi(temp);
          

          return t;
      }
      
    
      
  
      int main()
      {
          long long num1, num2;
          while(scanf("%lld", &num1))
          {
              int a, b;
              num2 = reverse(num1);
              a = is_Prime(num1);
              b = is_Prime(num2);
              
              if(!a)
                  printf("%lld is not prime.\n", num1);
              else if(a && !b)
                  printf("%lld is prime.\n", num1);
              else if(a && b && a == b)
                  printf("%lld is prime.\n", num1);
              else if(!a && !b && a != b)
                  printf("lld is emirp.\n", num1);
          }
          return 0;
      }

