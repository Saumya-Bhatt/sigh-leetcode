#include <vector>
using namespace std;
vector<int> breakingRecords(vector<int> scores)
{
    int max_score = 0;
    int max_count = -1;
    int min_score = __INT_MAX__;
    int min_count = -1;
    for (int i : scores)
    {
        if (i > max_score)
        {
            max_score = i;
            max_count++;
        }
        if (i < min_score)
        {
            min_score = i;
            min_count++;
        }
    }
    vector<int> ans = {max_count, min_count};
    return ans;
}