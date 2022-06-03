#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *link ;
};

typedef struct node ListNode;

void printList(ListNode *head);
int moveMaxToFront(ListNode **ptrHead);

int main()
{
    ListNode *head = NULL;
    ListNode *ptr;
    int i;


    while(scanf("%d \n", &i))
    {
        if(head == NULL){
            head = malloc(sizeof(ListNode));
            ptr = head;
        }
        else{
            ptr->link = malloc(sizeof(ListNode));
            ptr = ptr->link;
        }
        ptr->item = i;
    }
    ptr->link = NULL;

    i= moveMaxToFront(&head);
    printf("index: %d\n",i);
    printList(head);


    return 0;
}

void printList(ListNode *head)
{
    while(head != NULL){
        printf("%d\n", head ->item);
        head = head -> link;
    }
    return;
}

int moveMaxToFront(ListNode **ptrHead)
{
    ListNode *ptr = *ptrHead, *dynamic = *ptrHead, *maxPtr,*next, *cur;
    int max = ptr->item;
    int n =0, index=0;

    while(dynamic->link != NULL){
        if(dynamic->link->item > max){
            cur = dynamic;
            max = dynamic->link->item;
            maxPtr = dynamic->link;
            next = dynamic->link->link;
            index = n;
        }
        dynamic = dynamic->link;
        n++;

    }
    if(max == ptr->item){
        return -1;
    }
    else{
        cur->link = next;
        maxPtr->link = ptr;
        *ptrHead = maxPtr;
        return n;
    }

}
