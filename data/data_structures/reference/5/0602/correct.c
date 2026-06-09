#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct muiti
{
    int num;
    int power;
}matha[505],mathb[505],ans[505];
int main()
{
    char in='\0';
    int temp1,i,j,k=0,p,q,temp2,flag;
    for(p=1;in!='\n';++p)
    {
        scanf("%d %d%c",&matha[p].num,&matha[p].power,&in);
    }
    in='\0';
    for(q=1;in!='\n';++q)
    {
        scanf("%d %d%c",&mathb[q].num,&mathb[q].power,&in);
    }
    for(i=1;i<p;i++)
    {
        for(j=1;j<q;j++)
        {
            ans[k].num=matha[i].num*mathb[j].num;
            ans[k].power=matha[i].power+mathb[j].power;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        flag=0;
        for(j=0;j<k-i;j++)
        {
            if(ans[j].power<ans[j+1].power&&ans[j].num!=0)
            {
                temp1=ans[j].power;
                ans[j].power=ans[j+1].power;
                ans[j+1].power=temp1;
                temp2=ans[j].num;
                ans[j].num=ans[j+1].num;
                ans[j+1].num=temp2;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }//ÅÅÐò
    for(i=0;i<k;i++)
    {
        if(ans[i].power==ans[i+1].power)
        {
            ans[i+1].num+=ans[i].num;
            ans[i].num=0;
        }
    }
    for(i=0;i<=k;i++)
    {
        if(ans[i].num==0)
        {
            continue;
        }
        printf("%d %d ",ans[i].num,ans[i].power);
    }
    return 0;
}

