#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ [The program does not generate permutations as required by the problem. Instead, it only prints the input integer N. This is a logical error where the core functionality of generating and printing all lexicographically ordered permutations of numbers from 1 to N is completely missing.]
    return 0;
}