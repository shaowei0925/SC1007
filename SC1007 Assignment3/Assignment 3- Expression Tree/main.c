#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}
BTNode* newNode(char* prefix, int* n) {
    int k, temp;
    char integer[SIZE];

    while(prefix[*n] == ' ' ){
        (*n)++;
    }
    if (prefix[*n] == '\0'){
        return NULL;
    }

    if (prefix[*n]>= '0' && prefix[*n] <= '9') {
        k=0;
        while (prefix[*n]>= '0' && prefix[*n] <= '9') {
            integer[k++] = prefix[*n];
            (*n)++;
        }
        integer[k] = '\0';
        temp = atoi(integer);
        BTNode* leaf = (BTNode*) malloc(sizeof(BTNode));
        leaf->item = temp;
        leaf->left = NULL;
        leaf->right = NULL;
        (*n)++;
        return leaf;
    }

    else {
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
        node->item = prefix[*n];
        (*n)++;
        node->left = newNode(prefix, n);
        node->right = newNode(prefix, n);
        return node;
    }
}
void createExpTree(BTNode** root,char* prefix)
{
 //Write your code here
    int i = 0;
    char* c = prefix;
    (*root) = newNode(c,&i);
}

void printTree(BTNode *node){
    //Write your code here
    if (node==NULL) {
        return;
    }
    else {
        printTree(node->left);
        if ((node->left != NULL) && (node->right != NULL)) {
            printf("%c ", node->item);
        }
        else {
            printf("%d ", node->item);
        }
        printTree(node->right);
    }
}


void printTreePostfix(BTNode *node){
   //Write your code here
    if (node==NULL) {
        return;
    }
    else {
        printTreePostfix(node->left);
        printTreePostfix(node->right);
        if ((node->left != NULL) && (node->right != NULL)) {
            printf("%c ", node->item);
        }
        else {
            printf("%d ", node->item);
        }
    }
}

double computeTree(BTNode *node){
    double result;
    double i, j;

    if (node != NULL) {
        if ((node->left == NULL) && (node->right == NULL)) {
            return node->item;
        }

        else if (node->item == '+') {
            i = computeTree(node->left);
            j = computeTree(node->right);
            result = i + j;
            return result;
        }

        else if (node->item == '-') {
            i = computeTree(node->left);
            j = computeTree(node->right);
            result = i - j;
            return result;
        }

        else if (node->item == '*') {
            i = computeTree(node->left);
            j = computeTree(node->right);
            result = i * j;
            return result;
        }

        else{
            i = computeTree(node->left);
            j = computeTree(node->right);
            result = i / j;
            return result;
        }
    }
}
