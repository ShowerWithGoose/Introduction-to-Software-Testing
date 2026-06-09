#include <stdio.h>
int s[10086][4],tmp[4],n,m,num,x0,y0,z0;
int i,j,k;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %d %d %d %d", &s[i][0], &s[i][1], &s[i][2], &s[i][3]);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i][0]>s[j][0]){
                for(k=0;k<4;k++)
                    tmp[k]=s[i][k];
                for(k=0;k<4;k++)
                    s[i][k]=s[j][k];
                for(k=0;k<4;k++)
                    s[j][k]=tmp[k];
            }
        }
    }
    for(i=0;i<n;i++){
        z0=i;
        num=0;
        for (j=i+1;j<n;j++)
            if (s[z0][2]==s[j][0]){
                if (s[z0][3]==s[j][1]){
                    num++;
                    z0=j;
                }
            }
        if (num>m){
            m=num;
            x0=s[i][0];
            y0=s[i][1];
        }
    }
    printf("%d %d %d",m+1,x0,y0);
    return 0;
}


