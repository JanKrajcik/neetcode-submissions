#include <unordered_map>
#include <string>

class Solution {
   public:
    bool isAnagram(string s, string t) {
        // Two hash-maps <char, char-count>
        //   Go through both strings, sort into hash map and compare the count of each char in the
        //   maps.
        // Check length first to save time?

        // Check length first
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> sUM;
        unordered_map<char, int> tUM;

        // Process string s
        for (const char& ch : s) {
            auto ite = sUM.find(ch);
            if (ite != sUM.end()) {
                ite->second++;
            } else {
                sUM.insert({ch, 1});
            }
        }
        // Process string t
        for (const char& ch : t) {
            auto ite = tUM.find(ch);
            if (ite != tUM.end()) {
                ite->second++;
            } else {
                tUM.insert({ch, 1});
            }
        }

        // Compare maps
        return sUM == tUM;
    }
};
