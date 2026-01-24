#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,get;
    cin >> n >> k;
    if (n == 0) get = 0;
    else get = k/n;
    int baki = n*get;
    int ans =k - baki;
    cout << get << " " << ans;

    return 0;
}