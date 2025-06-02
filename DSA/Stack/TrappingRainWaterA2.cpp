//////////////// Trapping Rain Water   p-42 (Hard) ///////////////
            /////// Approach-2 by "TWO POINTER" /////

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0, r=n-1;// Two pointers from both ends
        int lmax =0, rmax=0;// Max heights from left and right

        while(l<r){
            lmax= max(lmax, height[l]);// Update left max
            rmax= max(rmax, height[r]);// Update right max

        // Water trapped depends on smaller max
            if(lmax<rmax){ //left
                ans+= (lmax-height[l]);// Water trapped at l
                l++;
            }else{ //right
                ans+= (rmax-height[r]);// Water trapped at r
                r--;
            }
        }

        return ans;
    }
};

//T.C---> O[n]
//S.C---> O[1] //optimized
