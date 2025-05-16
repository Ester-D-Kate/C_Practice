#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    int *arr;
    int currentSize;
    int capacity;
}dynamicArrResult;

dynamicArrResult createDynamicArray(int initialCapacity){
    int *arr=malloc(initialCapacity*sizeof(int));
    int currentSize = 0;
    dynamicArrResult result = {arr,currentSize,initialCapacity};
    return result;
}



int *addElement(int *arr, int *size, int *capacity, int element){
    int currentSize = *size;
    int previousCapacity = *capacity;
    if(currentSize < previousCapacity){
        *(arr+currentSize)=element;
        currentSize++;
        *size=currentSize;
        return arr;
    }else{
        char choice;
        printf("your array of size %d has run out of memory\n",previousCapacity);
        printf("do you wish to double its memory size to add the element (%d) in array\n",element);
        printf("its previous memory size was %ld bytes and array capacity was %d\n",previousCapacity*sizeof(int),previousCapacity);
        printf("if yes enter y and if no enter any other key: ");
        scanf(" %c",&choice);
        if(choice == 'y' || choice == 'Y'){
            int newCapacity = previousCapacity*2;
            arr = realloc(arr, newCapacity*sizeof(int));
            *(arr+currentSize)=element;
            currentSize++;
            *size=currentSize;
            *capacity=newCapacity;
            currentSize=*size;
            printf("element (%d) is successfully added to array of capacity %d and memory size %ld\n",element,newCapacity,newCapacity*sizeof(int));
            return arr;
        } else{
            return arr;
        }    
    }
}



void freeDynamicArray(int *arr){
    free(arr);
}



int main(int argc, int *argv[]){
    int initialCapacity;
    printf("enter the the intial size of array you want: ");
    scanf("%d",&initialCapacity);
    dynamicArrResult result = createDynamicArray(initialCapacity);
    int *arr = result.arr;
    int capacity = result.capacity;
    int size = result.currentSize;
    char choice = 'y';
    printf("do you want to add an element to this newly created array\n");
    printf("if yes enter y if no enter any alphabet: ");
    scanf(" %c",&choice);
    while(choice == 'y' || choice == 'Y'){
        int element;
        printf("enter the integer value you want to add in the array: ");
        scanf("%d",&element);
        arr = addElement(arr,&size,&capacity,element);
        printf("do you want to add more element to this array\n");
        printf("if yes enter y if no enter any alphabet: ");
        scanf(" %c",&choice);
    }
    if(size>0){
       for(int i = 0; i < size; i++){
           printf("values of array at index %d is %d\n",i,*(arr+i));
        } 
    }else{
        printf("array was empty");
    }
    
    freeDynamicArray(arr);
    printf("memory has been freed successfully\n");
}

