#include <iostream>
using namespace std;

class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        for(int i=0;i<n-1;i++) {
            int diff = heights[i+1] - heights[i];
            if(diff > 0) {
                if(pq.size() < ladders) {
                    pq.push(diff);
                } else {
                    if(pq.empty() || pq.top() >= diff) {
                        bricks -= diff;
                    } else {
                        int longest_diff = pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks -= longest_diff;
                    }
                    if(bricks < 0) return i;
                }
            }
        }
        return n - 1;
    }

    
};