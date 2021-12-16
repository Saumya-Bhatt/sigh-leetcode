using namespace std;
int mySqrt(int x)
{
    if (x < 2)
        return x;
    int start = 1;
    int end = x / 2;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid <= x / mid && (mid + 1) > x / (mid + 1))
        {
            return mid;
        }
        else if (mid > x / mid)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}