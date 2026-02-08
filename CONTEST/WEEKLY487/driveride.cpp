#include<bits/stdc++.h>
using namespace std;
class RideSharingSystem {
    queue<int>qdriver;
    queue<int>qrider;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        qrider.push(riderId);
        return;
    }
    
    void addDriver(int driverId) {
        qdriver.push(driverId);
        return;
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>ans(2,-1);
        if (qrider.size()!=0 && qdriver.size()!=0)
        {int x = qdriver.front();
        int y = qrider.front();
         qdriver.pop();
         qrider.pop();
         ans[0]=x;
         ans[1]=y;
         return ans;
        }
        return ans;
        
    }
    
    void cancelRider(int riderId) {
        queue<int>temp;
        while (!qrider.empty())
            {
                int r = qrider.front();
                qrider.pop();
                if (r==riderId)
                {
                    continue;
                }
                temp.push(r);
            }
        qrider=temp;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */