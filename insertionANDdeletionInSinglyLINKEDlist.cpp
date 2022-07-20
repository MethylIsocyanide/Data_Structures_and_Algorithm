#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int element)
    {
        data = element;
        next = NULL;
    }
};

void insertAtBegning(node *&head, int newElement)
{

    node *new_node = new node(newElement);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(node *&head, int newelement)
{

    node *new_node = new node(newelement);

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void dispaly(node *&head)
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertionAtIndex(node *head, int newElement, int index)
{

    node *new_node = new node(newElement);
    node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

node *insertAfteraNode(node *head, node *givenNode, int newElement)
{
    node *new_node = new node(newElement);

    new_node->next = givenNode->next;
    givenNode->next = new_node;

    return head;
}

void deletionAtBegning(node *&head)
{

    node *ptr = head;
    head = head->next;
    delete (ptr);
}

void deletionAtIndex(node *head, int index)
{

    node *p = head;
    node *q = head->next;
    int i = 1;
    while (i != index - 1)
    {
        q = q->next;
        p = p->next;
    }

    p->next = q->next;
    delete (q);
}

void deletionByValues(node *&head, int value)
{

    node *temp = head;

    while (temp->next->data != value || temp->next == NULL)

    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Cannot find the entry" << endl;
    }
    else
    {
        node *node_delete = temp->next;

        temp->next = temp->next->next;

        delete (node_delete);
    }
}

int main()
{

    node *head = NULL;
    insertAtBegning(head, 1);
    insertAtBegning(head, 2);
    insertAtBegning(head, 3);

    // dispaly(head);

    insertAtTail(head, 34);

    // dispaly(head);

    insertionAtIndex(head, 400, 2);
    // dispaly(head);

    insertAfteraNode(head, head->next->next, 67);
    dispaly(head);

    deletionByValues(head, 400);
    dispaly(head);

    return 0;
}