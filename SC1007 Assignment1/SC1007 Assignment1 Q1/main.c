#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;


	reverseKNodes(&head, K);
	printList(head);
    deleteList(&head);
	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
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

void reverseKNodes(ListNode** head, int K)
//Write your code here
{
    ListNode *temp1= *head, *temp2, *hd = *head;
    ListNode *kthnode;
    int count;
    int num=0;

    if(temp1 == NULL || K == 0){
        return;
    }

    while(temp1 != NULL){
        num ++;
        temp1 = temp1 ->next;
    }
    if(num<K){
        return;
    }

    temp1 =hd;
    for(int i=0 ; i<K; i++){
        temp1 = temp1->next;
    }
    count =0;
    while(temp2 != NULL && count <K){
        temp2 = hd ->next;
        hd-> next = temp1 ;
        temp1 = hd;
        hd = temp2;
        count++;
    }
    *head = temp1;
    num -= K;
    num = num/K;

    while(num>0){
        kthnode = temp1;
        for(int i=0; i<K-1; i++){
            kthnode = kthnode->next;
        }
        temp1 = hd;
        for(int i=0 ; i<K; i++){
            temp1 = temp1->next;
        }
        count = 0;
        while(temp2 != NULL && count <K){
            temp2 = hd ->next;
            hd-> next = temp1 ;
            temp1 = hd;
            hd = temp2;
            count++;
            if(count==K){
                kthnode ->next = temp1;
            }
            }
        num--;

    }
}
