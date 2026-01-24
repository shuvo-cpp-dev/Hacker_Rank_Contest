#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 1; i<= n;i++)
    {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while(t--)
    {
        int l , r;
        cin >> l >> r;
        int cnt = 0;
        for(int i = l; i < r; i++ )
        {
            for(int j = i+1; j < r-i-1; j++)
            {
                if (arr[j] < arr[j+1]) cnt++;     
            }

        }
        cout << cnt << endl;
    }
    return 0;
}