#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);

LinkedList rearrange (LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);

	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

LinkedList rearrange (LinkedList ll)
{
    ListNode *hd = ll.head;
    int n = ll.size;
    if( (hd == NULL) || (n == 0) || (n == 1) ){
        return ll;
    }
    ListNode *head1 , *head2 , *link;
    head1 = hd;
    head2 = hd;
    int size = (n/2)-1;
    if(ll.size %2 ==0){
        for(int i=0; i< size; i++){
            head2 = head2 ->next;
        }
        link = head2;
        head2 = head2 ->next;
        link->next = NULL;

        hd = head2;
        while(link != NULL){
            link = head2->next;
            head2->next = head1;
            head2 = head1;
            head1 = head1->next;
            head2->next = link;
            head2 = link;
        }

        //*********************second round***********************
        head1 = hd;
        head2 = hd;

        for(int i=0; i<size ; i++){
            head2 = head2 ->next;
        }
        link = head2;
        head2 = head2 ->next;
        link->next = NULL;
        link = head1;

        hd = head1;
        while(link != NULL){
            link = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = head1->next;
            head1->next = link;
            head1 = link;

        }
        ll.head = hd ;
    }
    else{
        ListNode *laz = hd;
        for(int i=0; i<n -2; i++){
            laz = laz->next;
        }
        link = laz;
        laz = laz->next;
        link->next = NULL;
        for(int i=0; i< size; i++){
            head2 = head2 ->next;
        }
        link = head2;
        head2 = head2 ->next;
        link->next = NULL;

        hd = head2;
        while(link != NULL){
            link = head2->next;
            head2->next = head1;
            head2 = head1;
            head1 = head1->next;
            head2->next = link;
            head2 = link;
        }
        //*********************second round***********************
        head1 = hd;
        head2 = hd;

        for(int i=0; i<size ; i++){
            head2 = head2 ->next;
        }
        link = head2;
        head2 = head2 ->next;
        link->next = NULL;
        link = head1;

        hd = head1;
        while(link != NULL){
            link = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = head1->next;
            head1->next = link;
            head1 = link;
        }
        link = hd;

        while(link->next != NULL){
            link = link->next;
        }
        link->next = laz;

        ll.head = hd ;


    }
    return ll;

}
