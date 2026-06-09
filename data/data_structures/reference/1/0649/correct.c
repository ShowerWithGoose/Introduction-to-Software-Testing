#include<stdio.h>
int store[15]={0,1,2,3,4,5,6,7,8,9,10};
int n;
void swap(int *a,int *b)
{
  if(a>b)
  {
    int *tmp=a;
    a=b;
    b=tmp;
  }

  int tmp=*b;
  while(a!=b)
  {
    *b=*(b-1);
    b--;
  }
  *a=tmp;
}
void reswap(int *a,int *b)
{
  if(a>b)
  {
    int *tmp=b;
    b=a;
    a=tmp;
  }

  int tmp=*a;
  while(a!=b)
  {
    *a=*(a+1);
    a++;
  }
  *b=tmp;
}
void array(int begin, int end)
{
  
  if (begin == end)
  {
    int i;
    for (i = 1; i <= end; ++i) 
    {
      printf("%d ", store[i]);
    }
    printf("\n");
  }
  else 
  {
    int i;
    for (i = begin; i <= end; ++i)
    {
      swap(&store[i], &store[begin]);
      array(begin + 1, end);
      reswap(&store[i], &store[begin]);
    }
    
  }
}
int main(void)
{

  scanf("%d",&n);
  array(1,n);
  return 0;
}
