#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

BTNode *newNode(char *pre,char *post, int poststart , int postend, int *ptr)
{
    int postIndex = 0;
    if(poststart>postend){
        return NULL;
    }

    BTNode *node = malloc(sizeof(BTNode));
    node->id = pre[*ptr];
    (*ptr)++;

    if(poststart == postend){
        node->left = node->right = NULL;
        return node;
    }
    while(post[postIndex]!= pre[*ptr]){
        postIndex ++;
    }

    node->left = newNode(pre, post , poststart , postIndex, ptr);
    node->right = newNode(pre,post, postIndex+1 , postend-1, ptr);
    return node;
}
void buildTree(BTNode** node, char* preO, char* postO)
{
    int index = 0;
    int poststart =0;
    int postend = strlen(postO)-1;
    (*node) = newNode(preO,postO,poststart, postend, &index);
}
