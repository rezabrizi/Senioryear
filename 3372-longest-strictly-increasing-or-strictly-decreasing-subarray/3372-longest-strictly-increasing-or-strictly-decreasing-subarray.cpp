class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1; 
        int cnt = 1; 

        int d_cnt = 1; 


        for (int i = 1 ; i < nums.size(); i++){
            if (nums[i] > nums[i-1]) {
                cnt ++;
                ans = max(d_cnt, ans); 
                d_cnt = 1; 
                ans = max(cnt, ans);
            }
            else if (nums[i] < nums[i-1]){
                ans = max(cnt, ans); 
                cnt = 1; 
                d_cnt ++;
                ans = max(d_cnt, ans); 
            }else{
                ans = max (ans, max(cnt, d_cnt)); 
                cnt = d_cnt = 1; 
            }
        }

        return ans;
        
    }
};