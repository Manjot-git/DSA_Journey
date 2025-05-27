/////////////// Largest Rectangle in Histogram    P-84  /////////////////

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0); //left smaller nearest
        vector<int> right(n, 0); //right smaller nearest
        stack<int> s;

// Step 1: Fill 'right' with indices of next smaller elements to the right
        //Right Smaller
        for(int i=n-1; i>=0; i--){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            // If stack is empty, no smaller element to right → use n
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        // Clear the stack for next use
        while(!s.empty()) {
            s.pop();
        }

// Step 2: Fill 'left' with indices of previous smaller elements to the left
        //Left Smaller
        for(int i=0; i<n; i++){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            // If stack is empty, no smaller element to left → use -1
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }


// Step 3: Calculate maximum area
        int ans = 0;

        for(int i=0; i<n; i++){
            int width = right[i] - left[i] -1 ;// Width between left and right smaller
            int currArea = heights[i] * width; // Area of rectangle at index i
            ans = max(ans, currArea);// Update max area
        }

        return ans;
    }
}; 
