#include <stdio.h>
#include <stdlib.h>

#define ROWS        2
#define COLUMNS     5

int main (void)
{
    int **row;
    int *column;

    row = (int **)malloc(ROWS * sizeof(int *));

    for(int i=0; i<ROWS; i++) {
        *(row + i) = (int *)malloc(COLUMNS * sizeof(int));
    }

}