#include <stdio.h>
#include <stdlib.h>
struct shi
{
    int und;
    int pow;
};
int cmp(const void *p1, const void *p2);
int main()
{
  struct shi fir[100];
  struct shi sec[100];
  struct shi final[10000];
  int num=0,num1=0;
  char temp;
  while(scanf("%d%d%c",&fir[num].und,&fir[num].pow,&temp)!=EOF&&temp!='\n')
  {
      num++;
  }
  while(scanf("%d%d%c",&sec[num1].und,&sec[num1].pow,&temp)!=EOF&&temp!='\n')
  {
      num1++;
  }
  int sum=0;
  for(int i=0;i<=num;i++) // @@ [Loop condition should be i < num, not i <= num; currently accesses fir[num] which is uninitialized]
  {
      for(int j=0;j<=num1;j++) // @@ [Loop condition should be j < num1, not j <= num1; currently accesses sec[num1] which is uninitialized]
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und; // @@ [Multiplication of coefficients is correct, but due to loop bounds, may use garbage values]
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ [Loop condition should be p < sum; when p == sum, final[p] is uninitialized, and writing to it before incrementing sum is unsafe]
        {
            if(temppow==final[p].pow)
            {
                final[p].und+=tempund;
                break;
            }
            else if(p==sum)
            {
                final[sum].und=tempund;
                final[sum++].pow=temppow;
                break;
            }
        }    
    }
  }
  qsort(final,sum,sizeof(final[0]),cmp);
  for(int i=0;i<=sum;i++) // @@ [Loop condition should be i < sum; i <= sum prints an extra uninitialized term at index sum]
  {
      printf("%d %d ",final[i].und,final[i].pow);
  }
  return 0;
}
int cmp(const void *p1, const void *p2)
{
    struct shi *d1=(struct shi*) p1;
    struct shi *d2=(struct shi*) p2;
    if(d1->pow>d2->pow) return -1;
    else if(d1->pow<d2->pow) return 1;
    else return 0;
}