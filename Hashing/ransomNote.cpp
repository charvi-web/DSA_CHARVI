#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>m;
        if (ransomNote.length()>magazine.length()) return false;
        for (int i=0;i<magazine.length();i++)
        {
            m[magazine[i]]++;
           
        }
        for (int i=0;i<ransomNote.length();i++)
        {
            m[ransomNote[i]]--;
            if (m[ransomNote[i]]<0) return false;
        }
        return true;
    }
};