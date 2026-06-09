#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[1000],duoxiangshi2[1000],duoxiangshi[1000000];
int main()
{
    int len1,len2,len3,temp;
    for(int i=1;;i++) // @@ [Error: Input loop starts at index 1 instead of 0, leaving duoxiangshi1[0] uninitialized. This causes incorrect length and usage of garbage values later.]
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu);
        len1=i; // @@ [Error: len1 should be i+1 for correct count, or start i from 0. This off-by-one makes later loops access uninitialized element at index 0.]
        if(getchar()=='\n')
            break;
    }
    for(int i=1;;i++) // @@ [Same error as first input loop: starts at 1 instead of 0.]
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu);
        len2=i; // @@ [Error: len2 should be i+1, causing same off-by-one issue.]
        if(getchar()=='\n')
            break;
    }
    int k=0;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++,k++)
        {
            duoxiangshi[k].xishu=duoxiangshi1[i].xishu*duoxiangshi2[j].xishu;
            duoxiangshi[k].zhishu=duoxiangshi1[i].zhishu+duoxiangshi2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(int j=k+1;j<len3;j++)
        {
            if(duoxiangshi[k].zhishu<duoxiangshi[j].zhishu)
            {                
                temp=duoxiangshi[k].zhishu;
                duoxiangshi[k].zhishu=duoxiangshi[j].zhishu;
                duoxiangshi[j].zhishu=temp;
                
                temp=duoxiangshi[k].xishu;
                duoxiangshi[k].xishu=duoxiangshi[j].xishu;
                duoxiangshi[j].xishu=temp;

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
}