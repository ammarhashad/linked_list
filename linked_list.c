#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct slist
{
    int val;
    struct slist *next;
}
node;
node *create(int value);
node *insert(node *head, int value);
bool find(node *head, int value);
void destory(node *head);
void delete_node(node *head, int value);

int main(void)
{
    node *list = create(5);
    list = insert(list, 4);
    bool x = find(list, 5);
    printf("bool is %i\n", x);
    x = find(list, 10);
    printf("bool is %i\n", x);
    list = insert(list, 3);
    list = insert(list, 2);
    list = insert(list, 1);
    for (node *temp = list; temp != NULL ; temp = temp -> next)
    {
        printf("%i\t",temp -> val);
    }
    printf("after delete\n");
    for (node *temp = list; temp != NULL ; temp = temp -> next)
    {
        printf("%i\t",temp -> val);
    }


}
node *create(int value)
{
    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        exit(0);
    }
    list -> val = value;
    list -> next = NULL;
    return list;
}

bool find(node *head, int value)
{
    bool c = false;
    for (node *temp = head; temp != NULL ; temp = temp -> next)
    {
        if (temp -> val == value)
        {
            c = true;
            break;
        }
    }
    return c;
}

node *insert(node *head, int value)
{
    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        exit(0);
    }
    list -> val = value;
    list -> next = head;
    return list;
}

void destory(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    destory(temp -> next);
    free(temp);
}

void delete_node(node *head, int value)
{
    node *temp2 = head;
    for (node *temp = head; temp != NULL ; temp = temp -> next)
    {

        if (temp -> val == value && temp != head)
        {
            temp2 -> next = temp -> next;
            free(temp);
            break;
        }
        else if (temp -> val == value && temp == head)
        {
            printf("da5l gna \n w 3ml set le el head b head next = %i\n w mas7 el temp = %i\n", head -> next -> val, temp-> val);
            head = head -> next;
            free(temp);
            break;
        }
        temp2 = temp;
    }
}