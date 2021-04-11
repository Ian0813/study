#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "H_Tree.h"




int main()
{
    srand(time(NULL));
    Node *root = NULL;

    root = Create(root, 30);
    for(int i = 0; i < 10; i++)
    {
        Insert(root, (rand()%100) * i);
    }    
    Traversal_Inorder(root);

    return 0;

}