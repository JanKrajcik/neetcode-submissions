class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;   // <value, index>
        
        for (int i = 0; i < nums.size(); i++) {
            // Diff between target and i-th number.
            int need = target - nums[i];
            auto it = seen.find(need);

            // Try to find the number equal to the iDiff, so it does not have to be fetched twice.
            if (it != seen.end()) {
                return {it->second, i}; // Use iterator to avoid double lookup
            } else {
                seen[nums[i]] = i;
            }
        }
    }
};