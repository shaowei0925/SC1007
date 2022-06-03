#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode** head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

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


	triPartition(&head, pivot);
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

void triPartition(ListNode** head, int pivot)
{
    ListNode *smallHead = NULL , *bigHead = NULL , *sameHead = NULL , *link = *head, *dynamic1, *dynamic2, *dynamic3;
    if(link == NULL || pivot < 0){
        return;
    }
    while(link != NULL){
        if(link->item < pivot){
            if( smallHead == NULL){
                smallHead = malloc(sizeof(ListNode));
                smallHead->item = link->item;
                dynamic1 = smallHead;
            }
            else{
                dynamic1->next = malloc(sizeof(ListNode));
                dynamic1 = dynamic1->next;
                dynamic1->item = link->item;
            }
        }
        else if (link->item == pivot){
            if( sameHead == NULL){
                sameHead = malloc(sizeof(ListNode));
                sameHead->item = link->item;
                dynamic2 = sameHead;
            }
            else{
                dynamic2->next = malloc(sizeof(ListNode));
                dynamic2 = dynamic2->next;
                dynamic2->item = link->item;
            }
        }
        else{
            if( bigHead == NULL){
                bigHead = malloc(sizeof(ListNode));
                bigHead->item = link->item;
                dynamic3 = bigHead;
            }
            else{
                dynamic3->next = malloc(sizeof(ListNode));
                dynamic3 = dynamic3->next;
                dynamic3->item = link->item;
            }
        }
        link = link->next;
    }
    if(smallHead != NULL && bigHead != NULL && sameHead != NULL){
        dynamic3->next = NULL;
        dynamic1->next = sameHead;
        dynamic2->next = bigHead;
        *head = smallHead;
    }
    else if(smallHead == NULL && bigHead != NULL && sameHead != NULL){
        dynamic3->next = NULL;
        dynamic2->next = bigHead;
        *head = sameHead;
    }
    else if(smallHead != NULL && bigHead == NULL && sameHead != NULL){
        dynamic1 ->next = sameHead;
        dynamic2->next = NULL;
        *head = smallHead;
    }
    else if(smallHead != NULL && bigHead != NULL && sameHead == NULL){
        dynamic3->next = NULL;
        dynamic1->next = bigHead;
        *head = smallHead;
    }
    else if(smallHead != NULL && bigHead == NULL && sameHead == NULL){
        dynamic1->next = NULL;
        *head = smallHead;
    }
    else if(smallHead == NULL && bigHead != NULL && sameHead == NULL){
        dynamic3->next = NULL;
        *head = bigHead;
    }
    else if(smallHead == NULL && bigHead == NULL && sameHead != NULL){
        dynamic2->next = NULL;
        *head = sameHead;
    }
    else{
        return;
    }
}


