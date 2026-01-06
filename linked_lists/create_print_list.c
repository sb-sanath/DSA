#include "linked_list.h"

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
    struct single_linked_list * list1_head;
    struct single_linked_list * list2_head;

    list1_head = ( struct single_linked_list *)malloc(sizeof(struct single_linked_list));
    list2_head = ( struct single_linked_list *)malloc(sizeof(struct single_linked_list));

    create_list(list1_head, LIST1_NUM_OF_NODES);
    printf("List 1:\t");
    print_list(list1_head);

    create_list(list2_head, LIST2_NUM_OF_NODES);
    printf("List 2:\t");
    print_list(list2_head);
/*
    printf("Printing in reverse:\n");
    print_list_in_reverse(list1_head);
    printf("\n");
*/
    list1_head = reverse_list(list1_head);
    printf("Reversed list1:\t");
    print_list(list1_head);

    list2_head = reverse_list(list2_head);
    printf("Reversed list2:\t");
    print_list(list2_head);

    merge_list(list1_head, list2_head);
    printf("Merged List 1:\t");
    print_list(list1_head);

    printf("Merged List 2:\t");
    print_list(list2_head);

}
