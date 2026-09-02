#include "../main.h"
int get_size_of_string(char *input)
{
    int size = 0;
    while(*input != '\0'){
        size++;
        input++;
    }
    
    return size;
}

void print_string(char *input)
{
    while(*input != '\0'){
        printf("%c", *input);
        input++;
    }
}