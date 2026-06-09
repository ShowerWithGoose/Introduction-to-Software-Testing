#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ The program should output all permutations of integers from 1 to N, not just the integer N itself. For N=2, the expected output is "1 2 " and "2 1 " on separate lines, but this code only prints the value of N.
    return 0;
}