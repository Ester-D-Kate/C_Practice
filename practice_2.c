#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
 
struct node{
    char* dataS;
    node* next;
};



void insertAtBeginning(node** head, const char* data){
    node* new = malloc(sizeof(node));
    if(new == NULL){
        return;
    } else{
        new->dataS = strdup(data);
        new->next = *head;
        *head = new;
    }
}




node* insertAtEnd(node** head, const char* data){
    if(*head != NULL){
        node* ptr = *head;
        for(int i = 0;ptr->next != NULL; i++){
            ptr = ptr->next;
        }
        node* last = malloc(sizeof(node));
        if(last == NULL){
            return NULL;
        }else{
            last->dataS = strdup(data);
            last->next = NULL;
            ptr->next = last;
            return last;
        }
    } else{
        node* last = malloc(sizeof(node));
        if(last==NULL){
            return NULL;
        }else{
            last->dataS = strdup(data);
            last->next = NULL;
            *head = last;
            return last;
        }
    }
}



void printList(node* head){
    if(head == NULL){
        printf("list is empty");
    }
    else{
        int x = 1;
        for(int i = 0;x != 0; i++){
            if(head->next == NULL){
                x=0;
            }
            printf("list element at index %d is: %s",i,head->dataS);
            head = head->next;
        }
    }
}



int searchList(node* head, const char* target){
    if(head == NULL){
        return 0;
    }else{
        int x = 1;
        for(int i = 0; x != 0; i++){
            if(head->next == NULL){
                x=0;
            }
            if(strcmp(head->dataS,target) == 0){
                return 1;
            }
            head = head->next;
        }
        return 0;
    }
}



void deleteNode(node** head, const char* target){
    if(*head == NULL){
        printf("list is already empty");
    }else{
        char think = 'n';
        int x = 1;
        node* ptr = *head;
        node* previous = ptr;
        for(int i = 0; x != 0; i++){
            if(ptr->next == NULL){
                x = 0;
            }
            if(strcmp(ptr->dataS,target) == 0){
                if(strcmp((*head)->dataS,target) == 0){
                    free((*head)->dataS);
                    (*head)->dataS = NULL;
                    *head = (*head)->next;
                    ptr->next = NULL;
                    ptr = NULL;
                    break;
                }
                free(ptr->dataS);
                ptr->dataS = NULL;
                previous->next = ptr->next;
                ptr->next = NULL;
                free(ptr);
                ptr = NULL;
                printf("deleted node containing string %s successfully",target);
                think = 'y';
                break;
            }
            previous = ptr;
            ptr = ptr->next;
        }
        if(think == 'n'){
            printf("targeted string %s is not present in list ",target);
        }
    }
}



void freeList(node** head){
    node* current = *head;
    while(current != NULL){
        node* next = current->next;
        free(current->dataS);
        current->dataS = NULL;
        current->next = NULL;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main(int argc, int *argv[]){
    node *head = NULL;
    node *list0 = malloc(sizeof(node));
    node *list1 = malloc(sizeof(node));
    node *list2 = malloc(sizeof(node));
    node *list3 = malloc(sizeof(node));
    node *list4 = malloc(sizeof(node));
    node *list5 = malloc(sizeof(node));
    
    head = list0;
    list0->dataS = strdup("hello 0");
    list0->next=list1;
    
    list1->dataS = strdup("hello 1");
    list1->next=list2;

    list2->dataS = strdup("hello 2");
    list2->next=list3;

    list3->dataS = strdup("hello 3");
    list3->next=list4;
    
    list4->dataS = strdup("hello 4");
    list4->next=list5;
    
    list5->dataS = strdup("hello 5");
    list5->next=NULL;
    
    return 0;
}