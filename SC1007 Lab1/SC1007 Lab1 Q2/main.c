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
int removeNode2(LinkedList *ll, int index);

int main()
{
    LinkedList *ll;

    ll->head = NULL;
    ll->size = 0;
    ListNode* temp;

	int i = 0;
	int n=0;
	scanf("%d",&n);

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

    removeNode2( ll , n);

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

int removeNode2(LinkedList *ll, int index)
{
    ListNode *first = ll->head;
    ListNode *dynamic;

    if(index == 0){
        dynamic = first->link;
        ll->head = dynamic;
        return;
    }
    else if( index>0 && index < ll->size){
        dynamic = first;
        for(int i=0; i<index-1; i++){
            first = first->link;
        }
        dynamic = first->link->link;
        first->link = dynamic;
        return;
    }
    else{
        return;
    }

}
