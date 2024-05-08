#include <stdlib.h>
#include <stdio.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head, *last;

void create(int val);
void print();
void insertAtFirst(int val);
void insertAfterVal(int val, int val1);
void delAtFirst();
void delAtLast();

int main()
{
    int c, refval, n;
    while (1)
    {
        printf("\n\nLinked List Menu\n");
        printf("1. Create(i.e. insertion at last)\n");
        printf("2. Insert at First\n");
        printf("3. Insert after val\n");
        printf("4. Delete at first.\n");
        printf("5. Delete at Last.\n");
        printf("6. Print Linked List\n");
        printf("0. Exit\n");
        printf("\nEnter Your choice : ");
        scanf("%d", &c);

        switch (c)
        {
        case (1):
            printf("\n\nEnter the value to be inserted : ");
            scanf("%d", &n);
            create(n);
            break;
        case (2):
            printf("\n\nEnter the value to be inserted : ");
            scanf("%d", &n);
            insertAtFirst(n);
            break;
        case (3):
            printf("\n\nEnter the value to be inserted : ");
            scanf("%d", &n);
            printf("\n\nEnter the value after which insertion has to done : ");
            scanf("%d", &refval);
            insertAfterVal(n, refval);
            break;
        case (4):
            delAtFirst();
            break;
        case (5):
            delAtLast();
        case (6):
            print();
            break;
        case (0):
            exit(1);
            break;
        default:
            printf("\nSorry wrong choice.");
        };
    }
}

void create(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->val = val;
    temp->next = NULL;

    if (head == NULL)
        head = last = temp;
    else
    {
        last->next = temp;
        last = temp;
    }
}

void insertAtFirst(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->val = val;
    temp->next = NULL;

    if (head == NULL)
        head = last = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertAfterVal(int val, int val1)
{
    if (head == NULL)
    {
        printf("\nList Empty\n");
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->val = val1;
    temp->next = NULL;

    struct node *t1 = head;

    while (t1->next != NULL)
    {
        if (t1->val == val)
        {
            temp->next = t1->next;
            t1->next = temp;
            return;
        }
        else
        {
            t1 = t1->next;
        }
    }
    last->next = temp;
    last = temp;
}

void delAtFirst()
{
    if (head == NULL)
        printf("List is Empty.");

    if (head == last)
    {
        printf("%d deleted\n", head->val);
        head = last = NULL;
        return;
    }
    else
    {
        printf("%d deleted\n", head->val);
        head = head->next;
    }
}

void delAtLast()
{
    struct node *p1 = head;
    while (p1->next->next != NULL)
    {
        p1 = p1->next;
    }
    p1->next = NULL;
    last = p1;
}

void print()
{
    struct node *ptr;
    ptr = head;

    printf("\nLinked List is as Follows : ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->val);
        ptr = ptr->next;
    }
}
