#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int n,m;
int str[105][105];
int tp[105],tm[105];
int fg=0;

void shen(int k){
    if(fg==0)
    {
        printf("%d",k);
        fg=1;
    }
    else
    {
        printf(" %d",k);
    }
    tp[k]=1;
    for(int i=1;i<=n;i++)
    {
        if(str[k][i]==1&&tp[i]==0)
        {
            shen(i);
        }
    }

}
void gu(int k){
    int t;
    tm[1]=k;
    for(int j=1,r=1;j<=r;)
    {
        t=tm[j++];
        if(tp[t]==1)
        {
            continue;
        }
        if(fg==0)
       {
        printf("%d",t);
        fg=1;
       }
       else
       {
        printf(" %d",t);
       }

       tp[t]=1;
       for(int i=1;i<=n;i++)
      {
        if(str[t][i]==1&&tp[i]==0)
        {
            tm[++r]=i;
        }
      }

     }
}


int main()
{
   int x,y;
   int i;
   scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++){
    scanf("%d%d",&x,&y);
    str[x][y]=1;
    str[y][x]=1;
   }
   shen(0);
   printf("\n");
   for(int j=0;j<105;j++){
    tp[j]=0;
    fg=0;
   }
   gu(0);
   printf("\n");
   for(int j=0;j<105;j++){
    tp[j]=0;
    fg=0;
   }
   scanf("%d",&x);
   tp[x]=1;
   shen(0);
   printf("\n");
   for(int j=0;j<105;j++){
    tp[j]=0;
    fg=0;
   }
   tp[x]=1;
   gu(0);
   printf("\n");
   for(int j=0;j<105;j++){
    tp[j]=0;
    fg=0;
   }

}

