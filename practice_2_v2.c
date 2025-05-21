#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
struct node{
    char* dataS;
    node* next;
};



void insertAtBeggining(node** head,const char* data){
    node* new = (node*)malloc(sizeof(node));
    if(new == NULL){
        printf("unable to allocate memory to insert the data %s in list",data);
    }else{
        new->dataS = strdup(data);
        new->next = *head;
        *head = new;
    }
}




node* insertAtEnd(node** head, const char* data){
    node* new = (node*)malloc(sizeof(node));
    if(new == NULL){
        return NULL;
    }else{
        new->dataS = strdup(data);
        new->next = NULL;
        if(*head == NULL){
            *head = new;
        } else{
            node* tmp = *head;
            for(int i = 0; tmp->next != NULL; i++){
                tmp = tmp->next;
            }
            tmp->next = new;
            return new;
        }
    }
}



void printList(node* head){
    if(head == NULL){
        printf("list is empty\n");
    }else{
        int tmp = 0;
        for(int i = 0; tmp != 1; i++){
            if(head->next == NULL){
                tmp = 1;
            }
            printf("element at index %d: %s\n",i,head->dataS);
            head = head->next;
        }
    }
}

int searchList(node* head, const char* target){
    if(head == NULL){
        return 0;
    }else{
        int tmp = 0;
        for(int i = 0; tmp != 1; i++){
            if(head->next == NULL){
                tmp = 1;
            }
            if(strcmp(head->dataS,target) == 0){
                return 1;
                break;
            }
            head = head->next;
        }
        return 0;
    }
}



void deleteNode(node** head, const char* target){
    if(*head == NULL){
        printf("target element not found\n");
    }else{
        node* current = *head;
        node* previous = current;
        int temp = 0;
        for(int i = 0; temp != 1; i++){
            if(current->next == NULL){
                temp = 1;
            }
            if(strcmp((*head)->dataS,target) == 0){
                free((*head)->dataS);
                (*head)->dataS = NULL;
                *head = (*head)->next;
                current->next = NULL;
                free(current);
                current = NULL;
                printf("targeted data (%s) \'s node deleted successfully\n",target);
                break;                       
            }
            if(strcmp(current->dataS,target) == 0){
                free(current->dataS);
                current->dataS = NULL;
                previous->next = current->next;
                current->next = NULL;
                free(current);
                current = NULL;
                printf("targeted data (%s) \'s node deleted successfully\n",target);
                break;        
            }
            previous = current; 
            current = current->next; 
        }
    }
}



void freeList(node** head){
    if(*head == NULL){
        printf("list is already free\n");
    }
    int tmp = 0;
    for(int i = 0; tmp != 1; i++){
        if((*head)->next == NULL){
            tmp = 1;
        }
        free((*head)->dataS);
        (*head)->dataS = NULL;
        node* temp = (*head)->next;
        (*head)->next =NULL;
        free(*head);
        *head = temp; 
        printf("element %d of list has been successfully removed\n",i);
    }
    printf("List has been freed succesfully\n");   
}

int main(int argc, int* argv[]){
    node* head = NULL;
    node* list0 = (node*)malloc(sizeof(node));
    head = list0;
    node* list1 = (node*)malloc(sizeof(node));
    node* list2 = (node*)malloc(sizeof(node));
    node* list3 = (node*)malloc(sizeof(node));
    node* list4 = (node*)malloc(sizeof(node));
    node* list5 = (node*)malloc(sizeof(node));

    list0->dataS = strdup("hello 0");
    list1->dataS = strdup("hello 1");
    list2->dataS = strdup("hello 2");
    list3->dataS = strdup("hello 3");
    list4->dataS = strdup("hello 4");
    list5->dataS = strdup("hello 5");

    list0->next = list1;
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = list5;
    list5->next = NULL;
    
    printList(head);
    insertAtBeggining(&head,"hello newBeggining");
    printList(head);
    insertAtEnd(&head,"hello newEnd");
    printList(head);
    int search0 = searchList(head,"hello 2");
    int search1 = searchList(head,"hello");
    if(search0 == 1){
        printf("target founded for search0\n");
    }else{
        printf("target not founded for search0\n");
    }
    if(search1 == 1){
        printf("target founded for search1\n");
    }else{
        printf("target not founded for search1\n");
    }
    deleteNode(&head,"hello 4");
    printList(head);
    deleteNode(&head,"hello newBeggining");
    printList(head);
    deleteNode(&head,"hello newEnd");
    printList(head);
    freeList(&head);
    printList(head);

    return 0;
}