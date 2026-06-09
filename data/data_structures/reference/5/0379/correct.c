#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

 
struct a
{
	int xishu;
	int zhishu;
}a1[10000],a2[10000],a[1000000];
int main()
{
    int i,j,len1,len2,k,temp,len3;
    for(i=0;;i++)
    {
        scanf("%d%d",&a1[i].xishu,&a1[i].zhishu);
        len1=i+1;
        if(getchar()=='\n')
        	break;
        
       
       
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&a2[i].xishu,&a2[i].zhishu);
        len2=i+1;
        if(getchar()=='\n')
        	break;
        
    }
    for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
            a[k].xishu=a1[i].xishu*a2[j].xishu;
            a[k].zhishu=a1[i].zhishu+a2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(j=k+1;j<len3;j++)
        {
            if(a[k].zhishu<a[j].zhishu)
            {
                temp=a[k].xishu;
                a[k].xishu=a[j].xishu;
                a[j].xishu=temp;
                temp=a[k].zhishu;
                a[k].zhishu=a[j].zhishu;
                a[j].zhishu=temp;
            }
            else if(a[k].zhishu==a[j].zhishu)
            {
                a[k].xishu+=a[j].xishu;
                a[j].xishu=0;
                a[j].zhishu=0;
            }
        }
    }
    for(k=0;a[k].xishu!=0;k++)
    {
        printf("%d %d ",a[k].xishu,a[k].zhishu);
    }
    
}

