#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
struct shi{
    int xi;
    int mi;
}S1[50],S2[50],s[2500];
int cmp(const void* p,const void* q)
{
    struct shi*m=(struct shi*)p;
    struct shi*n=(struct shi*)q;
    return n->mi-m->mi;
}
int main()
{
  int i=0,j,a=0,b=0;
  char c;
  do
  {
    scanf("%d %d%c",&S1[a].xi,&S1[a].mi,&c);
    a++;
  } while (c!='\n');
  do
  {
    scanf("%d %d%c",&S2[b].xi,&S2[b].mi,&c);
    b++;
  } while (c!='\n');
  for(i=0;i<a;i++)
  {
      for(j=0;j<b;j++)
      {
          s[i*b+j].xi=S1[i].xi*S2[j].xi;
          s[i*b+j].mi=S1[i].mi+S2[j].mi;
      }}
  qsort(s,a*b,sizeof(struct shi),cmp);
  j=0;
  for(i=0;i<a*b;i++){
      if((s[i].mi==s[i+1].mi)&&(s[i].mi!=0))
      {s[i+1].xi+=s[i].xi;
      s[i].xi=0;}
      else if((s[i].mi==0)&&(s[i].xi!=0))
      {
        s[i+1].xi+=s[i].xi;
        s[i].xi=0;
      }
      if((s[i].mi==0)&&(s[i].xi==0)&&(s[i+1].xi!=0))
      j=s[i+1].xi;
  }
  i=0;
  while((s[i].xi!=0)||(s[i].mi!=0))
  {
      if(s[i].xi!=0) printf("%d %d ",s[i].xi,s[i].mi);
      i++;
  }
  if(j!=0)
  printf("%d %d ",j,s[i].mi);
return 0;
}
