#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void print_array(int size, int *input_array, const char *s)
{
    printf("%s:\t", s);
    for(int i=0; i<size; i++){
        printf("%d\t", input_array[i]);
    }
    printf("\n");
}

void rotate_array(int size, int *input_array, int number_of_rotations)
{
    
    int temp =0, j=0;

    for(int i=0; i<number_of_rotations; i++) {
        temp = input_array[0];
        j=0;
        while(j < size-1) {
            input_array[j] = input_array[j+1];
            j++;
        }
        input_array[j] = temp;
    }

    print_array(size, input_array, __func__);
}

int main (void)
{
    int input_array[] = {1, 2, 3, 4, 5};
    int number_of_rotations = 2;

    print_array((sizeof(input_array)/sizeof(int)), input_array, __func__);

    rotate_array(ARRAY_SIZE(input_array), input_array, number_of_rotations);


    return 0;
}