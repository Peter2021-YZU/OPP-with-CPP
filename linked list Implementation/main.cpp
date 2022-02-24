#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* link;
};

Node* head;

void traverseList( Node* );
void insertList( Node*, int );
Node* reverseList( Node* );
void recursivePrint( Node* );
void recReverse( Node* );
//void printList( Node* );



int main()
{
    //Create linked list
//    Node* head = new Node;
    Node* A = new Node;
    Node* B = new Node;
    Node* C = new Node;
    Node* D = new Node;

    head = A;
    (*A).data = 2;
    A->link = B;

    (*B).data = 4;
    B->link = C;

    (*C).data = 7;
    C->link = D;

    (*D).data = 5;
    D->link = NULL;

    traverseList(head); // 2 4 7 5
    head = reverseList(head);
    cout << "\nThe linked list reversed:" << endl;
    traverseList(head); // 5 7 4 2


    cout << "\nPrint the linked list using the recursive print function:" << endl;
    recursivePrint(head); // 2 4 7 5

    recReverse(head);
    cout << "Head is: " << head->data << endl;
    cout << "\nThe linked list reversed again:" << endl;
    traverseList(head); //2 4 7 5

    return 0;
}


void traverseList( Node* head )
{
    Node* cur = head;
    while( cur->link != NULL ){
        cout << (*cur).data << endl;
        cur = cur->link;
    }
    cout << (*cur).data << endl;
}

void insertList( Node* head, int data )
{
    //
}


// linear reverse of a linked list
Node* reverseList( Node* head)
{
    Node* cur, *prev, *next;
    cur = head;
    prev = NULL;

    while( cur != NULL ){
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

//void printList( Node* head );

// Print linked list using Recursive method
void recursivePrint( Node* head )
{
    Node* cur = head;
    if( cur == NULL ){
        return;
    }
    recursivePrint(cur->link);
    cout << cur->data << endl;
}


// Reverse a function using recursion
void recReverse( Node* p)
{
    if( p->link == NULL ){
        head = p;
        return;
    }
    recReverse(p->link);
    p->link->link = p;
    p->link = NULL;
}
