#include<stdio.h>
#include<stdlib.h>

#define INIT_LIST_HEAD(node) \
        {\
            (node)->next = node; \
            (node)->prev = node; \
        }\

#define LIST_EMPTY(list) ((list)->head.next == &(list)->head)

struct char_node
{
    char c;
    struct char_node *next;
    struct char_node *prev;
};

struct char_list
{
    struct char_node head;
};

struct char_list* char_list_init()
{
    struct char_list *list = (struct char_list*)malloc(sizeof(struct char_list));
    list->head.next = &list->head;
    list->head.prev = &list->head;
    return list;
}

struct char_node* char_node_create(char c)
{
    struct char_node *node = (struct char_node *)malloc(sizeof(struct char_node));
    node->c = c;
    INIT_LIST_HEAD(node);
}

void char_list_append(struct char_list* list, char c)
{
    // list->next是第一个元素，list->head是
    struct char_node* node = char_node_create(c);
    /* 头插法
    node->next = list->head.next;
    list->head.next->prev = node;
    node->prev = list->head.next->prev;
    list->head.next = node;*/
    // 尾插法
    node->next = &list->head;
    node->prev = list->head.prev;
    list->head.prev->next = node;
    list->head.prev = node;
}

void char_list_remove(struct char_node *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    INIT_LIST_HEAD(node);
    free(node);
}

void travle_list(struct char_list *list)
{
    int i = 1;
    struct char_node *temp = list->head.next;
    printf("first in first out:\n");
    while (temp != &list->head)
    {
        printf("the %dst is %c\n", i, temp->c);
        i++;
        temp = temp->next;
    }
    printf("first in last out:\n");
    i = 1;
    temp = list->head.prev;
    while (temp != &list->head)
    {
        printf("the %dst is %c\n", i, temp->c);
        i++;
        temp = temp->prev;
    }
}

void add_test()
{
    struct char_list *list = char_list_init();
    char_list_append(list, 'a');
    char_list_append(list, 'b');
    char_list_append(list, 'c');
    char_list_append(list, 'd');
    char_list_append(list, 'e');
    travle_list(list);
}

int main()
{
    printf("this is a test:\n");
    add_test();
    return 0;
}