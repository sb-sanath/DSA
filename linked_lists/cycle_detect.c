#include "linked_list.h"

void cycle_detect(struct single_linked_list * head)
{
    struct single_linked_list * slow;
    struct single_linked_list * fast;
    int cycle_position = 0;

    slow = head;
    fast = head;

    while ((slow->next != NULL) && (fast->next != NULL) &&(fast->next->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while(head != slow) {
                cycle_position ++;
            }
            printf("Cycle is detected at node : %d", cycle_position);
        }
    }
    printf("List ends with a NULL. No cycle detected");
}