

    #include<stdio.h>
    #include<time.h>
    #include<stdlib.h>
    #include "./C.h"

  




    struct node* create(struct node *n)
    {
         n = (struct node*) malloc(sizeof(struct node));
         n->data = rand()%100;
         n->next = n;
         return n;
    }    

    void generate(struct node *n)
    {
        struct node *temp, *new;
        new = (struct node*) malloc(sizeof(struct node));
        new->data = rand()%100;
        new->next = NULL;
        temp = n;
        while(temp->next != n)
            temp = temp->next;
        temp->next = new;
        new->next = n;
    }

    void traverse(struct node *n)
    {
        struct node *temp;
        temp = n;
        while(temp->next != n)
        {
             printf("%d  ", temp->data);
             temp = temp->next;
        }
        printf("%d  \n", temp->data);
    }

    void insert_to(struct node *n, int data)
    {
        struct node *temp, *new;
        temp = n;
        while(temp->data != data && temp->next != n)
        {
            temp = temp->next;
        }
        if(temp->data != data)
            return;
        
        new = (struct node*) malloc(sizeof(struct node));
        new->data = rand()%100;
        new->next = temp->next;
        temp->next = new;
    }
    
    void delete(struct node *n, int data)
    {
        struct node *temp1, *temp2;
        temp1 = n;
        temp2 = n->next;
        
        while(temp1->next != n && temp2->data != data)
        {
            temp1 = temp2;
            temp2 = temp1->next;
        }   
        
        if(temp1->next == n && temp2->data != data)
            return;
        else
        {
            temp1->next = temp2->next;
            free(temp2);
        }
    }

    int main()
    {
        struct node *head;

        srand(time(NULL));
        int amount, action, temp_num;
        head = create(head);
        traverse(head);
        printf("Please enter a number so decide the length of link: \n");
        scanf("%d", &amount);

        while(amount > 0)
        {
            generate(head);
            amount--;
        }    
        
        while(1)
        {
            printf("Please enter a number inform what you want to do : \n");
            scanf("%d", &action);
            
            if(action == 1)
                traverse(head);
            else if(action == 2)
            {
                printf("Please enter a number into the function : \n");
                scanf("%d", &temp_num);
                insert_to(head, temp_num);
            }
            else if(action == 3)
            {
                printf("Please enter a number then delete it : \n");
                scanf("%d", &temp_num);
                delete(head, temp_num);
            }
            else if(action == 4)
                length(head);
        }
        return 0;
    }
