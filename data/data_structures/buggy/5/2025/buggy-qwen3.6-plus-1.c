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
  while(scanf("%d%d%c",&fir[num].und,&fir[num].pow,&temp)!=EOF&&temp!='\n') // @@ [Error: %c reads the next character including spaces, not just '\n'. This causes incorrect loop termination or parsing. Use a different method to detect line endings.]
  {
      num++;
  }
  while(scanf("%d%d%c",&sec[num1].und,&sec[num1].pow,&temp)!=EOF&&temp!='\n') // @@ [Error: Same issue as above; %c will likely read a space instead of '\n', leading to incorrect input handling and potential infinite loops or misreads.]
  {
      num1++;
  }
  int sum=0;
  for(int i=0;i<=num;i++) // @@ [Error: Loop bound should be i < num. num is the count of terms, so valid indices are 0 to num-1. Using <= causes out-of-bounds access to uninitialized memory and may cause compilation/runtime errors in strict C standards.]
  {
      for(int j=0;j<=num1;j++) // @@ [Error: Loop bound should be j < num1 for the same reason, preventing out-of-bounds access and undefined behavior.]
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und;
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ [Error: The 'final' array is uninitialized. When sum is 0, final[0].pow contains garbage values, causing incorrect equality checks and logic failures.]
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
  for(int i=0;i<=sum;i++) // @@ [Error: Loop bound should be i < sum. sum is the number of valid terms, so indices range from 0 to sum-1. Accessing final[sum] prints uninitialized/garbage data.]
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