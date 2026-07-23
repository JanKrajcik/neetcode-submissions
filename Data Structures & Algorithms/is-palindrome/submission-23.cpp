class Solution {
public:
    bool isPalindrome(string s) {
        const auto cBeg = s.begin();
        const auto cEnd = s.end(); 
        auto b = cBeg;      // First char of the string
        auto e = cEnd - 1;  // Last char of the string. The end is the termination char.

        while (b < e) {
            // Skip all non-alphanumeric characters.
            while (b < e && !(std::isalnum(*b))) {
                b++;
            }

            while (e > b && !(std::isalnum(*e))) {
                e--;
            }

            // Compare whether characters are the samme (without case sensitivity)
            if (std::tolower(*b) != std::tolower(*e)) {
                return false;
            }

            // Move to the next characters
            b++;
            e--;
        }

        return true; // Is palindrome
    }
};