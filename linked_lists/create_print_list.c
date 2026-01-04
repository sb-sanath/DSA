#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_OF_NODES 5

struct single_linked_list{
    int data;
    struct single_linked_list *next;
};

struct single_linked_list * create_list(struct single_linked_list * head_ptr, int num_of_nodes)
{
    struct single_linked_list *new_node;
    for(int i=0;i<num_of_nodes; i++) {
        new_node = (struct single_linked_list *)malloc(sizeof(struct single_linked_list));
        new_node->data = i+1;
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

void print_list_in_reverse(struct single_linked_list * head_ptr)
{
    if(head_ptr == NULL)
        return;

    print_list_in_reverse(head_ptr->next);
    printf("%d\t", head_ptr->data);
    
}

struct single_linked_list * reverse_list (struct single_linked_list * head)
{
    struct single_linked_list * behind;
    struct single_linked_list * temp;

    behind = NULL;

    while(head != NULL) {
        temp = head->next;
        head->next = behind;
        behind = head;
        head = temp;
    }
    return behind;
}

int main(void) 
{
    struct single_linked_list * head;

    head = ( struct single_linked_list *)malloc(sizeof(struct single_linked_list));

    create_list(head, NUM_OF_NODES);
    print_list(head);

    printf("Printing in reverse:\n");
    print_list_in_reverse(head);
    printf("\n");

    head = reverse_list(head);
    print_list(head);

}
