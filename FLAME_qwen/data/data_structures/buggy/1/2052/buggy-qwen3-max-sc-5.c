#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ [The program does not generate permutations as required by the problem. Instead, it only reads and prints the input integer N. This is a logical error: the core functionality of generating and printing all lexicographically ordered permutations of numbers 1 to N is completely missing.]
    return 0;
}