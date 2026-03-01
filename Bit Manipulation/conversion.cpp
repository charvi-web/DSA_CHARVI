#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int n)
{
    string res="";
    while (n)
    {
        if (n%2==1) res+='1';
        else res+='0';
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

string BinaryToDecimal(string s)
{
    int num=0;
    int pow = 1;
    for (int i=s.length()-1;i>=0;i--)
    {
        if (s[i]=='1')
        {
            num=num+pow;
        }
        pow=pow*2; 
    }
    return to_string(num);
}