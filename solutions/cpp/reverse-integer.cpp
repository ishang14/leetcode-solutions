class Solution {
public:
int reverse(int x) {
        int reverseInt = 0;
        while (x != 0) {
            int lastDigit = x % 10;
            if ((reverseInt > INT_MAX / 10) || (reverseInt < INT_MIN / 10 )) {
                return 0;
            }
            reverseInt = reverseInt * 10 + lastDigit;
            x /= 10; 
        }
        return reverseInt;
    }
};