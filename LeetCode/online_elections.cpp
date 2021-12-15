#include <vector>
#include <map>
#include <unordered_map>
#include <cstring>
using namespace std;

class TopVotedCandidate
{
private:
    // map storing who was leading at time 'i'
    // (time, leader)
    map<int, int> score_board;

public:
    TopVotedCandidate(vector<int> persons, vector<int> times)
    {

        int n = persons.size();
        int curr_lead = -1;

        // counts total votes of candidate 'i'
        // [candidate, count]
        unordered_map<int, int> count;

        for (int i = 0; i < n; i++)
        {
            count[persons[i]]++; // updating the count of candidate persons[i]

            // who is currently leading is changed here
            curr_lead = count[persons[i]] >= count[curr_lead] ? persons[i] : curr_lead;

            // add the happenings here
            score_board[times[i]] = curr_lead;
        }
    }

    int q(int t)
    {
        // if t=13, upper bound will give 15, if range is as [..10,15,..]
        // so need to do -1, to get 10
        return (--score_board.upper_bound(t))->second;
    }
};