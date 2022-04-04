// name of Problem : Partition Labels
// leetcode link of problem : https://leetcode.com/problems/partition-labels/
// author : Dhruv Nagar

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionLabels;
        
        int lastIndexs[26];
        for(int i = 0; i < s.length(); i++) {
            lastIndexs[s[i] - 'a'] = i;
        }
        int i = 0;
        while(i < s.length()) {
            int end = lastIndexs[s[i] - 'a'];
            int j = i;
            while(j !=   end) {
                end = max(end, lastIndexs[s[j++] - 'a']);   
            }
            partitionLabels.push_back(j - i + 1);
            i = j + 1;
        }
        return partitionLabels;
    }
};

// Time = O(s.length())
// Space = O(1)