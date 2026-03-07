#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int>l;
        for (int i=0;i<asteroids.size();i++)
        {
            if (asteroids[i]>0) l.push_back(asteroids[i]);
            // negative
            else
            {
                while (!l.empty() &&  l.back()>0 && l.back()<abs(asteroids[i]))
                {
                    l.pop_back();
                } 
                if (!l.empty() && l.back()==abs(asteroids[i]))
                {
                    l.pop_back();
                }
                else if (l.empty() || l.back()<0)
                {
                    l.push_back(asteroids[i]);
                }

            }
        }
        vector<int>ans(l.begin(),l.end());
        return ans;
    }
};