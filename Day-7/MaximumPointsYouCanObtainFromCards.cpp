// name of Problem : Maximum Points You Can Obtain from Cards
// leetcode link of problem : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// author : Dhruv Nagar

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int left[k+1], right[k+1];
        
        for(int i = 0; i < k; i++) {
            left[i+1] = cardPoints[i] + left[i];
            right[i+1] = cardPoints[n - i - 1] + right[i];
        }
        
        int maxScore = 0;
        for(int i = 0; i <= k; i++) {
            int currScore = left[i] + right[k - i];
            maxScore = max(maxScore, currScore);
        }
        return maxScore;
    }
};

// Time = O(K)
// Space = O(K)


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int maxPoints = sum;
        for(int i = k - 1; i >=0; i--) {
            sum = sum - cardPoints[i];
            sum = sum + cardPoints[n + i - k];
            maxPoints = max(maxPoints, sum);
        }
        return maxPoints;
    }
};

// Time = O(K)
// Space = O(1)