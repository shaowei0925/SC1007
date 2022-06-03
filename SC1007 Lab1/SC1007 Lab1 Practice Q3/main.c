#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *link ;
};

typedef struct node ListNode;

void printList(ListNode *head);
int concatenate(ListNode **ptrHead1, ListNode *head2);

int main()
{
    ListNode *head = NULL;
    ListNode *head2 = NULL;
    ListNode *ptr;
    int i;


    while(1)
    {
        if(scanf("%d",&i)){
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
        else{
            break;
        }
    }
    ptr->link = NULL;
    printf("next:\n ");
    while(scanf("%d \n", &i))
    {
        if(head2 == NULL){
            head2 = malloc(sizeof(ListNode));
            ptr = head2;
        }
        else{
            ptr->link = malloc(sizeof(ListNode));
            ptr = ptr->link;
        }
        ptr->item = i;
    }
    ptr->link = NULL;

    concatenate(&head, head2);

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

int concatenate(ListNode **ptrHead1, ListNode *head2)
{
    ListNode *dynamic = *ptrHead1;
    while(dynamic->link != NULL){
        dynamic = dynamic->link;
    }
    dynamic->link = head2;
    return;
}
