#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int sta[105][2],fin[105][2],count[105],mark[105];
int n;
void f(int,int,int);
int main()
{
    int m,i=0,maxNum,ans1,ans2;

    scanf("%d",&n);
    m=n;
    while(m--){
        scanf(" %d%d%d%d",&sta[i][0],&sta[i][1],&fin[i][0],&fin[i][1]);
        i++;
    }
    for(i=0;i<n;i++){
        f(fin[i][0],fin[i][1],i);
    }
    maxNum=count[0];
    ans1=sta[0][0];
    ans2=sta[0][1];
    for(i=1;i<n;i++){
        if(maxNum<count[i]){
            maxNum=count[i];
            ans1=sta[i][0];
            ans2=sta[i][1];
        }
    }

    printf("%d %d %d",maxNum+1,ans1,ans2);

    return 0;
}
void f(int x,int y,int i)
{
    int j,flag;
    flag=0;
    for(j=0;j<n;j++){
            if(x==sta[j][0]&&y==sta[j][1]){
                count[i]++;
                mark[j]=1;
                flag=1;
                break;
            }
    }
    if(0==flag)return;
    return f(fin[j][0],fin[j][1],i);
}

