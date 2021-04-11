
typedef struct node {

    int value;
    struct node *left;
    struct node *right;
}Node;

Node* New_node(Node *node, int value) {

    if(node == NULL)
    {
        node =(Node*) malloc(sizeof(struct node));
        node->value = value;        
        node->left = NULL;
        node->right = NULL;
    }else {
        printf("The root already exist.\n");
        exit(0);
    }

    return node;
}


void Insert(Node *node, int value)
{

    if(node == NULL) {
        New_node(node, value);    
    }
    else if(){

    }

    while(temp2 != NULL)
    {        
        if(temp1->value >= value)
        {
            if(temp1->left != NULL)   
            {
                temp3 = temp1->left;
                temp1 = temp3;
            }
            else {
                temp2 = (struct node*) malloc(sizeof(struct node));
                temp2->value = value;
                temp2->left = NULL;
                temp2->right = NULL;
                temp1->left = temp2;
                printf("New node : %d", temp2->value);
            }            
        }
        else if(temp1->value < value)        
        {
            if(temp1->right != NULL)   
            {
                temp3 = temp1->right;
                temp1 = temp3;
            }
            else {
                temp2 = (struct node*) malloc(sizeof(struct node));
                temp2->value = value;
                temp2->left = NULL;
                temp2->right = NULL;
                temp1->right = temp2;
                printf("New node : %d", temp2->value);
            }                           
        }            
    }    
}

void Traversal_Inorder(Node *root)
{
    Node *temp;
    temp = root;
    if(temp != NULL){
        printf("Val = %d\n", temp->value);
    } else{
        exit(0);
    }
    Traversal_Inorder(temp->left);
    Traversal_Inorder(temp->right);
}



// void release(Node *root){
//     while()
// }

