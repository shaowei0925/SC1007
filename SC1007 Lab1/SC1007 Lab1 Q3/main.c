#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *link ;
};

typedef struct node ListNode;

void printList(ListNode *head);
int removeNode(ListNode **ptrHead , int index);

int main()
{
    ListNode *head = NULL;
    ListNode *ptr;
    ListNode *even = NULL, *odd = NULL;
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

    split(head, &even , &odd);

    printList(head);
    printf("Even link:\n");
    printList(even);
    printf("\nOddlink:\n");
    printList(odd);


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

int split(ListNode *cur, ListNode **ptrEvenList,ListNode **ptrOddList)
{
    ListNode *dynamic = cur;
    ListNode *evenlink = *ptrEvenList, *oddlink = *ptrOddList;
    int n=0;
    while(cur != NULL){
        if(n%2 == 0){
            if( evenlink == NULL){
                evenlink = malloc(sizeof(ListNode));
                evenlink->item = cur->item;
                *ptrEvenList = evenlink;
            }
            else{
                evenlink->link = malloc(sizeof(ListNode));
                evenlink = evenlink -> link;
                evenlink->item = cur->item;
            }
        }
        else{
            if( oddlink == NULL){
                oddlink = malloc(sizeof(ListNode));
                oddlink->item = cur->item;
                *ptrOddList = oddlink;
            }
            else{
                oddlink->link = malloc(sizeof(ListNode));
                oddlink = oddlink -> link;
                oddlink->item = cur->item;
            }

        }
        n++;
        cur = cur->link;
    }
    evenlink->link = NULL;
    oddlink->link = NULL;
    return;

}
