#include "../main.h"

void reverse_string(char *input)
{
    int size;
    char temp;
    char *backup = input;

    size = get_size_of_string(input);

    for (int i = 0; i < (size / 2); i++) {
        temp = input[i];
        input[i] = input[size - 1 - i];
        input[size - 1 - i] = temp;
    }

    print_string(backup);
}