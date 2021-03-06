        #include<stdio.h>
        #include<stdlib.h>
        struct node{
            int data;
            struct node *previous, *next;
        };


        struct node* create(struct node *n, int data)
        {
            n = (struct node*) malloc(sizeof(struct node));
            n->data = data;
            n->next = n;
            n->previous = n;
            return n;
        }

        void generates(struct node *n, int data)
        {
                struct node *temp, *new;
                new = (struct node*) malloc(sizeof(struct node));
                new->data = data;
                new->previous = new->next = NULL;
                temp = n;
                while(temp->next != n)
                        temp = temp->next;
                (temp->next)->previous = new;
                new->next = temp->next;
                temp->next = new;
                new->previous = temp;     
        }

        void insert(struct node *n, int data)
        {
            struct node *temp;
            temp = (struct node*) malloc(sizeof(struct node));
            temp->data = data;
            (n->previous)->next = temp;
            temp->previous = n->previous;
            temp->next = n;
            n->previous = temp;
        }

        struct node* delete(struct node *n, int data)
        {
            struct node *temp; 
            temp = n->next;
            if(n->data != data)
            {
                while(temp->data != data && temp != n)
                {
                    temp = temp->next;
                }
                if(temp == n)   
                    return n;
                else 
                {
                    (temp->previous)->next = temp->next;
                    (temp->next)->previous = temp->previous;
                    free(temp);
                    return n;
                }
            } 
            else
            {
                (n->previous)->next = n->next;
                (n->next)->previous = n->previous;
                free(n);          
                return temp;
            }               
        }

        void traverse(struct node *n)
        {
            struct node *temp;
            printf("%d ", n->data);
            temp = n->next;
            while(temp != n)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
