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
  for(int i=0;i<=num;i++) // @@ [Loop condition should be i < num, not i <= num, because num is the count of elements (0-indexed). Accessing fir[num] reads uninitialized memory.]
  {
      for(int j=0;j<=num1;j++) // @@ [Same issue: should be j < num1, not j <= num1.]
      {
          int tempund,temppow;
          tempund=fir[i].und*sec[j].und;
        temppow=fir[i].pow+sec[j].pow;
        for(int p=0;p<=sum;p++) // @@ [Loop condition should be p < sum when checking existing terms; also, when sum==0, this loop runs once with p=0, but final[0] may be uninitialized. Logic fails to handle first insertion correctly.]
        {
            if(temppow==final[p].pow)
            {
                final[p].und+=tempund;
                break;
            }
            else if(p==sum) // @@ [This condition assumes final[sum] is available, but array indexing starts at 0; should assign to final[sum] then increment sum after. However, due to loop condition p<=sum, when sum=0, p goes to 0 and then hits p==sum, which tries to write to final[0], but then does sum++ after assignment — but the logic is flawed because the loop runs one extra time. Also, initial sum=0 means no terms exist, so the inner loop should handle that case separately.]
            {
                final[sum].und=tempund;
                final[sum++].pow=temppow;
                break;
            }
        }    
    }
  }
  qsort(final,sum,sizeof(final[0]),cmp);
  for(int i=0;i<=sum;i++) // @@ [Should be i < sum, not i <= sum. This prints one extra uninitialized element.]
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