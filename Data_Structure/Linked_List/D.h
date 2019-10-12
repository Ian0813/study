        #include<stdio.h>
        #include<stdlib.h>
        struct node{
            int data;
            struct node *previous, *next;
        }


        struct node* create(struct node *n)
        {
            n = (struct node*) malloc(sizeof(struct node));
            n->data = rand()%100;
            n->next = 
        }

        void insert(struct node *n)
        {
            struct node *temp;
            temp = (struct node*) malloc(sizeof(struct node));
            temp->data = rand()%100;
            (n->previous)->next = temp;
            temp->previous = n->previous;
            temp->next = n;
            n->previous = temp
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
                    return n;
                }
            } 
            else
            {
                (n->previous)->next = n->next;
                (n->next)->previous = n->previous;          
                return n;
            }               
        }
