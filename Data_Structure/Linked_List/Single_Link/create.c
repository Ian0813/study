        


        #include<stdio.h>
        #include<stdlib.h>
        #include<time.h>

        struct node
        {
            int data;
            struct node *next;
        };
       

        struct node* generate(struct node *n, int data)
        {
            struct node *temp = NULL;
            
            temp = (struct node* ) malloc(sizeof(struct node));
            n->next = temp;
            temp->data = data;
            temp->next = NULL;
            n = n->next;
            temp = NULL;
            free(temp);
            return n;
        }
        
        
        struct node* crate()
        {
            struct node *temp;
            
            temp = (struct node*) malloc(sizeof(struct node));
            temp->data = 10;
            temp->next = NULL;
            return temp;
        }


        void traverse(struct node* n)
        {
            struct node *temp = NULL;
            temp = n;
            while(temp != NULL)
            {
                printf(" %d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }


        int main()
        {
            srand(time(NULL));
            int amount;
            struct node *head, *temp;
    
            head = crate();
            printf("Please enter an integer of amount : ");
            scanf("%d", &amount);
            temp = head;

            while(amount > 0)
            {
                temp = generate(temp, rand()%100);
                amount--;
            }            

            traverse(head);

            return 0;
        }




