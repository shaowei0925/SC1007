#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // The size of the array

enum ExpType { OPT, OPERAND };

typedef struct _stackNode {
  char item;
  struct _stackNode *next;
} StackNode;

typedef struct _stack {
  int size;
  StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode {
  int item;
  enum ExpType type;
  struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
  int size;
  ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList(LinkedList ll);

void in2PreLL(char *infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main() {
  char infix[SIZE];

  // printf("Enter an infix expression:\n");
  scanf("%[^\n]%*c", infix);

  LinkedList inExpLL;
  inExpLL.head = NULL;
  inExpLL.size = 0;

  in2PreLL(infix, &inExpLL);

  printExpLL(inExpLL);

  removeAllNodes(&inExpLL);
  return 0;
}

void printExpLL(LinkedList inExpLL) {
  ListNode *temp = NULL;
  temp = inExpLL.head;
  while (temp != NULL) {
    if (temp->type == OPERAND)
      printf(" %d ", temp->item);
    else
      printf(" %c ", (char)(temp->item));
    temp = temp->next;
  }
  printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
  ListNode *newNode;
  newNode = malloc(sizeof(ListNode));
  if (newNode == NULL)
    exit(0);

  newNode->item = item;
  newNode->type = type;
  newNode->next = LLPtr->head;
  LLPtr->head = newNode;
  LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
  if (LLPtr == NULL || LLPtr->size == 0) {
    return 0;
  } else {
    ListNode *temp = LLPtr->head;
    LLPtr->head = LLPtr->head->next;

    free(temp);
    LLPtr->size--;
    return 1;
  }
}

int isEmptyLinkedList(LinkedList ll) {
  if (ll.size == 0)
    return 1;
  else
    return 0;
}

void removeAllNodes(LinkedList *LLPtr) {
  while (deleteNode(LLPtr))
    ;
}

void push(Stack *sPtr, char item) {
  StackNode *newNode;
  newNode = malloc(sizeof(StackNode));
  newNode->item = item;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr) {
  if (sPtr == NULL || sPtr->head == NULL) {
    return 0;
  } else {
    StackNode *temp = sPtr->head;
    sPtr->head = sPtr->head->next;
    free(temp);
    sPtr->size--;
    return 1;
  }
}

char peek(Stack s) { return s.head->item; }

int isEmptyStack(Stack s) {
  if (s.size == 0)
    return 1;
  else
    return 0;
}

#include <string.h>


void reverse(char *str)
{
    int i = 0, j=0;
    int n =strlen(str);
    char temp[n];
    for( i = n-1 ; i>=0 ; i--){
        temp[j] = str[i];
        j++;
    }
    temp[j] = '\0';
    strcpy(str,temp);
    return str;
}


int precedence(char opt)
{
    if(opt == '+'||opt == '-'){
        return 1;
    }
    if(opt== '*' || opt == '/'){
        return 2;
    }
}
void in2PreLL(char *infix, LinkedList *inExpLL)
{
    Stack stck;
    stck.head = NULL;
    stck.size = 0;
    if (strlen(infix)==0) return;

    int len = strlen(infix);
    int i = 0, j;
    int number;
    char store2 ;

    reverse(infix);

    char store[len];


    while(infix[i]!= NULL){
        if(infix[i] >= '0' && infix[i]<= '9'){
            j= 0;
            while(infix[i]>= '0' && infix[i]<='9'){
                store[j] = infix[i];
                j++; i++;
            }
            store[j] = '\0';
            reverse(store);
            number = atoi(store);
            insertNode(inExpLL, number, OPERAND);

        }
        else if( infix[i] == ')'){
            push(&stck, infix[i]);
            i++;
        }
        else if(infix[i] == '('){
            while(peek(stck)!= ')'){
                store2 = stck.head->item;
                insertNode(inExpLL, store2, OPT);
                pop(&stck);
            }
            pop(&stck);
            i++;
        }
        else{
            while((isEmptyStack(stck)!=1) && (peek(stck)!=')') && (precedence(peek(stck))>precedence(infix[i]))){
                store2 = stck.head->item;
                insertNode(inExpLL, store2, OPT);
                pop(&stck);
            }
            push(&stck, infix[i]);
            i++;
        }
    }
    while(isEmptyStack(stck)!=1) {
        store2 = stck.head->item;
        insertNode(inExpLL, store2, OPT);
        pop(&stck);
    }
}

