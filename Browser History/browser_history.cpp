#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        string val;
        Node* prev;
        Node* next;
        Node(string val)
        {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
void insert_at_tail(Node* &head, Node* &tail,string val)
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
int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    while(true)
    {
        string s;
        cin >> s;
        if(s == "end")
        {
            break;
        }
        insert_at_tail(head,tail,s);
    }

    Node* find = head;
    int t;
    cin >> t;
   while(t--)
   {
        string s2,s3;
        cin >> s2;
       
        if(s2 == "visit") 
        {   Node* tmp = head;
            cin >> s3;
            bool found = false;
            
            while(tmp != nullptr)
            {   if(tmp->val == s3) 
                {   
                    find = tmp;

                    found = true;
                    break;
                }   
                tmp  = tmp->next;
            }
            if(found == false) cout << "Not Available" << endl;
            else cout << find->val <<endl;
        
        }
        else if(s2 == "prev")
        {
            if(find == nullptr || find->prev == nullptr)
            {
            cout << "Not Available" << endl;
            }
            else
            {
            find = find->prev;
            cout << find->val << endl;
            }
        }
        else if(s2 == "next")
        {
            if(find == nullptr || find->next == nullptr)
            {
            cout << "Not Available" << endl;
            }
            else
            {
            find = find->next;
            cout << find->val << endl;
            }
        }
   }
    return 0;
}