#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    //Add a node at the end of the linked list
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            // tail = tail->next;
            tail = tmp;
        }
    }
    void add_node_beginning(int n){
        node* tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }

    //Traversing through the List
    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data<<" --> " ;
            tmp = tmp->next;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(7);
    a.add_node(2);
    a.add_node_beginning(9);
    a.add_node_beginning(5);
    a.display();
    return 0;
}