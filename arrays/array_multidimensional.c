#include <stdio.h>
#include <stdlib.h>

#define ROWS        2
#define COLUMNS     5

/*
    Method 1: Allocate Non-contiguous memory.
    Step 1. Allocate memory for row referneces, i.e this memory holds pointers to individal rows.
    Step 2. Aloocate memory for individual rows.
    In this case, memory for each row is allocated indepndently with malloc (thus non-contiguous).
*/

int ** non_contiguous_array (int num_rows, int num_columns)
{
    int **matrix;

    matrix = (int **)malloc(num_rows * sizeof(int *));

    for(int i=0; i<ROWS; i++) {
        *(matrix + i) = (int *)malloc(num_columns * sizeof(int));
    }

    return matrix;
}

/*
    Method 2: Allocate contiguous memory
    Step 1. Allocate memory for row referneces, i.e this memory holds pointers to individal rows.
    Step 2. Allocate memory for the whole matrix i.e, (rows * columns) in one go.
    Step 3. In the for loop, each element of the first array is assigned a portion of the memory allocated by the second malloc
*/

int ** contiguous_with_row_refernce(int num_rows, int num_columns)
{
    int **rows;
    int *matrix;

    rows = (int **)malloc(num_rows * sizeof(int *));                // Step 1

    matrix = (int *)malloc(num_rows * num_columns * sizeof(int));   // Step 2

    for(int i=0; i<num_rows; i++) {                                 // Step 3
        *(rows + i) = matrix + (i * num_columns);
    }

    return rows;

}
int main (void)
{
    int **non_contiguous_matrix;
    int **contiguous_matrix;

    non_contiguous_matrix = non_contiguous_array(ROWS, COLUMNS);

    contiguous_matrix = contiguous_with_row_refernce(ROWS, COLUMNS);

    return 0;
}