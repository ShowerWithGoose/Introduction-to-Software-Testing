#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int m,n,ch[105][105],mm[105]={0},nn[105]={0},flag,l=1,k,o;
void shendu(int x){
    if(flag==0){
        flag=1;printf("%d",x);
    }
    else
    printf(" %d",x);
    mm[x]=1;
    for(int i=1;i<=m;i++){
        if(ch[x][i]==1&&mm[i]==0){
            shendu(i);
        }
    }
}
void guangdu(int x){
    int j=1;
    nn[1]=x;
    for(j=1,l=1;j<=l;){
        k=nn[j];
        j++;
        if(mm[k]==1)continue;
        if(flag==0){
        flag=1;
        printf("%d",k);}
        else printf(" %d",k);
        mm[k]=1;
        for (int i = 1; i <= m; i++)
        {
            if (ch[k][i] == 1 && mm[i] == 0)
            {
                l++;
                nn[l] = i;
            }
        }
    }
}
int main(){
    int p,q,i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&p,&q);
        ch[p][q]=1;ch[q][p]=1;
    }
    shendu(0);
    printf("\n");
    flag=0;
    memset(mm,0,sizeof(mm));
    guangdu(0);
    printf("\n");
    flag=0;
    memset(mm,0,sizeof(mm));
    scanf("%d",&o);
    mm[o]=1;
    shendu(0);;
    printf("\n");
    flag=0;
    memset(mm,0,sizeof(mm));
    mm[o]=1;
    guangdu(0);
    printf("\n");
}
