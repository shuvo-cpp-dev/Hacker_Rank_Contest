#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* prev;
        Node* Next;
        Node(int val)
        {
            this->val = val;
            this->Next = nullptr;
            this->prev = nullptr;
        }
};
void insert_value(Node* &head, Node* &tail,int val)
{   
    Node* newNode = new Node(val);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;    
    }
    tail->Next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
class MyStack
{
    public:
        Node* head;
        Node* tail;
        void Push(Node* &head, Node* &tail,int val)
        {
           insert_value(head,tail,val);
        }
        void stackPop(Node* &head, Node* &tail)
        {
            if(tail == nullptr) return;

            Node* deleteNode = tail;
            tail = tail->prev;

            if(tail == nullptr)
            head = nullptr;
            else
            tail->Next = nullptr;

            delete deleteNode;
        }
        int stackTop(Node* tail)
        {
            return tail->val;
        }
        int empty(Node*head)
    {
        return head == nullptr;
    }
};
class MyQue
{
    public:
        Node* head;
        Node* tail;
    void Push(Node* &head, Node* &tail,int val)
    {
    insert_value(head,tail,val);
    }
    void quePop(Node* &head, Node* &tail)
    {
        if(head == nullptr) return;

         Node* deleteNode = head;
        head = head->Next;

        if(head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete deleteNode;
    }
    int quefront(Node*head)
    {
        return head->val;
    }
    int empty(Node* head)
    {
        return head == nullptr;
    }
};




int main()
{   
    Node* head = nullptr;
    Node* tail = nullptr;
    MyStack st;
    MyQue q;
    int a,b;
    cin >> a >> b;
    for(int i = 0; i < a ; i++)
    {   int x;
        cin >> x;
        st.Push(head,tail,x);
    }
    for(int i = 0; i < b ; i++)
    {   int y;
        cin >> y;
        q.Push(head,tail,y);
    }
    if(a != b) cout << "NO";
    else  
    {
        for(int i = 0; i<a;i++)
        {
            if(st.stackTop(tail)==q.quefront(head))
            {
                st.stackPop(head,tail);
                q.quePop(head,tail);

            }
           else 
           {
            cout << "NO";
            break;
           }
        }
         if(st.empty(tail) && q.empty(head)) cout << "YES";
    }   
    return 0;
}