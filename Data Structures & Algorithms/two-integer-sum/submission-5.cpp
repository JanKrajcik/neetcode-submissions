class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;   // <value, index>
        seen.reserve(nums.size() / 2);  // Pre-allocate for fewer rehashes
        
        for (int i = 0; i < nums.size(); i++) {
            // Diff between target and i-th number.
            int need = target - nums[i];
            // Try to find the number equal to the iDiff, so it does not have to be fetched twice.
            if (seen.find(need) != seen.end()) {
                return {seen[need], i};
            } else {
                seen[nums[i]] = i;
            }
        }
    }
};