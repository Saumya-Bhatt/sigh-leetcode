1. Returning rightmost 1 in binary rep of x
   `x ^ ( x & ( x-1 ) )`

2. Returning rightmost 1 in binary rep of x
   `x & ( -x )`

   x = 10 = 1010
   -x = -10:
   flip 10: 0101
   add 1 : 0101 + 1 = 0110
   x & -x = 1010 & 0110 = 0010

3. Returning number with i'th bit set
   `x | ( 1 << i)`
