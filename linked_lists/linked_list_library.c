#include "linked_list.h"

struct single_linked_list * create_list(struct single_linked_list * head_ptr, int num_of_nodes)
{
    srand(num_of_nodes);
    struct single_linked_list *new_node;
    for(int i=0;i<num_of_nodes; i++) {
        new_node = (struct single_linked_list *)malloc(sizeof(struct single_linked_list));
        new_node->data = rand() % 20;
        head_ptr->next = new_node;
        head_ptr = new_node;
    }
    head_ptr->next = NULL;
}

void print_list(struct single_linked_list * head_ptr)
{
    while(head_ptr != NULL){
        printf("%d\t", head_ptr->data);
        head_ptr = head_ptr->next;
    }
    printf("\n");
}

void merge_list(struct single_linked_list * to_be_merged, struct single_linked_list * merged_into)
{
    int merge_node;
    struct single_linked_list * head;
    srand(time(NULL));

    merge_node = rand() % LIST2_NUM_OF_NODES;
    printf("Lists will be merged at position: %d\n", merge_node);
    //head = to_be_merged;
    for(int i=1; i < merge_node; i++) {
        to_be_merged = to_be_merged->next;
        merged_into = merged_into->next;
    }
    to_be_merged->next = merged_into;
}

void create_cycle_list(struct single_linked_list * head, int length)
{
    int cycle_position;
    int position = 0;
    struct single_linked_list * last_node;


    //srand(time(NULL));

    cycle_position = 3;
    printf("cycle_position = %d", cycle_position);
    if (head == NULL){
        printf("%s head is NULL", __func__);
    }
    last_node = head;

    while(last_node->next != NULL) {
        last_node = last_node->next;
    }

    while(position < cycle_position){
        head = head->next;
        position ++;
    }

    last_node->next = head;

    printf("Cyclical list created.");
}