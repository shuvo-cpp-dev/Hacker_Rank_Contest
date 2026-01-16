#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* prev;
        Node* next;
        Node(int val)
        {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
void insert_at_head(Node* &head, Node* &tail,int val)
{
     Node* newNode = new Node(val);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;    
    }
    newNode->next= head;
    head->prev = newNode;
    newNode->prev = nullptr;
    head = newNode;
}
void insert_at_anypos(Node* &head,int val,int idx)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    for(int i=1;i<idx;i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}
void insert_at_tail(Node* &head, Node* &tail,int val)
{   
    Node* newNode = new Node(val);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;    
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
int size(Node* head)
{   int cnt = 0;
    Node* tmp = head;
    while(tmp != nullptr)
    {
       cnt++;
       tmp= tmp->next;
    }
    return cnt;
}
void print_forward(Node* head)
{
    Node* tmp = head;
    cout << "L -> ";
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_backword(Node* tail)
{
    Node* tmp = tail;
    cout << "R -> ";
    while(tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    int q;
    cin >> q;
    while(q--)
    {
        int idx,x;
        cin >> idx;
        cin >> x;
        if(idx == 0) {
            insert_at_head(head,tail,x);
            
            print_forward(head);
            print_backword(tail);

        }
        else if(idx == size(head))
        {
            insert_at_tail(head,tail,x);
           
            print_forward(head);
            print_backword(tail);
        }
        else if(idx > 0 && idx < size(head))
        {
            insert_at_anypos(head,x,idx);
             
            print_forward(head);
            print_backword(tail);
        }
        else cout << "INVALID" << endl;

    }

    
    return 0;
}