class Solution {
public:
const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        vector<int> pow(n);
        pow[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }
        int i = 0, j = n - 1;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + pow[j - i]) % mod;
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};