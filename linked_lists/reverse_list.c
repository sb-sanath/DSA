#include "linked_list.h"

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