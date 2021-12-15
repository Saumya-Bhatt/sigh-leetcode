#include <vector>
#include <cmath>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int n1 = nums1.size();
    int n2 = nums2.size();

    // doing this to ensure that we get nums1 as smaller array than nums2
    if (n1 < n2)
        return findMedianSortedArrays(nums2, nums1);

    // since now we know that nums1 is definitely the smaller one, we can perform binary search on it
    int low = 0;
    int high = n2;
    while (low <= high)
    {

        // elements to the left of partition_x and partition_y forms left half of the merged array
        // elements to the right of partition_x and partition_y forms the right half of the merged array
        int partition_x = (low + high) / 2;                // is the target in the binary search (mid)
        int partition_y = (n1 + n2 + 1) / 2 - partition_x; // doing this so that partition_x and partition_y always divide the merged array into equal parts

        // since we are already assuming that the arrays are already sorted,
        // so in the case that the partition occurs such that elements to the left or right are none
        // we still need to ensure that the imaginary array still is sorted
        // so adding -infinity to the left and +infinity to the right

        double left_x = (partition_y == 0) ? INT_MIN : nums1[partition_y - 1];
        double left_y = (partition_x == 0) ? INT_MIN : nums2[partition_x - 1];

        double right_x = (partition_y == n1) ? INT_MAX : nums1[partition_y];
        double right_y = (partition_x == n2) ? INT_MAX : nums2[partition_x];

        // doing this will garuntee that the elements to the left of the merged array are always smaller than the elements to the right
        if (left_x > right_y)
        {
            low = partition_x + 1; // have partitioned too much to the right and thus need to move left
        }
        else if (left_y > right_x)
        {
            high = partition_x - 1; // have partitioned too much to the left and thus need to move right
        }
        else
        {
            // reaching here means that we have partitioned the array correctly
            // just have to take care of whether the merged array is even or odd length
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left_x, left_y) + min(right_x, right_y)) / 2;
            }
            else
            {
                return max(left_x, left_y);
            }
        }
    }
    return -1;
}