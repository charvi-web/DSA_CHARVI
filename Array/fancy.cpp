#include<bits/stdc++.h>
using namespace std;
class Fancy {
public:
long long M = 1e9+7;
vector<long long>A;
long long add= 0;
long long mult=1;
//BINARY EXPONENETIATION FERMIT'S
long long power(long long a,long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b%2) res = (res*a)%M;
            a = (a*a)%M;
            b/=2;
        }
        return res;
    }
    Fancy() {
    }
    
    void append(int val) {
        A.push_back(((val-add)%M+M)*power(mult,M-2)%M);
    }
    
    void addAll(int inc) {
        add=(add+inc)%M;
    }
    
    void multAll(int m) {
        add=(add*m)%M;
                mult=(m*mult)%M;

        
        
    }
    
    int getIndex(int idx) {
        if (A.size()<=idx)  return -1;
        return (A[idx]*mult+add)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */