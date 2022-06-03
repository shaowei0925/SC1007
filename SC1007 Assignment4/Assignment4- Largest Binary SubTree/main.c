#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queueNode{
	BTNode *data;
	struct _queueNode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * data);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

BTNode* createNode(int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

BTNode* findLargestBST (BTNode* root);

int main()
{
    BTNode* root = NULL;
    BTNode* temp = NULL;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int item;
    int flag=1;
    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
    {
        if(root==NULL)
        {
            if(item!=-1){
                root =createNode(item);
                enqueue(&q,root);
            }
        }
        else{
            while(!isEmptyQueue(q)){
                temp = getFront(q);
                if(flag){
                    if(item != -1){
                        temp->left = createNode(item);
                        enqueue(&q,temp->left);
                    }
                    flag = 0;
                    break;
                }
                else if(temp->right==NULL){
                    if(item!=-1){
                        temp->right = createNode(item);
                        enqueue(&q,temp->right);
                    }
                    dequeue(&q);
                    flag=1;
                    break;
                }
                else  dequeue(&q);
            }
        }
    }
    scanf("%*s");
    printf("The input binary tree:\n");
    printBTNode(root,0,0);
    printf("\n");
    BTNode* BSTnode = findLargestBST (root);
    printf("The largest binary search subtree:\n");
    if(BSTnode)
        printBTNode(BSTnode,0,0);
    else
        printf("No BST\n");
    deleteTree(&root);

    return 0;
}

BTNode* createNode(int item)
{
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	node->item = item;
	node->left = node->right = NULL;
	return node;
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
void enqueue(Queue *qPtr, BTNode *data){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr){
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

BTNode* getFront(Queue q){
    return q.head->data;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
}



typedef struct store{
    BTNode *node;
    int isbst;
	int min;
	int max;
	int size;
}Store;

Store ptr;

Store find(BTNode *root)
{
    static int max = NULL;
    Store s ;
    Store left, right;
    s.node = root;
    //when root is NULL, return [True,min =0-infinity , max=+infinity, size =0]
    if(root == NULL){
        s.isbst = 1;
        s.min = 1000000;
        s.max = -1;
        s.size = 0;
        return s;
    }
    left = find(root->left);
    right = find(root->right);



    /*when root is != NULL, check if root->item > left->max && root->item < right->min, left is BST and Right is BST ,
    return [True, left->min , right->max, left.size+right.size+1] */
    if(root != NULL){
        //printf("%d-%d-%d-%d  ",root->item, left.isbst, left.max, right.min);
        if((left.isbst == 1) && (right.isbst == 1)&& (root->item > left.max) && (root->item < right.min) ){
            if(left.max == -1){
                s.min = root->item;
            }
            else{
                s.min = left.min;
            }
            if(right.min == 1000000){
                s.max = root->item;
            }
            else{
                s.max = right.max;
            }
            s.isbst = 1;
            s.size= left.size + right.size +1;


            if(s.size > max){
                max = s.size;
                ptr = s;
                //printf("%d ",ptr.node->item);
            }
            return s;
        }

        else{
            s.isbst = 0;
            s.max = s.min = 0;
            s.size = 0;
            return s;
        }

    }

    if(left.isbst == 1 && left.size > right.size){
        return left;
    }
    else if(right.isbst ==1 && right.size > left.size){
        return right;
    }
    else{
        Store end;
        end = ptr;
        printf("%d ", end.node->item);
        return end;
    }



}

BTNode* findLargestBST (BTNode* root)
{
    if(root == NULL){
        return NULL;
    }
    Store p;
    p = find(root);

    return ptr.node;

}
