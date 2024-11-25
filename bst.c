#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL, *newNode = NULL, *parent;

void createNode()
{
    int item;
    printf("\nEnter the data\n");
    scanf("%d", &item);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
}


void searchAndInsert(struct node *ptr)
{
    // value more than root node value insert at right 
    if ((newNode->data > ptr->data) && (ptr->right != NULL))
        searchAndInsert(ptr->right);
    else if ((newNode->data > ptr->data) && (ptr->right == NULL))
        ptr->right = newNode;
    // value less than root node value insert at left 
    else if ((newNode->data < ptr->data) && (ptr->left != NULL))
        searchAndInsert(ptr->left);
    else if ((newNode->data < ptr->data) && (ptr->left == NULL))
        ptr->left = newNode;
}

void insert()
{
    createNode();
    if (root == NULL)
        root = newNode;
    else
        searchAndInsert(root);
}


/* To find the smallest element in the right sub tree */
int smallestLeftNode(struct node *ptr)
{
    struct node *temp;
    while (ptr->left != NULL)
    {
        temp = ptr;
        ptr = ptr->left;
    }
    temp->left = NULL;

    return ptr->data;
}

void search(struct node * ptr, int val){
	if(ptr == NULL){
		printf("Not found\n");
		return;
	}
	if(ptr -> data == val){
		printf("Element Found\n");
	}
	else{
		if(ptr -> data < val){
			search(ptr -> right, val);
		}
		search(ptr -> left, val);
	}

}

void deleteNode(struct node *toDelete)
{
    int smallest;

    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    if (parent == NULL || parent == toDelete)
        printf("\nParent node not found\n");
    else
    {
        if (parent->left == toDelete)
        {
            if (toDelete->left == NULL && toDelete->right == NULL)
            {
                parent->left = NULL;
                free(toDelete);
            }
            else if (toDelete->left == NULL)
            {
                parent->left = toDelete->right;
                free(toDelete);
            }
            else if (toDelete->right == NULL)
            {
                parent->left = toDelete->left;
                free(toDelete);
            }
            else
            {
                if (toDelete->right->left != NULL)
                {
                    smallest = smallestLeftNode(toDelete->right);
                    toDelete->data = smallest;
                }
                else
                {
                    toDelete->data = toDelete->right->data;
                    toDelete->right = toDelete->right->right;
                }
            }
        }

        if (parent->right == toDelete)
        {
            if (toDelete->left == NULL && toDelete->right == NULL)
            {
                parent->right = NULL;
                free(toDelete);
            }
            else if (toDelete->left == NULL)
            {
                parent->right = toDelete->right;
                free(toDelete);
            }
            else if (toDelete->right == NULL)
            {
                parent->right = toDelete->left;
                free(toDelete);
            }
            else
            {
                if (toDelete->right->left != NULL)
                {
                    smallest = smallestLeftNode(toDelete->right);
                    toDelete->data = smallest;
                }
                else
                {
                    toDelete->data = toDelete->right->data;
                    toDelete->right = toDelete->right->right;
                }
            }
        }
    }
}

void searchAndDelete(struct node *ptr, int item)
{
	int val = item;
	if(ptr == NULL){
		printf(" \n");
		return;
	}
	if(ptr -> data == val){
		printf(" \n");
	}
	else{
		if(ptr -> data < val){
			search(ptr -> right, val);
		}
		search(ptr -> left, val);
	}



	int f;
    if (item > ptr->data)
    {
        f = 1;

	parent = ptr;
        searchAndDelete(ptr->right, item);
    }
    else if (item < ptr->data)
    {
         f=1;

	 parent = ptr;


        searchAndDelete(ptr->left, item);
    }
    else if (item == ptr->data)
{
	f=1;

        deleteNode(ptr);
}

   else if (f!=1)
{

        printf("\n Item not found \n");
}

   else
      parent = ptr;


}
void delete ()
{
    int items;


    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }

    printf("\nEnter the item to be deleted\n");
    scanf("%d", &items);
    parent = root;

    searchAndDelete(root, items);

}



void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d \n", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d \n", ptr->data);
    }
}
void display(struct node *ptr)
{
    if (ptr == NULL)
        printf("\nTree is empty");
    else
    {
        printf("\nInorder :\n");
        inorder(ptr);
        printf("\n\nPreorder :\n");
        preorder(ptr);
        printf("\n\nPostorder :\n");
        postorder(ptr);
    }
    printf("\n");
}

void main()
{
    int choice,n;

    while (1)
    {

        printf("\n1. Insert a node \n2. Display \n3. Delete a node \n4. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
	        insert();
                break;

            case 2:
                display(root);
                break;

            case 3:
                delete ();
                break;
	    case 5:
		int vall;
         	printf("Enter the value to search");
                scanf("%d", &vall);
		search(root, vall);

            case 4:
                exit(0);

            default:
                printf("\nIvalid choice.\n");
        }
    }
}
