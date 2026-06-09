#include<stdio.h>
#include<string.h>
int bex[105],bey[105],fix[105],fiy[105];
int main()
{
    int n,max=0,t=0,flagnum,flag,maxnum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&bex[i],&bey[i],&fix[i],&fiy[i]);
    }
    for(int i=1;i<=n;i++){
        t=0,flag=0;
        int j=i;
            for(int k=1;k<=n;k++){
                if(fix[j]==bex[k]&&fiy[j]==bey[k]){
                    if(flag==0){
                        flagnum=j;
                        flag=1;
                    }
                    t++;
                    j=k;
                    k=0;
                }
            }

        if(t>max){
            max=t;
            maxnum=flagnum;
        }
    }
    printf("%d %d %d",max+1,bex[maxnum],bey[maxnum]);

}

