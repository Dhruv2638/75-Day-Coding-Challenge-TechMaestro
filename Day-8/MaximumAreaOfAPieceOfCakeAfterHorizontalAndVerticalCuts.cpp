// name of Problem : Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// leetcode link of problem : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// author : Dhruv Nagar

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int maxh = max(hc[0], h - hc.back()),
            maxv = max(vc[0], w - vc.back());
        for (int i = 1; i < hc.size(); i++)
            maxh = max(maxh, hc[i] - hc[i-1]);
        for (int i = 1; i < vc.size(); i++)
            maxv = max(maxv, vc[i] - vc[i-1]);
        return (int)((long)maxh * maxv % 1000000007);
    }
};

// Time = O(N * log(N) + M * log(M))
// Space = O(1)