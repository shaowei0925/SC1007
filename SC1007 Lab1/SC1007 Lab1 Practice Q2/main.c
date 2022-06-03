#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *link ;
};
typedef struct node ListNode;

typedef struct _linkedlist{
    ListNode *head;
    int size;
} LinkedList;

void printList(ListNode *head);
void moveEvenItemsToBack(LinkedList *ll);

int main()
{
    LinkedList *ll;

    ll->head = NULL;
    ll->size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll->head == NULL){
			ll->head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll->head;
		}
		else{
			temp->link = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->link;
		}
		temp->item = i;
		ll->size++;
	}
	temp->link = NULL;

    moveEvenItemsToBack( ll );

    printList(ll->head);


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

void moveEvenItemsToBack(LinkedList *ll)
{
    ListNode *ptrhead = NULL, *dynamic, *evenHead = NULL, *evennext;
    dynamic = ll->head;
    while(dynamic != NULL){
        if(dynamic->item %2 == 1 || ((dynamic->item)*-1 %2 == 1)){
            if(ptrhead == NULL){
                ptrhead = malloc(sizeof(ListNode));
                ptrhead->item = dynamic->item;
                ll->head = ptrhead;
            }
            else{
                ptrhead->link = malloc(sizeof(ListNode));
                ptrhead = ptrhead->link;
                ptrhead->item = dynamic->item;
            }
        }
        else{
            if(evenHead == NULL){
                evenHead = malloc(sizeof(ListNode));
                evenHead->item = dynamic->item;
                evennext = evenHead;
                }

            else{
                evennext->link = malloc(sizeof(ListNode));
                evennext = evennext->link;
                evennext->item = dynamic->item;
            }
        }
        dynamic = dynamic->link;
    }
    if(ptrhead == NULL){
        evennext->link = NULL;
    }
    else{
        evennext->link = NULL;
        ptrhead->link = evenHead;
    }
    return;

}
