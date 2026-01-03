/*
Given an array, reverse it
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void print_array(int size, int *input_array, const char *s){
    printf("%s:\t", s);
    for(int i=0; i<size; i++){
        printf("%d\t", input_array[i]);
    }
    printf("\n");
}

/* 
    Method 1. Create a new array to hold the reversed version of original one.
*/

int* reverse_array_in_new_array (int size, int *input_array){

    static int *new_arr;                        // static because we are returning the same reference to main.
    new_arr = malloc(size * sizeof(int));
    for(int i=size-1; i>=0; i--){
        new_arr[size-i-1] = input_array[i];
    }

    print_array(size, new_arr, __func__);

    return new_arr;
}

/*
    Method 2. Reverse the original inplace
*/
int* reverse_array_inplace (int size, int *input_array){
    int *beginning;
    int *ending;
    int temp;
    beginning = input_array;
    ending = input_array + size-1;
    while (beginning < ending){
     temp = *beginning;
     *beginning = *ending;
     *ending = temp;
     beginning ++;
     ending --;   
    }

    print_array(size, input_array, __func__);

    return input_array;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5};
    int * result;

    print_array((sizeof(a)/sizeof(int)), a, __func__);

    result = reverse_array_in_new_array((sizeof(a)/sizeof(int)), a);

    result = reverse_array_inplace((sizeof(a)/sizeof(int)), a);

    return 0;

}