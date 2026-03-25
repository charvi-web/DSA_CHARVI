#include<bits/stdc++.h>
using namespace std;
int minServer(vector<int>A,int X)
{
    int cnt=0;
    sort(A.begin(),A.end(),greater<int>());
    for(int x:A)
    {
        if(x<=X)
        {
            X-=x;
            cnt++;
        }
        if (X==0) return cnt;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>server(n);
    for(int i=0;i<n;i++)
     {
        cin>>server[i];
     }
     int expected_load;
     cin>>expected_load;
     cout<<minServer(server,expected_load);
    }