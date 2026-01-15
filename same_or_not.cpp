/*There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. 
You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    stack<int> st;
    queue<int> q;
    
    
    for(int i = 0; i < a ; i++)
    {   int x;
        cin >> x;
        st.push(x);
    }
    for(int i = 0; i < b ; i++)
    {   int y;
        cin >> y;
        q.push(y);
    }
    if(a != b) cout << "NO";
    else  
    {
        for(int i = 0; i<a;i++)
        {
            if(st.top()==q.front())
            {
                st.pop();
                q.pop();

            }
           else 
           {
            cout << "NO";
            break;
           }
        }
         if(st.empty() && q.empty()) cout << "YES";
    }   
    
    return 0;
}