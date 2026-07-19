class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;  // <difference between target and i-th number, index>
        for (int i = 0; i < nums.size(); i++) {
            // Diff between target and i*th number.
            int iDiff = target - nums[i];
            // Try to find the number equal to the iDiff, so it does not have to be fetched twice.
            auto umFound = um.find(iDiff);
            if (umFound != um.end()) {
                return {umFound->second, i};
            } else {
                um[nums[i]] = i;
            }
        }
    }
};