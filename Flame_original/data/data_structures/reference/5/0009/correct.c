 
#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duo[10000],duo2[10000],duoi[1000000];
int main()
{
    int i,j,len1,len2,k,temp,len3;
    for(i=0;;i++)
    {
        scanf("%d%d",&duo[i].xishu,&duo[i].zhishu);
        len1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&duo2[i].xishu,&duo2[i].zhishu);
        len2=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
            duoi[k].xishu=duo[i].xishu*duo2[j].xishu;
            duoi[k].zhishu=duo[i].zhishu+duo2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(j=k+1;j<len3;j++)
        {
            if(duoi[k].zhishu<duoi[j].zhishu)
            {
                temp=duoi[k].xishu;
                duoi[k].xishu=duoi[j].xishu;
                duoi[j].xishu=temp;
                temp=duoi[k].zhishu;
                duoi[k].zhishu=duoi[j].zhishu;
                duoi[j].zhishu=temp;
            }
            else if(duoi[k].zhishu==duoi[j].zhishu)
            {
                duoi[k].xishu+=duoi[j].xishu;
                duoi[j].xishu=0;
                duoi[j].zhishu=0;
            }
        }
    }
    for(k=0;duoi[k].xishu!=0;k++)
    {
        printf("%d %d ",duoi[k].xishu,duoi[k].zhishu);
    }
}
