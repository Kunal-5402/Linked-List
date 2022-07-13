#include <iostream>
using namespace std;

template <class t>
class node
{
public:
    t data;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
    node(t data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <class t>
class doubly_linked_list
{
public:
    node<t> *head;
    node<t> *tail;
    doubly_linked_list()
    {
        head = tail = NULL;
    }
    void insert_at_beginning();
    void insert_at_mid();
    void insert_at_end();
    void delete_from_beginning();
    void delete_from_mid();
    void delete_from_end();
    node<t> *search(t data);
    bool search_for_an_element();
    void display_list();
    void display_list_reverse();
};

template <class t>
void doubly_linked_list<t>::display_list()
{
    node<t> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
template <class t>
void doubly_linked_list<t>::display_list_reverse()
{
    node<t> *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
template <class t>
bool doubly_linked_list<t>::search_for_an_element()
{
    t data;
    cout << "Enter the element to be searched: ";
    cin >> data;
    node<t> *temp = head;
    if (data == head->data || data == tail->data)
        return true;
    while (temp != NULL)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}
template <class t>
node<t> *doubly_linked_list<t>::search(t s_data)
{
    node<t> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == s_data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
template <class t>
void doubly_linked_list<t>::insert_at_beginning()
{
    t data;
    cout << "Enter the data: ";
    cin >> data;
    node<t> *new_node = new node<t>(data);
    if (tail == NULL && head == NULL)
    {
        head = tail = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}
template <class t>
void doubly_linked_list<t>::insert_at_mid()
{
    t data, s_data;
    cout << "Enter after which element to be inserted: ";
    cin >> s_data;
    node<t> *temp = search(s_data);
    if (temp == NULL)
    {
        cout << "Element doesn't exist" << endl;
        return;
    }
    cout << "Enter the data: ";
    cin >> data;
    if (head == NULL && tail == NULL)
        insert_at_beginning();
    if (s_data == tail->data)
        insert_at_end();
    node<t> *new_node = new node(data);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}
template <class t>
void doubly_linked_list<t>::insert_at_end()
{
    t data;
    cout << "Enter the data: ";
    cin >> data;
    node<t> *new_node = new node<t>(data);
    if (tail == NULL && head == NULL)
    {
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}
template <class t>
void doubly_linked_list<t>::delete_from_beginning()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node<t> *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
template <class t>
void doubly_linked_list<t>::delete_from_mid()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    t data;
    cout << "Enter the element to be deleted: ";
    cin >> data;
    if (head->data == data)
        delete_from_beginning();
    if (tail->data == data)
        delete_from_end();
    node<t> *temp = head;
    node<t> *ptr;
    while (temp->next->data != data)
        temp = temp->next;
    ptr = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    delete ptr;
}
template <class t>
void doubly_linked_list<t>::delete_from_end()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node<t> *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    node<t> *ptr;
    ptr = tail;
    tail = temp;
    tail->next = NULL;
    delete ptr;
}

int main()
{
    doubly_linked_list<int> list;
    cout << "0. Exit" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at mid" << endl;
    cout << "3. Insert at end" << endl;
    cout << "4. Delete from beginning" << endl;
    cout << "5. Delete from mid" << endl;
    cout << "6. Delete from end" << endl;
    cout << "7. Search an element" << endl;
    cout << "8. Display list" << endl;
    cout << "9. Display reverse list" << endl;
    do
    {
        int option;
        cout << "Enter the option: ";
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "Exiting..." << endl;
            exit(0);
        case 1:
            list.insert_at_beginning();
            break;
        case 2:
            list.insert_at_mid();
            break;
        case 3:
            list.insert_at_end();
            break;
        case 4:
            list.delete_from_beginning();
            break;
        case 5:
            list.delete_from_mid();
            break;
        case 6:
            list.delete_from_end();
            break;
        case 7:
            if (list.search_for_an_element())
                cout << "The element is present in the list" << endl;
            else
                cout << "The element is not present in the list" << endl;
            break;
        case 8:
            list.display_list();
            break;
        case 9:
            list.display_list_reverse();
            break;
        default:
            cout << "Option don't exist" << endl;
            break;
        }
    } while (true);
    return 0;
}