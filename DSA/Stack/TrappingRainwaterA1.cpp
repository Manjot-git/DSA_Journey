///////// Trapping Rainwater P-42 Approach--1 /////////

//Better-Approach  {Prefix Array}

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

        // Build lmax array: stores the max height to the left of or at i
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1], height[i]);
        }
        // Build rmax array: stores the max height to the right of or at i
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], height[i]);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            // Calculate trapped water at each index
            ans += (min(lmax[i] , rmax[i]) - height[i]);
        }

        return ans;
    }
};

//T.C---> O[n]
//S.C---> O[n]

