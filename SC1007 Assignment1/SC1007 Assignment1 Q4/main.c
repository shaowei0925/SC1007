#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;


	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
    // Write your code here
    ListNode *temp1 , *temp2,*startpt= head,*endpt=head ;
    ListNode *hd= head, *tail; ListNode *start2;

    if(hd == NULL|| start<0 || end<0 || start>end || start == end){
        return hd;
    }
    if(isdigit(start) == 0 || isdigit(end) ==0){
        return hd;
    }

    int n =0;
    temp1 = head;
    while(temp1 != NULL){
        temp1 = temp1 ->next;
        n++;
    }
    if(n-1<end || n-1<start){
        return hd;
    }

    if(start == 0){
        startpt = hd;
    }
    else{
    for(int i=0; i<start-1;i++){
        startpt = startpt->next;
    }
    start2 = startpt;
    startpt = startpt->next;

    }
    for(int i=0; i<end;i++){
        endpt = endpt->next;
    }
    tail = endpt->next;
    temp1 = tail;
    while(temp2!= tail ){
        temp2 = startpt->next;
        startpt->next = temp1;
        temp1 = startpt;
        startpt = temp2;
    }
    if(start ==0){
        hd = temp1;
    }
    else if(start ==1){
        hd->next = temp1;
    }
    else{
        start2->next = temp1;
    }
    return hd;

}
