#include <stdio.h>
void def(int N, int* a, int temp,int* flag)
{
 int i = 0;
 if (temp > N)
 {
  for (i = 1; i <= N; i++)
  {
   if (i == 1)
    printf("%d", a[i]);
   else
    printf(" %d", a[i]);
  }
  printf("\n");
  return;
 }
 for (i = 1; i <= N; i++)
 {
  if (flag[i] == 1)
   continue;
  a[temp] = i;
  flag[i] = 1;
  def(N, a, temp + 1, flag);
  flag[i] = 0;
 }
}
int main()
{
 int N;
 scanf("%d", &N);
 int a[11] = { 0 };
 int flags[11] = { 0 };
 def(N, a, 1, flags);
 return 0;
}

