#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
struct d
   {int xishu;
    int zhishu;
   }d1[10000],d2[10000],d[1000000];

int main()
   {int i,j,len1,len2,k,temp,len3;
    for (i=0;;i++)
       {scanf("%d%d",&d1[i].xishu,&d1[i].zhishu);
        len1=i+1;
        if (getchar()=='\n')
            break;
       }
    for (i=0;;i++)
       {scanf("%d%d",&d2[i].xishu,&d2[i].zhishu);
        len2=i+1;
        if (getchar()=='\n')
            break;
       }
    for (i=0,k=0;i<len1;i++)
       {for (j=0;j<len2;j++,k++)
           {d[k].xishu=d1[i].xishu*d2[j].xishu;
            d[k].zhishu=d1[i].zhishu+d2[j].zhishu;
           }
       }
    len3=k;
    for (k=0;k<len3;k++)
       {for (j=k+1;j<len3;j++)
           {if (d[k].zhishu<d[j].zhishu)
               {temp=d[k].xishu;
                d[k].xishu=d[j].xishu;
                d[j].xishu=temp;
                temp=d[k].zhishu;
                d[k].zhishu=d[j].zhishu;
                d[j].zhishu=temp;
               }
            else if (d[k].zhishu==d[j].zhishu)
               {
                d[k].xishu+=d[j].xishu;
                d[j].xishu=0;
                d[j].zhishu=0;
               }
           }
       }
    for (k=0;d[k].xishu!=0;k++)
        printf("%d %d ",d[k].xishu,d[k].zhishu);
   }

