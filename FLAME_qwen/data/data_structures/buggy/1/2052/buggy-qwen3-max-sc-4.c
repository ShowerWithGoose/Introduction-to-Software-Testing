#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ [The program does not generate permutations of integers from 1 to N as required. Instead, it only prints the input value N. This is a logical error where the core functionality of generating and printing all lexicographically ordered permutations is completely missing.]
    return 0;
}