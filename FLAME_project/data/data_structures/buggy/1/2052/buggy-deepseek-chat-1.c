#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ The program only prints the input number N, but the problem requires printing all permutations of integers from 1 to N in lexicographical order. For N=2, the expected output is "1 2 " and "2 1 " on separate lines, not just "2".
    return 0;
}