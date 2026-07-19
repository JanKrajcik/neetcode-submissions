#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  // Create the hash set directly on stack
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false; // Return false outside of the for loop, as we want to return whether the whole set contains duplicate.
    }
};