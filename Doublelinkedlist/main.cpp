#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

Node* head;

Node* createNode( int x )
{
    Node* temp = new Node;

    temp-> data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

Node* traverseNode( )
{
    Node* cur = head;
    Node* prev = NULL;
    while( cur != NULL ){
        prev = cur;
        cur = cur->next;
    }
    return prev;
}

void insertNodeHead( int x )
{
    Node* temp = createNode( x );
    if( head == NULL ){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertNodeTail( int x )
{
    Node* temp = createNode( x );
    if( head == NULL ){
        head = temp;
        return;
    }
    Node* last = traverseNode();
    last->next = temp;
    temp->prev = last;
}

void printNode()
{
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reversePrint()
{
    Node* temp = head;
    if( temp == NULL )
        return;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    while( temp != NULL ){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}
int main()
{
    head = NULL;
    insertNodeHead(2); printNode(); reversePrint();
    insertNodeTail(4); printNode(); reversePrint();
    insertNodeTail(6); printNode(); reversePrint();
    return 0;
}
