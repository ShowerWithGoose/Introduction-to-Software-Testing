#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct number{
    int xi;
    int zhi;
}shi1[105],shi2[105],ans[10005];
int main(){
    int n,i=1,j=1,k,len1=0,len2=0,len3=0;
    int tmp;
    for(i=0;;i++){
        scanf("%d%d",&shi1[i].xi,&shi1[i].zhi);
        len1=i+1;
        if(getchar()=='\n'){
            break;
        }
    }
    for(i=0;;i++){
        scanf("%d%d",&shi2[i].xi,&shi2[i].zhi);
        len2=i+1;
        if(getchar()=='\n'){
            break;
        }
    }
    for(i=0,j=0;i<len1;i++)
    {
        for(k=0;k<len2;j++,k++)
        {
            ans[j].xi=shi1[i].xi*shi2[k].xi;
            ans[j].zhi=shi1[i].zhi+shi2[k].zhi;
        }
    }
    len3=j;
    for(i=0;i<len3;i++)
    {
        for(j=i+1;j<len3;j++)
        {
            if(ans[i].zhi<ans[j].zhi)
            {
                tmp=ans[i].xi;
                ans[i].xi=ans[j].xi;
                ans[j].xi=tmp;
                tmp=ans[i].zhi;
                ans[i].zhi=ans[j].zhi;
                ans[j].zhi=tmp;
            }
            else if(ans[i].zhi==ans[j].zhi)
            {
                ans[i].xi+=ans[j].xi;
                ans[j].xi=0;
                ans[j].zhi=0;
            }
        }
    }
    for(i=0;ans[i].xi!=0;i++)
    {
        printf("%d %d ",ans[i].xi,ans[i].zhi);
    }
    return 0;
}


