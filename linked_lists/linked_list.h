#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define LIST1_NUM_OF_NODES 5
#define LIST2_NUM_OF_NODES 4

struct single_linked_list{
    int data;
    struct single_linked_list *next;
};

struct single_linked_list * create_list(struct single_linked_list * head_ptr, int num_of_nodes);
void print_list(struct single_linked_list * head_ptr);
void merge_list(struct single_linked_list * to_be_merged, struct single_linked_list * merged_into);