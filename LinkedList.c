#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *id;
    struct Node *next;
} node;

typedef struct LinkedList
{
    node *head, *tail;
} linkedList;

linkedList *initializeLinkedList()
{
    linkedList *list = (linkedList *)malloc(sizeof(linkedList));
    list->head = list->tail = NULL;
    return list;
}

node *createNode(char *id)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->id = (char *)malloc((strlen(id) + 1) * sizeof(char));
    strcpy(ptr->id, id);
    ptr->next = NULL;
    return ptr;
}

void insertNode(linkedList *list, char *id)
{
    node *newNode = createNode(id);
    if (!list->head)
        list->head = list->tail = newNode;
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(linkedList *list)
{
    node *ptr = list->head;
    while (ptr != NULL)
    {
        printf("%s ", ptr->id);
        ptr = ptr->next;
    }
    printf("\n");
}

linkedList *getCommonParticipants(linkedList *list1, linkedList *list2)
{
    linkedList *commonParticipants = initializeLinkedList();
    node *ptr1 = list1->head, *ptr2 = list2->head;
    while (ptr1)
    {
        ptr2 = list2->head;
        while (ptr2)
        {
            if (!strcmp(ptr1->id, ptr2->id))
            {
                insertNode(commonParticipants, ptr1->id);
                break;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return commonParticipants;
}

linkedList *getUniqueParticipants(linkedList *list1, linkedList *list2)
{
    linkedList *uniqueParticipants = initializeLinkedList();
    node *ptr1 = list1->head, *ptr2 = list2->head;

    while (ptr1)
    {
        ptr2 = list2->head;
        int flag = 0;
        while (ptr2)
        {
            if (!strcmp(ptr1->id, ptr2->id))
            {
                flag = 1;
                break;
            }
            ptr2 = ptr2->next;
        }
        if (!flag)
            insertNode(uniqueParticipants, ptr1->id);
        ptr1 = ptr1->next;
    }
    while (ptr2)
    {
        ptr1 = list1->head;
        int flag = 0;
        while (ptr1)
        {
            if (!strcmp(ptr1->id, ptr2->id))
            {
                flag = 1;
                break;
            }
            ptr1 = ptr1->next;
        }
        if (!flag)
            insertNode(uniqueParticipants, ptr2->id);
        ptr2 = ptr2->next;
    }
    return uniqueParticipants;
}

int main()
{
    linkedList *foosballEmployees = initializeLinkedList();
    int fb, tt;
    printf("Enter no of employees playing foosball : ");
    scanf("%d", &fb);
    for (int i = 0; i < fb; i++)
    {
        char id[20];
        scanf("%s", id);
        insertNode(foosballEmployees, id);
    }
    printList(foosballEmployees);

    linkedList *tableTennisEmployees = initializeLinkedList();
    printf("Enter no of employees playing table tennis : ");
    scanf("%d", &tt);
    for (int i = 0; i < tt; i++)
    {
        char id[20];
        scanf("%s", id);
        insertNode(tableTennisEmployees, id);
    }
    printList(tableTennisEmployees);

    printf("Common Participants : ");
    linkedList *commonParticipants = initializeLinkedList();
    commonParticipants = getCommonParticipants(foosballEmployees, tableTennisEmployees);
    printList(commonParticipants);

    printf("Unique Participants : ");
    linkedList *uniqueParticipants = initializeLinkedList();
    uniqueParticipants = getUniqueParticipants(foosballEmployees, tableTennisEmployees);
    printList(uniqueParticipants);

    return 0;
}