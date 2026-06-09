#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ [The program does not generate permutations of integers from 1 to N as required. Instead, it only prints the input number N. This fails to meet the problem's output specification which requires N! lines of lexicographically sorted permutations.]
    return 0;
}