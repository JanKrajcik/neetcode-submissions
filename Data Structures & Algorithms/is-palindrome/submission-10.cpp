class Solution {
public:
    bool isPalindrome(string s) {
        const auto cBeg = s.begin();
        const auto cEnd = s.end(); 
        auto b = cBeg;      // First char of the string
        auto e = cEnd - 1;  // Last char of the string. The end is the termination char.


        while (b < e) {
            int bAscii = *b;
            int eAscii = *e;
            // Skip all non-alphanumeric characters.
            bool bIsNumber = bAscii >= 48 && bAscii <= 57;
            bool bIsCapital = bAscii >= 65 && bAscii <= 90;
            bool bIsLowerCase = bAscii >= 97 && bAscii <= 122;
            bool bIsEnd = b == cEnd;

            bool eIsNumber = eAscii >= 48 && eAscii <= 57;
            bool eIsCapital = eAscii >= 65 && eAscii <= 90;
            bool eIsLowerCase = eAscii >= 97 && eAscii <= 122;
            bool eIsBeg = e == cEnd;

            while (!(bIsNumber || bIsCapital || bIsLowerCase)) {
                b++;
                bAscii = *b;
                bIsNumber = bAscii >= 48 && bAscii <= 57;
                bIsCapital = bAscii >= 65 && bAscii <= 90;
                bIsLowerCase = bAscii >= 97 && bAscii <= 122;
                bIsEnd = b == cEnd;
                if (bIsEnd) {
                    return true;
                }
            }

            while (!(eIsNumber || eIsCapital || eIsLowerCase) || eIsBeg) {
                e--;
                eAscii = *e;
                eIsNumber = eAscii >= 48 && eAscii <= 57;
                eIsCapital = eAscii >= 65 && eAscii <= 90;
                eIsLowerCase = eAscii >= 97 && eAscii <= 122;
                eIsBeg = e == cEnd;
                if (eIsBeg) {
                    return true;
                }
            }

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
