#include <stdio.h>
#include <stdlib.h>

struct Node
{
    void *data;
    struct Node *next;
    int size;
};

struct LinkedList
{
    struct Node *head;
};

struct Node *create_node(void *data, int size)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->size = size;
    return newNode;
}

void insertNode(struct LinkedList *list, void *data, int size)
{
    struct Node *newNode = create_node(data, size);
    if (newNode == NULL)
    {
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
}

void print_list(struct LinkedList *list)
{
    struct Node *current = list->head;

    while (current)
    {

        switch (current->size)
        {
        case 1:
            int *intData = (int *)current->data;
            printf("%d -> ", *intData);
            break;
        case 2:
            char *charData = (char *)current->data;
            printf("%c -> ", *charData);
            break;
        case 3:
            double *doubleData = (double *)current->data;
            printf("%.2lf -> ", *doubleData);
            break;
        default:
            printf("Unknown data type (size: %d)\n", current->size);
            break;
        }
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct LinkedList list;
    list.head = NULL;

    int num = 10;
    insertNode(&list, &num, 1);

    char str = 'H';
    insertNode(&list, &str, 2);

    double pi = 3.14;
    insertNode(&list, &pi, 3);

    printf("Linked list contents:\n");
    print_list(&list);

    return 0;
}