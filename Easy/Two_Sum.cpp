/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Using hash_table
// Linear time

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hash_table;
        int ref;
        for(int i = 0; i < nums.size(); i++) {
            ref = target - nums[i];

            // If the diff is in the hash_table, then we have found the pair
            if(hash_table.find(ref) != hash_table.end()) {
                ret.push_back(i);
                
                // find the value in the hash_table and get its index
                ret.push_back(hash_table.find(ref)->second);
                break;
            }
            hash_table[nums[i]] = i;
        }

        return ret;
    }
};

// Brute Force Method
// Slowest Method with time complexity of O(N^2)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ret;

//         for(int i = 0; i < nums.size() - 1; i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if(nums[i] + nums[j] == target) {
//                     ret.push_back(i);
//                     ret.push_back(j);
//                     return ret;
//                 }
//             }
//         }

//         return ret;
//     }
// };

int main() {

    Solution s;

    vector<int> vect{2, 7, 11, 15};
    vector<int> sol;
    int target = 9;
    sol = s.twoSum(vect, target);
    cout << sol[0] << sol[1];
    return 0;
}