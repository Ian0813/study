


        #include<stdio.h>
        #include<stdlib.h>
        #include<time.h>
        #include "./S.h"



        struct node* crate()
        {
            struct node *temp;

            temp = (struct node*) malloc(sizeof(struct node));
            temp->data = rand()%100;
            temp->next = NULL;
            return temp;
        }

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


        void insert(struct node *n, int data)
        {
            struct node *temp1, *temp2;
            temp1 = n;
            temp2 = (struct node *) malloc(sizeof(struct node));
            temp2->data = data;
            temp2->next = NULL;

            while(temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp2;
        }

        struct node* delete(struct node *n, int data)
        {
            struct node *temp1, *temp2;
            temp1 = n;
            temp2 = temp1->next;
            if(temp1->data == data)
            {
                n = n->next;
                free(temp1);
                return n;
            }
            else
            {
                while(temp2->data != data)
                {
                        temp1 = temp2;
                        temp2 = temp1->next;
                }
                if(temp2 == NULL)
                    return n;
                temp1->next = temp2->next;
                free(temp2);
                return n;
            }
        }

        int main()
        {
            srand(time(NULL));
            int amount, action, data;
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
            while(1)
            {
                fflush(stdin);
                printf("Please enter a number for action : \n 1. traverse \n 2. insert \n 3. delete \n 4. Compute length \n");
                scanf("%d", &action);
                if(action < 1 || action > 4)
                    continue;
                if(action == 1)
                    traverse(head);
                else if(action == 2)
                {
                    printf("Please enter a number then for insert to the end of the link list. : \n");
                    scanf("%d", &data);
                    fflush(stdin);
                    insert(head, data);
                }
                else if(action == 3)
                {
                    printf("Please enter a number for delete a number in link list : \n");
                    scanf("%d", &data);
                    fflush(stdin);
                    head = delete(head, data);
                }
                else if(action == 4)
                {
                    length(head);
                    fflush(stdin);
                }
            }
            return 0;
        }
