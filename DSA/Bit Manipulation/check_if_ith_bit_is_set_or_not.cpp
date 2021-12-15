// used to see if a number when represented in its
// binary form, the i'th bit is 1 (set) or 0.

// just AND that number with 2^i
// 2^i containes 1 only at the ith position
// if it is set 1&&1 = 1 (true) else false
// 2^i can be done by left shifting 1 to i places as 1<<i

bool check_ith_set(int n, int i)
{
    if (n && (1 << i))
    {
        return true;
    }
    return false;
}