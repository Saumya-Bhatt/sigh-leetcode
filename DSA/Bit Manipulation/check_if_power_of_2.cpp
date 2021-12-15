// if want to find binary representation of 'x'
// do 'x-1'
// Search for the rightmost 1
// flip that place and all the ones after it

// example: 4
// 4 = 100
// 4-1=3 = 011

// If number is a power of 2, it will only have one place with 1. Rest all 0
// so if x is a power of 2,
// x&(x-1) would be 0

using namespace std;

bool isPowerOfTwo(int x)
{

    // x will check for x==0
    return (x && !(x & (x - 1)));
}