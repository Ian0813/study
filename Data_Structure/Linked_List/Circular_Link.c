

    #include<stdio.h>
    #include<time.h>
    #include<stdlib.h>

    struct node{
        int data;
        struct node *next;
    };

    struct node* create(struct node *n)
    {
         n = (struct node*) malloc(sizeof(struct node));
         n->data = rand()%100;
         n->next = n;
         return n;
    }    

    void generate(struct node *n, int data)
    {
        struct node *temp, *new;
        new = (struct node*) malloc(sizeof(struct node));
        new->data = data;
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
            printf("%d  ", temp->data);
        printf("%d  \n", temp->data);
    }

    int main()
    {
        struct node *head;

        srand(time(NULL));
        int amount;
        head = create(head);
        traverse(head);
        printf("Please enter a number so decide the length of link: \n");
        scanf("%d", &amount);

        while(amount > 0)
        {
            generate(head, amount);
            amount--;
        }    

        traverse(head);

        return 0;
    }
