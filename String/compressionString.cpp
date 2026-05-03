#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i=0;
        while(i<n)
        {
            int cnt = 0;
            char curr_char = chars[i];
            while (i<n && curr_char==chars[i])
            {
                i++;
                cnt++;
            }
            chars[index]=curr_char;
            index++;
            if (cnt>1)
            {
                string counter = to_string(cnt);
                {
                    for (auto &it : counter)
                    {
                        chars[index]=it;
                        index++;
                    }
                }

            }

        }
        return index;
    }
};