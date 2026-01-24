#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    list<int> l;
    list<int> l2;
    list<int> l3;
    for(int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    for(int x : l) 
    {
        if(x%2 == 0)
        {
            l2.push_back(x);
        }
    }
    for(int x : l) 
    {
        if(x%2 != 0)
        {
            l3.push_back(x);
        }
    }
    l2.insert(l2.end(),l3.begin(),l3.end());
    for(int x : l2) cout << x << " ";
    return 0;
}