 #include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[10000],duoxiangshi2[10000],duoxiangshi[1000000];
int main()
{
    int i,j,len1,len2,k,temp,len3;
    for(i=0;;i++)
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu);
        len1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu);
        len2=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
            duoxiangshi[k].xishu=duoxiangshi1[i].xishu*duoxiangshi2[j].xishu;
            duoxiangshi[k].zhishu=duoxiangshi1[i].zhishu+duoxiangshi2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(j=k+1;j<len3;j++)
        {
            if(duoxiangshi[k].zhishu<duoxiangshi[j].zhishu)
            {
                temp=duoxiangshi[k].xishu;
                duoxiangshi[k].xishu=duoxiangshi[j].xishu;
                duoxiangshi[j].xishu=temp;
                temp=duoxiangshi[k].zhishu;
                duoxiangshi[k].zhishu=duoxiangshi[j].zhishu;
                duoxiangshi[j].zhishu=temp;
            }
            else if(duoxiangshi[k].zhishu==duoxiangshi[j].zhishu)
            {
                duoxiangshi[k].xishu+=duoxiangshi[j].xishu;
                duoxiangshi[j].xishu=0;
                duoxiangshi[j].zhishu=0;
            }
        }
    }
    for(k=0;duoxiangshi[k].xishu!=0;k++)
    {
        printf("%d %d ",duoxiangshi[k].xishu,duoxiangshi[k].zhishu);
    }
    return 0;
}

