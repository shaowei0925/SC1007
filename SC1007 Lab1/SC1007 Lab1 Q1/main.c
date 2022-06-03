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

    removeNode(&head, 2);

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

int removeNode(ListNode **ptrHead , int index)
{
    ListNode *pre_node , *cur_node;
    pre_node = *ptrHead;
    cur_node = *ptrHead;
    int num = 0;
    while(pre_node != NULL){
        num ++;
        pre_node = pre_node -> link;
    }

    pre_node = *ptrHead;

    if(index > num){
        return 0;
    }

    if(index == 0){
        *ptrHead = cur_node->link;
        free(cur_node);
        cur_node = NULL;
        return 1;

    }
    else{
        while( index != 0){
            pre_node = cur_node;
            cur_node = cur_node->link;
            index--;
        }
        pre_node->link = cur_node->link;
        free(cur_node);
        cur_node = NULL;
        return 1;
    }


}
