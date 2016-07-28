/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

using namespace std;

struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list node;    /* node type defined */

void first_node(node *head, int n)
{
    head->data=n;
    head->next=NULL;
}

void add_node(node *head, int n)
{
    node *new_node= new node;

    new_node->data=n;
    new_node->next=NULL;

    node *occur=head;
    while(occur)
    {
        if(occur->next==NULL)
        {
            occur->next=new_node;
            return;
        }
        occur=occur->next;
    }
}

void insert_front(node **head, int n)
{
    node *new_node= new node;

    new_node->data=n;
    new_node->next=*head;
    *head=new_node;
}

node* search_node(node *head, int n)
{
    node *occur=head;
    while(occur)
    {
        if(occur->data==n)
            return occur;
        occur=occur->next;
    }
    cout<<"Node "<<n<<" not found in the list.\n\n";
}

bool delete_node(node **head, node *ptrdel)
{
    node *occur=*head;
    if(ptrdel==*head)
    {
        *head=occur->next;
        delete ptrdel;
        return true;
    }

    while(occur)
    {
        if(occur->next==ptrdel)
        {
            occur->next=ptrdel->next;
            delete ptrdel;
            return true;
        }
        occur=occur->next;
    }
    return false;
}

void delete_linked_list(node **head)
{
    node *temp_node;
    while(*head)
    {
        temp_node=*head;
        *head=temp_node->next;
        delete temp_node;
    }
    cout<<"Linked List Deleted!\n\n";
}

void display(node *head)
{
    node *lists=head;
    while(lists)
    {
        cout<<lists->data<<" ";
        lists=lists->next;
    }
    cout<<endl<<endl;
}

int main()
{
    int numdel;
    node *ptrdel;
    node *new_head;
    node *head= new node;

    first_node(head,10);
    display(head);

    add_node(head,20);
    display(head);

    add_node(head,30);
    display(head);

    insert_front(&head,5);
    display(head);

    numdel=20;
    ptrdel=search_node(head,numdel);
    if(delete_node(&head,ptrdel))
        cout<<"Node "<<numdel<<" deleted!\n\n";
    display(head);

    delete_linked_list(&head);

    return 0;
}
