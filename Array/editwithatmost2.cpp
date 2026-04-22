#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for (int i=0;i<queries.size();i++)
        {
            for (int j=0; j<dictionary.size(); j++)
            {int diffcnt =0;
                for (int t=0;t<queries[0].size();t++)
                {
                    if (queries[i][t]!=dictionary[j][t])
                    {
                        diffcnt++;
                        if (diffcnt>2) break;
                    }
                }
                if (diffcnt<=2) {ans.push_back(queries[i]); break;}
                
            }
            
        }
        return ans;
    }
};