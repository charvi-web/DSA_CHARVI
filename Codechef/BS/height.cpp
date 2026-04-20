#include <bits/stdc++.h>
using namespace std;
long long summ(long long n)
{
    return n*(n+1)/2;
}
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    long long N;
	    cin>>N;
	    long long ans = 0;
	    long long low = 0;
	    long long high = N;
	    while(low<=high)
	    {
	        long long mid = low+(high-low)/2;
	        if (summ(mid)<=N)
	        {
	            ans = mid;
	            low=mid+1;
	        }
	        else high=mid-1;
	    }
	    cout<<ans<<endl;
	}

}
