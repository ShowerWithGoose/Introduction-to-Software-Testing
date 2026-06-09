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
  for(int i=0;i<=num;i++) // @@ [Loop condition should be i < num, not i <= num, because num is the count of terms, and indices go from 0 to num-1]
  {
      for(int j=0;j<=num1;j++) // @@ [Loop condition should be j < num1, not j <= num1, for the same reason as above]
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und;
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ [Loop condition should be p < sum when checking existing terms; also, when sum==0, this loop runs once with p=0, but final[0] is uninitialized]
        {
            if(temppow==final[p].pow)
            {
                final[p].und+=tempund;
                break;
            }
            else if(p==sum) // @@ [This condition assumes final[sum] is available, but if sum==0 initially, final[0] hasn't been set before this point]
            {
                final[sum].und=tempund;
                final[sum++].pow=temppow;
                break;
            }
        }    
    }
  }
  qsort(final,sum,sizeof(final[0]),cmp);
  for(int i=0;i<=sum;i++) // @@ [Loop should run i < sum, not i <= sum, because valid indices are 0 to sum-1]
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