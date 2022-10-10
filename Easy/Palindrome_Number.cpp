#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// For this solution, we reverse the last half number and compare it with first half
// We can reverse the whole number but it is not needed and it will take more time and space
// This way we can get result in half time
class Solution {
public:
    bool isPalindrome(int x) {

        // If a number is negative then it is not a palindrome
        // If a number is divisible by 10 then it is not a palindrome unless it is 0
        if (x < 0 || (x%10 == 0 && x!=0))
            return false;
        
        int rev = 0;
        
        // until rev of the number is smaller than the original number
        while(rev < x)
        {
            // 1221
            // rev = 1; x = 122
            // rev = 12; x = 12
            rev = rev*10 + x%10;
            x = x/10;
        }
        
        // If x has odd number of digits then we do not need middle digit, thats why why are dividing rev by 10
        // 12321 - rev = 123; x = 12
        return x == rev || x == rev/10;
    }
};

// This solution uses string which does not use constant space and uses functions
// There is a bit faster implementation
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string s;
//         s = to_string(x);
//         string rs = s;
//         reverse(rs.begin(), rs.end());
//         if (rs == s)
//             return true;
//         else
//             return false;
//     }
// };

int main() {
    Solution s;
    cout << s.isPalindrome(121);
    return 0;
}