// name of Problem : Subarray Sums Divisible by K
// leetcode link of problem : https://leetcode.com/problems/subarray-sums-divisible-by-k/
// author : Dhruv Nagar

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ans = 0;
        
        map<int, int> count;
        count[0] = 1;
        
        int sum = 0, rem = 0;
        
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            rem = sum % K;
            if(rem < 0) {
                rem += K;
            } 
            
            if(count.find(rem) != count.end()) {
                ans +=  count[rem];
                count[rem]++;
            }else {
                count[rem]++;
            }
        }
        
        return ans;
    }
};

// Time = O(N)
// Space = O(N)