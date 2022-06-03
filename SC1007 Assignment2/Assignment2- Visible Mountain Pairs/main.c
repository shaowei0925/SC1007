#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}



int numMountainPairs(CDblLinkedList CDLL)
{
    int num = CDLL.size;
    if(num == 0 || num==1||CDLL.head == NULL){
        return 0 ;
    }

    if(num == 2){
        return 1 ;
    }
    CDblListNode *head = CDLL.head, *middle = CDLL.head, *cur =NULL;
    int i = 0, flag1 = 0, flag2 = 0, min = 0;

    while(i<num-1)
    {
        i++;
        head = head->next;
        middle = middle->next;
    }
    middle = middle->pre;

    do
    {
        if(head != middle->next && middle->pre != head){
            if(head->item < middle->item){
                min = head->item;
            }
            else{
                min = middle->item;
            }
            cur = head->pre;
            while(head != cur && cur != middle){
                if(cur->item <= min){
                    flag1 = 1;
                }
                else{
                    flag1 = 0;
                    break;
                }
                cur= cur->pre;
            }
            cur = head->next;
            while(cur != head  && middle != cur)
            {
                if(cur->item <= min){
                    flag2 = 1;
                }
                else{
                    flag2 = 0;
                    break;
                }
                cur= cur->next;
            }
           if(flag1 == 1 || flag2 == 1){
                num++;
           }
        }
        if(CDLL.head == middle){
            head = head->pre;
            middle = head;
        }
        middle = middle->pre;
    }
    while(head != CDLL.head);
    return num;
}

