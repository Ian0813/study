        
        #include<stdio.h>
        #include<stdlib.h>

        struct node{
            int data;
            struct node *next;
        };
        void length(struct node *n)
        {   
            struct node *temp;
            int len = 0;
            temp = n;
            while(temp->next != n)
            {
                len++;
                temp = temp->next;
            }
            len++;
            printf("The length of link is %d. \n", len);
        }
