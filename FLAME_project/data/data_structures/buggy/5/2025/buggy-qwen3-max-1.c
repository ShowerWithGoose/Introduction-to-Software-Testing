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
  for(int i=0;i<=num;i++) // @@ [Loop condition should be i < num, not i <= num. The variable 'num' counts the number of terms read, so valid indices are 0 to num-1. Using <= causes access to uninitialized memory (fir[num]), leading to undefined behavior and incorrect results.]
  {
      for(int j=0;j<=num1;j++) // @@ [Same issue: should be j < num1. Accessing sec[num1] reads uninitialized data.]
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und; // @@ [Incorrect multiplication logic: coefficient multiplication is correct, but this line uses 'und' as coefficient and 'pow' as exponent, which is consistent with struct definition, BUT the accumulation logic below fails to handle cases where multiple term pairs produce the same exponent correctly due to flawed insertion logic.]
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ [Loop condition should be p < sum. When sum=0 initially, p<=sum allows p=0, but final[0] hasn't been initialized yet. Also, when checking for existing exponent, it only checks up to current 'sum', but the insertion at 'sum' happens inside the loop, causing potential overwrites or missed merges.]
        {
            if(temppow==final[p].pow)
            {
                final[p].und+=tempund;
                break;
            }
            else if(p==sum) // @@ [This condition triggers when no match is found in existing entries, but because the loop goes to p<=sum, when sum=0, p starts at 0 and immediately hits p==sum, inserting at index 0. However, after insertion, sum is incremented, but next time a new term comes, it may incorrectly compare against uninitialized entries beyond current logical size. Also, this approach doesn't scale well and misses merging when multiple same exponents appear non-consecutively before sorting.]
            {
                final[sum].und=tempund;
                final[sum++].pow=temppow;
                break;
            }
        }    
    }
  }
  qsort(final,sum,sizeof(final[0]),cmp);
  for(int i=0;i<=sum;i++) // @@ [Loop condition should be i < sum. This prints sum+1 terms, including an uninitialized or garbage term at index 'sum', which explains the extra "0 0" in the output.]
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