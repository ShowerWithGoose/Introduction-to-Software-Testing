#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[1000],duoxiangshi2[1000],duoxiangshi[1000000];
int main()
{
    int len1,len2,len3,temp;
    for(int i=1;;i++)
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu); // @@ [Array indexing starts at 1, skipping index 0, which causes uninitialized data access and potential out-of-bounds if input is large; should start at i=0]
        len1=i;
        if(getchar()=='\n')
            break;
    }
    for(int i=1;;i++)
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu); // @@ [Same issue: indexing starts at 1 instead of 0, leading to incorrect storage and possible undefined behavior]
        len2=i;
        if(getchar()=='\n')
            break;
    }
    int k=0;
    for(int i=0;i<len1;i++) // @@ [Loop uses i from 0 to len1-1, but data was stored starting at index 1, so duoxiangshi1[0] is uninitialized and used here]
    {
        for(int j=0;j<len2;j++,k++) // @@ [Same issue: duoxiangshi2[0] is uninitialized but accessed]
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
    for(k=0;duoxiangshi[k].xishu!=0;k++) // @@ [Loop terminates at first zero coefficient, but zero terms may appear before non-zero terms due to incomplete combining of like terms (e.g., if cancellation occurs in middle), causing premature termination and missing output]
    {
        printf("%d %d ",duoxiangshi[k].xishu,duoxiangshi[k].zhishu);
    }
}