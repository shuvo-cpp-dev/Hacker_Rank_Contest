#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for(char x : s)
        {
            st.push(x);
        }
        int cnt = 0, cnt1 = 0;
        if(st.empty()) cout << "NO" << endl;
        else{
            while (!st.empty())
            {
                if(st.top() == '1')
                {   
                    cnt1++;
                    st.pop();
                }
                else{
                    cnt++;
                    st.pop();
                }
               
            }
            if(cnt == cnt1) cout << "YES" << endl;
            else cout << "NO" << endl;
            
        }
    }
    
    return 0;
}