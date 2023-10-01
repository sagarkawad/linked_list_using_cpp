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

// void delete_at_position(Node *&head, int position)
// {
//     Node *temp = head;
//     int i = position;

//     if (position == 0)
//     {
//         delete_at_start(head);
//     }

//     while (i < position - 1)
//     {
//         temp = temp->next;
//         i++;
//         if (temp->next == NULL)
//         {
//             cout << "false operation" << endl;
//         }
//     };

//     // Node *temp2 = temp->next;
//     // temp->next = temp->next->next;
//     // free(temp2);
// };

void delete_at_position(Node *&head, int position)
{
    Node *temp = head;
    int count = 0;
    int state = 1;

    if (position == 0)
    {
        delete_at_start(head);
    }
    else if (position != 0)
    {

        while (count < position - 1)
        {
            cout << "\ncount = " << count;
            temp = temp->next;
            count++;

            if (temp->next == NULL)
            {
                cout << "\n false operation!" << endl;
                state = 0;
                break;
            }
        }
        cout << "\nand here we are, out of the while loop from the function delete at position " << position;
        if (state == 1)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            temp2->next = NULL;
            free(temp2);
        }
    }
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
    cout << "NULL/" << temp;
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
    delete_at_position(head, 6);
    display(head);

    return 0;
}