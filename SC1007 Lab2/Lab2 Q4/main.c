#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);
int prcd(char item);

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

int prcd(char item)
{
    if(item == '*' || item == '/'){
        return 1;
    }
    else{
        return 0;
    }
}
void in2Post(char* infix, char* postfix)
{
    Stack s;
    s.head = NULL;
    s.size = NULL;
    char c;
    int i =0 ; int n =0;
    while( infix[i] != '\0'){
        c = infix[i];
        if(c != '+' && c!= '-' && c != '*' && c!= '/'  && c != '(' && c !=')'){
            postfix[n++] = c;
        }
        else if( c == '('){
            push(&s, c);

        }
        else if( c == ')'){
            while(peek(s) != '('){
                postfix[n++] = peek(s);
                pop(&s);
            }
            pop(&s);
        }
        else{
            while(isEmptyStack(s)==0 && peek(s) != '(' && prcd(peek(s)) >= prcd(c) )
            {
                postfix[n++] = peek(s);
                pop(&s);
            }
            push(&s,c);
        }
        i++;
    }
    while(isEmptyStack(s) != 1){
        postfix[n++] = peek(s);
        pop(&s);
    }
    postfix[n] = '\0';
}
