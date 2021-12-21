// 1 2 | 3
// 3 4 | 7
// - -
// 4 6

// target = 7

// [1] += min(7-4,7-3) = 3
// 4 2 | 6
// 3 4 | 7
// - -
// 7 6

// [2] += min(7-6,7-6) = 1
// 4 3 | 7
// 3 4 | 7
// - -
// 7 7

#include <cstring>
#include <algorithm>
using namespace std;

int findMinOperations(int matrix[][2], int n)
{

    // initialize sumRows and sumCols to 0
    int sumRow[n], sumCol[n];
    memset(sumRow, 0, sizeof(sumRow));

    // calculating sumRow, sumCol of the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumRow[i] += matrix[i][j];
            sumCol[j] += matrix[j][i];
        }
    }

    // finding maximum sum
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum = max(maxSum, sumRow[i]);
        maxSum = max(maxSum, sumCol[i]);
    }

    int count = 0;
    for (int i = 0, j = 0; i < n && j < n;)
    {

        // finding the minimum cost required for that particular row/column operation to bring it to target
        int diff = min((maxSum - sumRow[i]), (maxSum - sumCol[j]));

        // adding the difference to the corresponding row/column
        matrix[i][j] += diff;
        sumRow[i] += diff;
        sumCol[j] += diff;

        count += diff;

        if (sumRow[i] == maxSum)
            i++; // have completed objective of that row, move on to next row
        if (sumCol[j] == maxSum)
            j++; // have completed objective of that col, move on to next col
    }

    return count;
}