#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* insertBSTNode(BTNode* cur, int item);
void printBTNode(BTNode *root, int space,int left);
void deleteTree(BTNode **root);
int removeBSTNode(BTNode **nodePtr, int item);

int main()
{
    BTNode* root=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        root = insertBSTNode(root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root,0,0);

    printf("Enter an integer to be removed from the tree:\n");
    scanf("%d",&item);

    if(removeBSTNode(&root,item))
       printf("%d was removed\n",item);

    else
       printf("%d is not in the tree.\n",item);

    printf("The Binary Search Tree:\n");
    printBTNode(root,0,0);

    deleteTree(&root);
    root=NULL;
    return 0;
}

BTNode* insertBSTNode(BTNode* cur, int item){
    if (cur == NULL){
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
    	node->item = item;
    	node->left = node->right = NULL;
    	return node;
	}
    if (item < cur->item)
        cur->left  = insertBSTNode (cur->left, item);
    else if (item > cur->item)
        cur->right = insertBSTNode (cur->right, item);
    else
        printf("Duplicated Item: %d\n",item);

    return cur;
}

void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->item);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

void deleteTree(BTNode **root){
    if (*root != NULL)
	{
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}
int removeBSTNode(BTNode **nodePtr, int item){
    BTNode *temp, *mum1;
    temp = (*nodePtr);

    while(item != temp->item){
        if(item < temp->item){
            mum1 = temp;
            temp = temp->left;
        }
        else if(item > temp->item){
            mum1 = temp;
            temp = temp->right;
        }
        else{
            return;
        }
    }

    if(temp->left == NULL && temp->right == NULL){
        if(item > mum1->item){
            mum1->right = NULL;
        }
        else{
            mum1->left = NULL;
        }
    }
    else if(temp->left == NULL){
        if(item < mum1->item){
            mum1->left = temp->right;
        }
        else{
            mum1->right = temp->right;
        }
    }
    else if(temp->right == NULL){
        if(item < mum1->item){
            mum1->left = temp->left;
        }
        else{
            mum1->right = temp->left;
        }
    }
    else{
        int n;
        if(item > mum1->item){
            temp = temp->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            n = temp->item;
            removeBSTNode(nodePtr, temp->item);
            mum1->right->item = n;
        }
        else{
            temp = temp->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            n = temp->item;
            removeBSTNode(nodePtr, temp->item);
            mum1->left->item = n;
       }
    }
}

