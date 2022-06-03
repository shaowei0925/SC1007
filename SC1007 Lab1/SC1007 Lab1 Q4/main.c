#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *link ;
};

typedef struct node ListNode;

void printList(ListNode *head);
int duplicateReverse(ListNode *cur, ListNode **ptrNewHead);

int main()
{
    ListNode *head = NULL;
    ListNode *ptr;
    ListNode *duplicate = NULL;
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

    duplicateReverse( head , &duplicate);

    printList(head);
    printf("Duplicate List:\n");
    printList(duplicate);


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

int duplicateReverse(ListNode *cur, ListNode **ptrNewHead)
{
    ListNode *dynamic = *ptrNewHead, *temp, *temp2;

    temp = cur;
    while(temp != NULL){
        if(dynamic == NULL){
            dynamic = malloc(sizeof(ListNode));
            dynamic->item = cur->item;
            dynamic->link = NULL;
        }
        else{
            temp2 = malloc(sizeof(ListNode));
            temp2->item = temp->item;
            temp2->link = dynamic;
            dynamic = temp2;
        }
        temp = temp->link;
    }
    *ptrNewHead = dynamic;
    return;
}
