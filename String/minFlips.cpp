#include<bits/stdc++.>
using namespace std;
int minFlips(string s)
{
    int n = s.size();
    int flips = 0;
    for (int i=0;i<n;i+=2)
    {
        if (s[i]!=s[i+1]) flips++;
    }
    return flips;
}
int main()
{
    string s;
    cin>>s;
    cout<<minFlips(s)<<endl;
}