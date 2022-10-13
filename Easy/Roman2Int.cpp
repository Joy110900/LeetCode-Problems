#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        // Defining a dic
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int sum = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if(roman[s[i]] < roman[s[i+1]])
            {
                sum -= roman[s[i]];
                continue;
            }
            sum += roman[s[i]];
        }
        return sum;
    }
};

int main() {

    Solution s;

    string i = "XVII";
    cout << s.romanToInt(i);

    return 0;
}