#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    char name[20];
    int age;
    double weight;
    double height;
    struct person *next;
    struct person *prev;
} Person;

int count_rows(FILE *fp);
void print_list(Person *p);
void free_list(Person *p);
Person *delete_item(Person *p, char *name);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("[ERROR] Expected 1 arguments.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open file.\n");
        return 1;
    }

    int num_rows = count_rows(fp);

    Person *first;
    Person *prev = NULL;

    for (int i = 0; i < num_rows; ++i)
    {
        Person *p = (Person *)malloc(sizeof(Person));
        if (i == 0)
        {
            first = p;
        }
        else
        {
            prev->next = p;
        }
        if (4 != fscanf(fp, "%19[^,],%d,%lf,%lf\n", p->name, &p->age, &p->height, &p->weight))
        {
            printf("[ERROR] Number of columns does not match.\n");
            return 1;
        }
        p->prev = prev;
        prev = p;
    }
    prev->next = NULL;

    fclose(fp);

    char name[20];
    printf("Enter a name of person to remove: ");
    scanf("%19s", name);

    first = delete_item(first, name);

    print_list(first);
    free_list(first);

    return 0;
}

int count_rows(FILE *fp)
{
    int count = 1;
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
            ++count;
    }
    fseek(fp, 0L, SEEK_SET);
    return count;
}

void print_list(Person *p)
{
    while (p)
    {
        printf("name: %s, age: %d, weight:%lf, height: %lf, prev: %p, next: %p\n",
               p->name, p->age, p->weight, p->height, p->prev, p->next);
        p = p->next;
    }
}

void free_list(Person *p)
{
    while (p)
    {
        Person *next = p->next;
        free(p);
        p = next;
    }
}

Person *delete_item(Person *p, char *name)
{
    Person *prev = NULL;
    Person *first = p;
    while (p)
    {
        if (strcmp(name, p->name) == 0)
        {
            if (prev)
            {
                prev->next = p->next;
            }
            else
            {
                first = p->next;
            }
            p->next->prev = prev;
            free(p);
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
    return first;
}