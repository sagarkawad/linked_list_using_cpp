#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int value;

    Node(int input)
    {
        value = input;
        next = NULL;
    }
};

void insert_at_start(Node *&head, int input)
{
    Node *new_node = new Node(input);
    new_node->next = head;
    head = new_node;
}

void insert_at_tail(Node *head, int input)
{
    Node *new_node = new Node(input);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
};

void insert_at_position(Node *&head, int input, int position)
{
    Node *temp = head;
    Node *new_node = new Node(input);
    if (position == 0)
    {
        insert_at_start(head, input);
    }
    else
    {
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    };
};

void update_at_position(Node *head, int input, int position)
{
    Node *temp = head;
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    temp->value = input;
};

void delete_at_start(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
};

void delete_at_tail(Node *head)
{
    Node *temp = head;
    Node *temp2 = head;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
};

void delete_at_position(Node *head, int position)
{
    Node *temp = head;
    int i = position;

    if (position == )

    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    };

    temp->next = temp->next->next;
    free(temp->next);
};

void display(Node *head)
{
    Node *temp = head;
    cout << endl;
    while (temp != NULL)
    {
        // cout << temp->value << " " << temp->next << "->";
        cout << temp->value << "->";
        temp = temp->next;
    }
    // cout << temp << endl;
    cout << "NULL";
};

int main()
{
    cout << "hello" << endl;
    cout << "welcome to linked lists" << endl;

    Node *new_node = new Node(10);
    Node *head = new_node;
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_start(head, 5);
    insert_at_start(head, 1);
    insert_at_position(head, 100, 1);
    update_at_position(head, 2, 2);
    // insert_at_position(head, 15, 0);
    // insert_at_position(head, 100, 1);
    // insert_at_position(head, 200, 2);
    display(head);
    delete_at_start(head);
    display(head);
    delete_at_start(head);
    display(head);
    delete_at_tail(head);
    display(head);

    return 0;
}