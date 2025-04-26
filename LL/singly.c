#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct Node {
//     struct Node* next;
//     int data;
// };

typedef struct Node
{
    struct Node *next;
    int data;
} node;

// add in linkedlist
node *addInLL(node *head)
{
    int n; // size of the linkedlist
    printf("\nEnter the Length of the LinkedList: ");
    scanf("%d", &n);
    node *temp = head;

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter the value that of new node: ");
        scanf("%d", &val);
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = val;
        new_node->next = NULL;

        if (i == 0)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    return head;
}

// display LL
void displayLL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

// search in LL
bool isValueAvaiable(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return false;
        }
        temp = temp->next;
    }
    return false;
}

// add new node after found a value
node *addnewNode(node *head)
{
    int key;
    printf("\nEnter the element after you add: ");
    scanf("%d", &key);

    node *new_node = (node *)malloc(sizeof(node));
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = NULL;

    node *temp = head;
    bool isAdded = false;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp->next != NULL)
            {
                new_node->next = temp->next;
                temp->next = new_node;
            }
            else
            {
                temp->next = new_node;
            }
            printf("\n node is added!");
            isAdded = true;
            return head;
        }
        temp = temp->next;
    }

    if (!isAdded)
    {
        printf("\n%d element is not found in LinkedList ", key);
    }
    return head;
}

// delete node
node *deleteNode(node *head)
{
    int key;
    printf("\nEnter the element you delete: ");
    scanf("%d", &key);

    node *temp = head;
    node *prev = NULL;
    bool isDeleted = false;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            prev->next = prev->next->next;
            isDeleted = true;
            printf("\n node is deleted!");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!isDeleted)
    {
        printf("\n %d element node not avaiable in LinkedList ", key);
    }
    return head;
}

int main()
{
    // struct Node* head;
    node *head;
    head = addInLL(head);
    displayLL(head);
    head = addnewNode(head);
    displayLL(head);
    head = deleteNode(head);
    displayLL(head);
}