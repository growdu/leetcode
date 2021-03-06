#include <uthash.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LEN 20

struct student {
    int id;  // key
    char name[MAX_NAME_LEN];
    UT_hash_handle hh;
};

struct student* add_student(struct student *head, int id, char *name)
{
    struct student *st = NULL;
    HASH_FIND_INT(head, &id, st);
    if (st == NULL) {
        st = (struct student *)malloc(sizeof(struct student));
        strcpy(st->name, name);
        st->id = id;
        HASH_ADD_INT(head, id, st);
    } else {
        printf("student has exists, id is %d\n", id);
    }
    return head;
}

struct student* find_student(struct student *head, int id)
{
    struct student *st = NULL;
    HASH_FIND_INT(head, &id, st);
    return st;
}

void delete_student(struct student **head, struct student *st)
{
    HASH_DEL(*head, st);
}

void delete_all_student(struct student **head)
{
    struct student *st;
    struct student *temp;
    HASH_ITER(hh, *head, st, temp) {
        HASH_DEL(*head, st);
        free(st);
    }
}

void print_student(struct student *head)
{
    struct student *st = head;
    for (;st != NULL; st = st->hh.next) {
        printf("student id is %d, student name is %s\n", st->id, st->name);
    }
}

int cmp(struct student *st1, struct student *st2)
{
    return st1->id > st2->id;
}

int cmp_by_name(struct student *st1, struct student *st2)
{
    return strcmp(st1->name, st2->name);
}

void uthash_int_test()
{
    struct student *head = NULL;
    printf("=======test uthash int key=======\n");
    head = add_student(head, 3, "tom");
    add_student(head, 88, "linda");
    add_student(head, 388, "marry");
    add_student(head, 188, "lisa");
    add_student(head, 944, "mock");
    add_student(head, 688, "jack");
    printf("add %d student, they are :\n", HASH_COUNT(head));
    print_student(head);
    HASH_SORT(head, cmp);
    printf("student sort by id is :\n");
    print_student(head);
    HASH_SORT(head, cmp_by_name);
    printf("student sort by id is :\n");
    print_student(head);
    printf("id(88)'s student's name is %s\n", (find_student(head, 88))->name);
    printf("=======test uthash int key=======\n");
}

void uthash_string_test()
{
    printf("=======test uthash string key=======\n");
    struct student *head = NULL;
    for (int i = 0; i < 10; i++ ) {
        struct student *st = (struct student *)malloc(sizeof(struct student));
        st->id = i;
        sprintf(st->name, "%d", i+10);
        HASH_ADD_STR(head, name, st);
    }
    print_student(head);
    HASH_SORT(head, cmp);
    printf("student sort by id is :\n");
    print_student(head);
    HASH_SORT(head, cmp_by_name);
    printf("student sort by name is :\n");
    print_student(head);
    struct student *s;
    HASH_FIND_STR(head, "12", s);
    if (s != NULL) {
        printf("student id is %d, name is %s\n", s->id, s->name);
    }
    printf("=======test uthash string key=======\n");
}

void uthash_test()
{
    uthash_int_test();
    uthash_string_test();
}
