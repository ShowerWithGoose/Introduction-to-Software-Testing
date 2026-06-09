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
  for(int i=0;i<=num;i++) // @@ Error: Loop condition should be i<num, not i<=num, because num is the count of terms, and array indices go from 0 to num-1. Using i<=num accesses out-of-bounds memory.
  {
      for(int j=0;j<=num1;j++) // @@ Error: Same issue as above; should be j<num1.
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und;
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ Error: Loop condition should be p<sum, not p<=sum, because sum is the current count of valid entries in final array. Using p<=sum accesses out-of-bounds memory.
        {
            if(temppow==final[p].pow)
            {
                final[p].und+=tempund;
                break;
            }
            else if(p==sum) // @@ Error: This condition is never true when p<=sum because p can equal sum, but the loop condition allows p to reach sum, which is out-of-bounds. Should be p==sum-1 or change loop to p<sum.
            {
                final[sum].und=tempund;
                final[sum++].pow=temppow;
                break;
            }
        }    
    }
  }
  qsort(final,sum,sizeof(final[0]),cmp);
  for(int i=0;i<=sum;i++) // @@ Error: Loop condition should be i<sum, not i<=sum, because sum is the count of valid entries. Using i<=sum prints an extra uninitialized entry.
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