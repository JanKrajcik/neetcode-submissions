class Solution {
public:
    bool isPalindrome(string s) {
        const auto cBeg = s.begin();
        const auto cEnd = s.end(); 
        auto b = cBeg;      // First char of the string
        auto e = cEnd - 1;  // Last char of the string. The end is the termination char.


        while (b < e) {
            // Skip all non-alphanumeric characters.
            bool bIsNumber = int(*b) >= 48 && int(*b) <= 57;
            bool bIsCapital = int(*b) >= 65 && int(*b) <= 90;
            bool bIsLowerCase = int(*b) >= 97 && int(*b) <= 122;
            bool bIsEnd = b == cEnd;

            bool eIsNumber = int(*e) >= 48 && int(*e) <= 57;
            bool eIsCapital = int(*e) >= 65 && int(*e) <= 90;
            bool eIsLowerCase = int(*e) >= 97 && int(*e) <= 122;
            bool eIsBeg = e == cEnd;

            while (!(bIsNumber || bIsCapital || bIsLowerCase)) {
                b++;
                bIsNumber = int(*b) >= 48 && int(*b) <= 57;
                bIsCapital = int(*b) >= 65 && int(*b) <= 90;
                bIsLowerCase = int(*b) >= 97 && int(*b) <= 122;
                bIsEnd = b == cEnd;
                if (bIsEnd) {
                    return true;
                }
            }

            while (!(eIsNumber || eIsCapital || eIsLowerCase) || eIsBeg) {
                e--;
                eIsNumber = int(*e) >= 48 && int(*e) <= 57;
                eIsCapital = int(*e) >= 65 && int(*e) <= 90;
                eIsLowerCase = int(*e) >= 97 && int(*e) <= 122;
                eIsBeg = e == cEnd;
                if (eIsBeg) {
                    return true;
                }
            }

            int bAscii = *b;
            int eAscii = *e;

            if ((bIsCapital && eIsLowerCase)) {
                bAscii += 32;
            }

            if (bIsLowerCase && eIsCapital) {
                bAscii -= 32;
            }

            if (bAscii != eAscii) {
                return false;
            }
            b++;
            e--;
        }

        return true; // Is palindrome
    }
};
