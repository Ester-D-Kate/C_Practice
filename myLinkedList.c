#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
    int dataI;
    node *next;
};

void traversal(node *head){
    while(head!=NULL){
        printf("data: %d\n",head->dataI);
        head = head->next;
    }
}

void insertNewNode(node *newNode, node *prevNode, int data){
    newNode->dataI=data;
    newNode->next=prevNode->next;
    prevNode->next=newNode;
}

void deleteNode(node **currentNode, node *prevnode){
    prevnode->next=(*currentNode)->next;
    free(*currentNode);
    *currentNode=NULL;
}

int main(int argc, int *argv[]){
    node *list0 = malloc(sizeof(node));
    node *list1 = malloc(sizeof(node));
    node *list2 = malloc(sizeof(node));
    node *list3 = malloc(sizeof(node));
    node *list4 = malloc(sizeof(node));
    node *list5 = malloc(sizeof(node));
    
    
    list0->dataI=1;
    list0->next=list1;


    list1->dataI=2;
    list1->next=list2;


    list2->dataI=3;
    list2->next=list3;


    list3->dataI=4;
    list3->next=NULL;

    insertNewNode(list4,list3,5);
    insertNewNode(list5,list1,9);

    deleteNode(&list5,list1);
    
    traversal(list0);
    printf("deleted pointer value %p\n",list5);
}