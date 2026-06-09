#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  printf("%d",N); // @@ The program simply prints the input number N instead of generating permutations. For N=2, it outputs "2" instead of the expected permutations "1 2 \n2 1 \n". The logic for generating permutations is completely missing.
    return 0;
}