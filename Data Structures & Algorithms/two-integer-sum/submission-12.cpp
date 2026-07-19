class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // <value, index>

        for (int i = 0; i < nums.size(); i++) {
            // Diff between target and i-th number.
            int need = target - nums[i];
            // Check BEFORE inserting - same check but cleaner
            if (seen.count(need)) {
                return {seen[need], i};
            }
            seen[nums[i]] = i;
        }
    }
};