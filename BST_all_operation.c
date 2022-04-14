#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
};
struct node *root = NULL;

int insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *current = NULL;
    struct node *parent = NULL;
    temp->left_child = NULL;
    temp->data = data;
    temp->right_child = NULL;

    if (root == NULL)
    {
        root = temp;
        printf("inserted    :   %d\n", data);
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (parent->data > data)
            {
                current = current->left_child;
                if (current == NULL)
                {
                    parent->left_child = temp;
                    printf("inserted    :   %d\n", data);
                    return 0;
                }
            }
            else
            {
                current = current->right_child;
                if (current == NULL)
                {
                    parent->right_child = temp;
                    printf("inserted    :   %d\n", data);
                    return 0;
                }
            }
        }
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left_child);
        printf("%d\t", root->data);
        inorder_traversal(root->right_child);
    }
}

void preorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        inorder_traversal(root->left_child);
        inorder_traversal(root->right_child);
    }
}
void postorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left_child);
        inorder_traversal(root->right_child);
        printf("%d\t", root->data);
    }
}
struct node * search(int key)
{
    struct node *current = root;
    while (current->data != key)
    {
        if (current->data > key)
        {
            current = current->left_child;
        }
        else
        {
            current = current->right_child;
        }
        if (current == NULL)
        {
            printf("\n%d is not prsent in the list\n", key);
            return current;
        }
    }
    return current;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left_child != NULL)
        current = current->left_child;
    return current;
}
struct node *maxValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->right_child != NULL)
        current = current->right_child;
    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left_child = deleteNode(root->left_child, key);
    else if (key > root->data)
        root->right_child = deleteNode(root->right_child, key);
    else
    {
        if (root->left_child == NULL)
        {
            struct node *temp = root->right_child;
            printf("Deletion done\n");
            free(root);
            return temp;
        }
        else if (root->right_child == NULL)
        {
            struct node *temp = root->left_child;
            printf("Deletion done\n");
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right_child);
        root->data = temp->data;
        root->right_child = deleteNode(root->right_child, temp->data);
    }
    return root;
}

int maxDepth(struct node* node)
{
    if (node == NULL)
        return -1;
    else {
        
        int lDepth = maxDepth(node->left_child);
        int rDepth = maxDepth(node->right_child);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int tree_height(struct node* root) {
    
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left_child);
        int right_height = tree_height(root->right_child);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int main()
{
    int n, temp, key, t = 1, ch;
    struct node *dummy;
    while (t == 1)
    {
        printf("\n1)  Insertion \n2)  Deletion\n3)  Finding an element (Search)\n4)  Finding Min element\n5)  Finding Max element\n");
        printf("6)  Left child of the given node\n7)  Right child of the given node\n8)  Finding the number of nodes,leaves nodes, ancestors, descendants\n");
        printf("9)  Inorder Traversal\n10) Preorder Traversal\n11) Postorder Traversal\n12) EXIT\n");
        //i. Delete node with only child ii. Delete node with both children
        printf("\n\nEnter your choice...... : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            //Inserting node to the BST
            printf("How many number you want to enter :     \n");
            scanf("%d", &n);
            printf("Enter the number \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &temp);
                insert(temp);
            }
            break;
        case 2:
            // Deletion in BST
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nEnter the element you want to delete : ");
                scanf("%d", &key);
                deleteNode(root, key);
            }
            break;
        case 3:
            //Searching
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nEnter the element you want to search \n");
                scanf("%d", &key);
                dummy = search(key);
                if(dummy == NULL){
                    printf("\n%d is not prsent in the list\n", key);
                }
                else{
                    printf("\n%d is prsent in the list\n", key);
                }
            }
            break;
        case 4:
            dummy = minValueNode(root);
            printf("Min element :   %d\n", dummy->data);
            break;
        case 5:
            dummy = maxValueNode(root);
            printf("Max element :    %d\n", dummy->data);
            break;
        case 6:
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nEnter the element you want to find it's left child \n");
                scanf("%d", &key);
                dummy = search(key);
                if(dummy == NULL){
                    printf("\n%d is not prsent in the list\n", key);
                }
                else if (dummy->left_child == NULL)
                {
                    printf("%d element have no left child\n",key);   
                }
                else{
                    printf("\n%d is the Left child of the %d node\n", dummy->left_child->data,key);
                }
            }
            break;
        case 7:
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nEnter the element you want to find it's left child \n");
                scanf("%d", &key);
                dummy = search(key);
                if(dummy == NULL){
                    printf("\n%d is not prsent in the list\n", key);
                }
                else if (dummy->right_child == NULL)
                {
                    printf("%d element have no right child\n",key);   
                }
                else{
                    printf("\n%d is the Left child of the %d node\n", dummy->right_child->data,key);
                }
            }
            break;
        case 8:
            printf("Finding the number of nodes,leaves nodes, ancestors, descendants\n");
            break;
        case 9:
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("Inorder Traversal : ");
                inorder_traversal(root);
            }
            break;
        case 10:
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nPreorder Traversal : ");
                preorder_traversal(root);
            }
            break;
        case 11:
            if (root == NULL)
            {
                printf("List is empty!!!\n");
            }
            else
            {
                printf("\nPostorder Traversal : ");
                postorder_traversal(root);
            }
            break;
        case 12:
            t = 2;
            break;
        default:
            printf("Invalid Choice!!!!!\n");
            break;
        }
    }

    printf("Depth of tree is : %d",maxDepth(root));
    printf("Height of tree is : %d",tree_height(root));
    return 0;
}