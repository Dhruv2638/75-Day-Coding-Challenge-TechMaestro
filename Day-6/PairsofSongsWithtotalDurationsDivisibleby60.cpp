// name of Problem : Pairs of Songs With Total Durations Divisible by 60
// leetcode link of problem : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// author : Dhruv Nagar

// Brute Force
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((time[i] + time[j]) % 60 == 0) count++;
            }
        }
        return count;
    }
};

// Time = O(N^2)
// Space = O(1)


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++) time[i]%=60;
        map<int,int>m;
        int ans=0;
        for(int i=0;i<time.size();i++){
            if(time[i]==0){
                ans+=m[0];
            }
            else if(m.find(60-time[i])!=m.end()){
                ans+=m[60-time[i]];
            }
            m[time[i]]++;
        }
        return ans;
    }
};

// Time = O(N)
// Space = O(N)