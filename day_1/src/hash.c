#include <stdio.h>
#include <string.h>

struct string_node {
    char *str;
    struct string_node *prev;
    struct string_node *next;
};

struct string_list {
    struct string_node head;
};

struct hash {
    struct string_list buckets[64];    
};

size_t hash_func(char *str)
{
    int len = strlen(str);
}

int main()
{
    printf("Hello world\n");
    return 0;
}

