// do x = x && (x-1) till x is 0
// in each iteration are removing 1 zero

// EXAMPLE n=23
// count = 0

// n = 23 = 10111
// 23-1=22 = 10110
// 23 && 22 = 10110
// let n = 10110 = 22
// count++ = 1

// n = 22 = 10110
// n-1 = 21 = 10101
// 22 && 21 = 10100
// let n = 10100 = 20
// count++ = 2

// n = 20 = 10100
// n-1 = 19 = 10011
// 20 && 19 = 10000
// let n = 10000 = 16
// count++ = 3

// n = 16 = 10000
// n-1 = 15 = 01111
// 16 && 15 = 00000
// let n = 00000 = 0
// count++ = 4   => resultant answer

int count_ones(int n)
{
    int count = 0;
    while (n)
    {
        n = n && (n - 1);
        count++;
    }
    return count;
}