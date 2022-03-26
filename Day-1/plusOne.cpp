// name of Problem : Plus One
// leetcode link of problem : https://leetcode.com/problems/plus-one/
// author : Dhruv Nagar


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        
        for(int i = n; i>=0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            }else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }
};

// Time = O(N)
// Space = O(1)