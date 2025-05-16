#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *createDynamicarray(int initialSize){
    int *arr = malloc(sizeof(int) * initialSize);
    return arr;
}

typedef struct {
    int *arr;
    int capacity;
}addElementReturn;
addElementReturn addElement(int *arr,int dataInArr,int capacity,int element){
    if(dataInArr < capacity){
          *(arr+dataInArr)=element;
    }else{
        capacity = capacity*2;
        arr = (int*)realloc(arr,capacity*sizeof(int));
        *(arr+dataInArr)=element;
    }
    addElementReturn result = {arr,capacity};
    return result;
}


void freememory(int *arr){
    free(arr);
}


void main(int argc,char *argv[]) {
    int capacity = 0;
    printf("enter the initial size of array you want to create: ");
    scanf("%d", &capacity);
    int *arr = createDynamicarray(capacity);
    int dataInArr = 0;
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    char choice = 'y';
    printf("do you want to insert value in the array enter y for yes n for no : \n");
    scanf(" %c",&choice);
    while(choice != 'n'){
        int value;
        printf("type the integer value you want to insert in array : \n");
        scanf("%d",&value);
        int element = value;
        addElementReturn result = addElement(arr,dataInArr,capacity,element);
        arr = result.arr;
        capacity = result.capacity;
        dataInArr++;
        printf("do you want to insert value in the array enter y for yes n for no : \n");
        scanf(" %c",&choice);
    }
    for(int i = 0;i<dataInArr;i++){
        printf("value of integer at index %d of array is %d \n",i,*(arr+i));
    }
    freememory(arr);
}