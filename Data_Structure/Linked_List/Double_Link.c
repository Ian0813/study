        
        #include<stdio.h>
        #include<stdlib.h>
        #include"./D.h"
        #include<time.h>

        int main
        {
            struct node *head;

            head = create();

            int action, amount;
            srand(time(NULL));
            printf("Please enter number od amount : ");
            scanf("%d", &amount);
            while(amount != 0)
            {
                generates(head, rand()%100);
                amount--;
            }
            
            while(1)
            {
                printf("For what you want to do, please enter a number. \n 1.Insert \n 2.Delete \n 3.Traverse \n");
                scanf("%d", &action);
                fflush(stdin);
                
                if(action == 1)
                    insert(head, rand()%100);
                else if(action == 2)
                    head = delete(head);
                else if(action == 3)
                    traverse(head);
                
            }        
        }
