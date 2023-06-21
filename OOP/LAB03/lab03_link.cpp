#include <iostream>
using namespace std;
// *LINKED LIST 

struct Node
{
    int data;
    Node *next;
};
// global variable root is used to record the head of link list
Node *root = NULL;
void InsertNode(int);
bool DeleteNode(int);
void Display();

int main()
{
    size_t i = 0;
    while (1)
    {
        cout << "Please select an option:" << endl
             << "1.Insert a node" << endl
             << "2.Delete a node" << endl
             << "3.Display the list" << endl
             << "4.End" << endl;
        cin >> i;
        int data;
        switch (i)
        {
        case 1:
            cout << "Please enter the number:" << endl;
            cin >> data;
            InsertNode(data);
            break;
        case 2:
            cout << "Please enter the number:" << endl;
            cin >> data;
            if (!DeleteNode(data))
                cout << "Failed to delete node " << data << endl;
            break;
        case 3:
            Display();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }

    return 0;
}

void InsertNode(int data)
{
    // 建立新node
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    // 1.LINK為空
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    // 2.linke!=NULL
    Node *current = root;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // insert newNode
    current->next = newNode;
}

bool DeleteNode(int data)
{
    Node *current = root,
         *previous = NULL;

    // LINK不為空，則找到要砍的NODE
    while ((current != NULL) && (current->data != data))
    {
        previous = current;
        current = current->next;
    }

    // LINK為空，為傳false
    if (current == NULL)
    {
        return (0);
    }
    else if (current == root) // link剛好為root
    {
        root = current->next;
        delete current;
        current = NULL;
        return (1);
    }
    else//OTHER
    {
        previous->next = current->next;
        delete current;
        return (1);
    }
}

void Display(){
    if(root==NULL){
        cout<<"List is empty"<<endl;
    }

    Node *current=root;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<endl;
}